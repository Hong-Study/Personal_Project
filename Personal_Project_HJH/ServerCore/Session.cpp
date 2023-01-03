#include "pch.h"
#include "Session.h"
#include "SocketUtils.h"

Session::Session()
{
	_sock = SocketUtils::CreateSocket();
}

Session::~Session()
{
	SocketUtils::Close(_sock);
}

void Session::Send(BYTE* buffer, int32 len)
{
	SendEvent* sendEvent = new SendEvent();
	sendEvent->owner = shared_from_this();
	sendEvent->buffer.resize(len);

	memcpy(sendEvent->buffer.data(), buffer, len);
	{
		// 중첩 관리 -> 후에 고치기
		lock_guard<SpinLock> guard(spinLock);
		RegisterSend(sendEvent);
	}
}

void Session::DisConnect(const WCHAR* cause)
{
	if (_connected.exchange(false) == false)
		return;

	// TEMP
	wcout << "Disconnect : " << cause << endl;

	OnDisconnected(); // 컨텐츠 코드에서 재정의
	RegisterDisconnect();
}

HANDLE Session::GetHandle()
{
	return reinterpret_cast<HANDLE>(_sock);
}

void Session::Dispatch(IocpEvent* iocpEvent, int32 numOfBytes)
{
	switch (iocpEvent->GetType()) {
	case EventType::Recv:
		ProcessRecv(numOfBytes);
		break;
	case EventType::Disconnect:
		ProcessDisconnect();
		break;
	case EventType::Send:
		ProcessSend(static_cast<SendEvent*>(iocpEvent), numOfBytes);
		break;
	default:
		break;
	}
}

void Session::ProcessSend(SendEvent* sendEvent, int32 numOfBytes)
{
	sendEvent->owner = nullptr;
	delete(sendEvent);

	if (numOfBytes == 0) {
		DisConnect(L"Send 0");
		return;
	}

	OnSend(numOfBytes);
}

void Session::ProcessRecv(int32 numOfBytes)
{
	_recvEvent.owner = nullptr;

	if (numOfBytes == 0) {
		DisConnect(L"Recv 0");
		return;
	}

	OnRecv(_recvBuffer, numOfBytes);

	{
		lock_guard<SpinLock> guard(spinLock);
		RegisterRecv();
	}
}

void Session::ProcessDisconnect()
{
	_disconnectEvent.owner = nullptr;
}

void Session::ProcessConnect()
{
	_connected.store(true);

	// 세션 등록
	GetService()->AddSession(GetSessionRef());

	// 컨텐츠 코드에서 재정의
	OnConnected();

	// 수신 등록
	RegisterRecv();
}

void Session::RegisterSend(SendEvent* sendEvent)
{
	if (IsConnected() == false)
		return;

	WSABUF wsaBuf;
	wsaBuf.buf = (char*)sendEvent->buffer.data();
	wsaBuf.len = (ULONG)sendEvent->buffer.size();

	DWORD numOfBytes = 0;

	if (SOCKET_ERROR == WSASend(_sock, &wsaBuf, 1, &numOfBytes, 0, sendEvent, nullptr)) {
		int32 errorCode = ::WSAGetLastError();
		if (errorCode != WSA_IO_PENDING){
			HandleError("WSASend");
			sendEvent->owner = nullptr; // RELEASE_REF
			delete sendEvent;
		}
	}
}

void Session::RegisterRecv()
{
	if (IsConnected() == false)
		return;
	_recvEvent.Init();
	_recvEvent.owner = shared_from_this();

	WSABUF wsaBuf;
	wsaBuf.buf = reinterpret_cast<char*>(_recvBuffer);
	wsaBuf.len = 1000;

	DWORD numOfBytes = 0;
	DWORD flag = 0;

	if (SOCKET_ERROR == WSARecv(_sock, &wsaBuf, 1, &numOfBytes, &flag, &_recvEvent, nullptr))
	{
		int32 errorCode = ::WSAGetLastError();
		if (errorCode != WSA_IO_PENDING)
		{
			HandleError("WSARecv");
			_recvEvent.owner = nullptr; // RELEASE_REF
		}
	}
}

bool Session::RegisterDisconnect()
{
	_disconnectEvent.Init();
	_disconnectEvent.owner = shared_from_this();

	if (false == SocketUtils::DisconnectEx(_sock, &_disconnectEvent, TF_REUSE_SOCKET, 0)) {
		int32 errorCode = ::WSAGetLastError();
		if (errorCode != WSA_IO_PENDING) {
			_disconnectEvent.owner = nullptr;
			return false;
		}
	}
	return true;
}

bool Session::RegisterConnect()
{
	return false;
}

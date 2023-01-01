#include "pch.h"
#include "SocketUtils.h"

bool SocketUtils::StaticInit()
{
#if _WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR)
	{
		ReportError("Starting Up");
		return false;
	}
#endif
	return true;
}

void SocketUtils::CleanUp()
{
#if _WIN32
	WSACleanup();
#endif
}


void SocketUtils::ReportError(const char* inOperationDesc)
{
#if _WIN32
	LPVOID lpMsgBuf;
	DWORD errorNum = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorNum,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);


	//LOG("Error %s: %d- %s", inOperationDesc, errorNum, lpMsgBuf);
#else
	LOG("Error: %hs", inOperationDesc);
#endif
}

int SocketUtils::GetLastError()
{
#if _WIN32
	return WSAGetLastError();
#else
	return errno;
#endif

}

UDPSocketPtr SocketUtils::CreateUDPSocket(SocketAddressFamily inFamily)
{
	SOCKET s = socket(inFamily, SOCK_DGRAM, IPPROTO_UDP);

	if (s != INVALID_SOCKET)
	{
		return UDPSocketPtr(new UDPSocket(s));
	}
	else
	{
		ReportError("SocketUtils::CreateUDPSocket");
		return nullptr;
	}
}

TCPSocketPtr SocketUtils::CreateTCPSocket(SocketAddressFamily inFamily)
{
	SOCKET s = socket(inFamily, SOCK_STREAM, IPPROTO_TCP);

	if (s != INVALID_SOCKET)
	{
		return TCPSocketPtr(new TCPSocket(s));
	}
	else
	{
		ReportError("SocketUtils::CreateTCPSocket");
		return nullptr;
	}
}

fd_set* SocketUtils::FillSetFromVector(fd_set& outSet, const vector< TCPSocketPtr >* inSockets, int& ioNaxNfds)
{
	if (inSockets)
	{
		FD_ZERO(&outSet);

		for (const TCPSocketPtr& socket : *inSockets)
		{
			FD_SET(socket->mSocket, &outSet);
#if !_WIN32
			ioNaxNfds = std::max(ioNaxNfds, socket->mSocket);
#endif
		}
		return &outSet;
	}
	else
	{
		return nullptr;
	}
}

void SocketUtils::FillVectorFromSet(vector< TCPSocketPtr >* outSockets, const vector< TCPSocketPtr >* inSockets, const fd_set& inSet)
{
	if (inSockets && outSockets)
	{
		outSockets->clear();
		for (const TCPSocketPtr& socket : *inSockets)
		{
			if (FD_ISSET(socket->mSocket, &inSet))
			{
				outSockets->push_back(socket);
			}
		}
	}
}

int SocketUtils::Select(const vector< TCPSocketPtr >* inReadSet,
	vector< TCPSocketPtr >* outReadSet,
	const vector< TCPSocketPtr >* inWriteSet,
	vector< TCPSocketPtr >* outWriteSet,
	const vector< TCPSocketPtr >* inExceptSet,
	vector< TCPSocketPtr >* outExceptSet)
{
	//build up some sets from our vectors
	fd_set read, write, except;

	int nfds = 0;

	fd_set* readPtr = FillSetFromVector(read, inReadSet, nfds);
	fd_set* writePtr = FillSetFromVector(write, inWriteSet, nfds);
	fd_set* exceptPtr = FillSetFromVector(except, inExceptSet, nfds);

	int toRet = select(nfds + 1, readPtr, writePtr, exceptPtr, nullptr);

	if (toRet > 0)
	{
		FillVectorFromSet(outReadSet, inReadSet, read);
		FillVectorFromSet(outWriteSet, inWriteSet, write);
		FillVectorFromSet(outExceptSet, inExceptSet, except);
	}
	return toRet;
}

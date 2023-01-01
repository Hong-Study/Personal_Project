#include "pch.h"
#include "TCPSocket.h"

int TCPSocket::Connect(const SocketAddress& inAddress)
{
	int err = connect(mSocket, (sockaddr*)&inAddress.mSockAddr, inAddress.GetSize());
	if (err < 0)
	{
		SocketUtils::ReportError("TCPSocket::Connect");
		return -SocketUtils::GetLastError();
	}
	return NO_ERROR;
}

int TCPSocket::Listen(int inBackLog)
{
	int err = listen(mSocket, inBackLog);
	if (err < 0)
	{
		SocketUtils::ReportError("TCPSocket::Listen");
		return -SocketUtils::GetLastError();
	}
	return NO_ERROR;
}

TCPSocketPtr TCPSocket::Accept(SocketAddress& inFromAddress)
{
	socklen_t length = inFromAddress.GetSize();
	SOCKET newSocket = accept(mSocket, (sockaddr*)(&inFromAddress.mSockAddr), &length);

	if (newSocket != INVALID_SOCKET)
	{
		return TCPSocketPtr(new TCPSocket(newSocket));
	}
	else
	{
		SocketUtils::ReportError("TCPSocket::Accept");
		return nullptr;
	}
}

int32_t	TCPSocket::Send(const void* inData, size_t inLen)
{
	int bytesSentCount = send(mSocket, static_cast<const char*>(inData), inLen, 0);
	if (bytesSentCount < 0)
	{
		SocketUtils::ReportError("TCPSocket::Send");
		return -SocketUtils::GetLastError();
	}
	return bytesSentCount;
}

int32_t	TCPSocket::Receive(void* inData, size_t inLen)
{
	int bytesReceivedCount = recv(mSocket, static_cast<char*>(inData), inLen, 0);
	if (bytesReceivedCount < 0)
	{
		SocketUtils::ReportError("TCPSocket::Receive");
		return -SocketUtils::GetLastError();
	}
	return bytesReceivedCount;
}

int TCPSocket::Bind(const SocketAddress& inBindAddress)
{
	int error = bind(mSocket, (sockaddr*)&inBindAddress.mSockAddr, inBindAddress.GetSize());
	if (error != 0)
	{
		SocketUtils::ReportError("TCPSocket::Bind");
		return SocketUtils::GetLastError();
	}

	return NO_ERROR;
}

TCPSocket::~TCPSocket()
{
#if _WIN32
	closesocket(mSocket);
#else
	close(mSocket);
#endif
}

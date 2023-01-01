#pragma once

class SocketAddress
{
public:
	SocketAddress(uint32_t inAddress, uint16_t inPort)
	{
		mSockAddr.sin_family = AF_INET;
		mSockAddr.sin_addr.s_addr = htonl(inAddress);
		mSockAddr.sin_port = htons(inPort);
	}
	SocketAddress(string s, uint16_t inport) {	
		mSockAddr.sin_family = AF_INET;
		IN_ADDR addr;
		inet_pton(AF_INET, s.c_str(), &addr);
		mSockAddr.sin_addr = addr;
		mSockAddr.sin_port = htons(inport);
	}
	SocketAddress(const sockaddr& inSockAddr)
	{
		memcpy(&mSockAddr, &inSockAddr, sizeof(sockaddr));
	}

	SocketAddress()
	{
		mSockAddr.sin_family = AF_INET;
		mSockAddr.sin_addr.s_addr = INADDR_ANY;
		mSockAddr.sin_port = 0;
	}

	uint32_t				GetSize()			const { return sizeof(SOCKADDR_IN); }
	string					ToString()			const;

private:
	friend class UDPSocket;
	friend class TCPSocket;

	SOCKADDR_IN mSockAddr;

};
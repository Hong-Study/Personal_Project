#include "pch.h"
#include "SocketAddress.h"

string	SocketAddress::ToString() const
{
#if _WIN32
	char destinationBuffer[128];
	InetNtop(mSockAddr.sin_family, const_cast<in_addr*>(&mSockAddr.sin_addr), destinationBuffer, sizeof(destinationBuffer));
	return StringUtils::Sprintf("%s:%d", destinationBuffer, ntohs(mSockAddr.sin_port));
#else
	//not implement on mac for now...
	return string("not implemented on mac for now");
#endif
}
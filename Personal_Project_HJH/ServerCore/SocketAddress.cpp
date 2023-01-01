#include "pch.h"
#include "SocketAddress.h"

string	SocketAddress::ToString() const
{
#if _WIN32
	const sockaddr_in* s = GetAsSockAddrIn();
	char destinationBuffer[128];
	InetNtop(s->sin_family, const_cast<in_addr*>(&s->sin_addr), destinationBuffer, sizeof(destinationBuffer));
	return StringUtils::Sprintf("%s:%d", destinationBuffer, ntohs(s->sin_port));
#else
	//not implement on mac for now...
	return string("not implemented on mac for now");
#endif
}

SocketAddressPtr SocketAddressFactory::CreateIPv4FromString(const string& inString)
{
	auto pos = inString.find_last_of(':');
	string host, service;
	if (pos != string::npos)
	{
		host = inString.substr(0, pos);
		service = inString.substr(pos + 1);
	}
	else
	{
		host = inString;
		//use default port...
		service = "0";
	}
	addrinfo hint;
	memset(&hint, 0, sizeof(hint));
	hint.ai_family = AF_INET;

	addrinfo* result;
	int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);
	if (error != 0 && result != nullptr)
	{
		SocketUtils::ReportError("SocketAddressFactory::CreateIPv4FromString");
		return nullptr;
	}

	while (!result->ai_addr && result->ai_next)
	{
		result = result->ai_next;
	}

	if (!result->ai_addr)
	{
		return nullptr;
	}

	auto toRet = std::make_shared< SocketAddress >(*result->ai_addr);

	freeaddrinfo(result);

	return toRet;

}

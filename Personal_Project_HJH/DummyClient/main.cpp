#pragma warning(disable:4996);

#include "pch.h"
#include <pch.h>

int main() {
	SocketUtils::StaticInit();
	TCPSocketPtr client = SocketUtils::CreateTCPSocket(INET);
	SocketAddress addr("127.0.0.1", 8000);

	while (true) {
		if (client->Connect(addr) != NO_ERROR) {
			cout << "연결 실패" << endl;
			continue;
		}
		break;
	}
	string s = "HelloWOrld";
	while (true) {
		int len = client->Send(s.c_str(), s.length());
		cout << "Send Len = " << len << endl;
		Sleep(1000);
	}
	SocketUtils::CleanUp();
}
#include "pch.h"

int main() {
	SocketUtils::StaticInit();
	TCPSocketPtr listen = SocketUtils::CreateTCPSocket(INET);
	SocketAddress addr(INADDR_ANY, 8000);
	char ch[100];
	ZeroMemory(ch, 100);
	if (listen->Bind(addr) != NO_ERROR) {
		cout << "Bind Faild" << endl;
	}
	if(listen->Listen() != NO_ERROR)
		cout << "Listen Faild" << endl;

	TCPSocketPtr accpet;
	SocketAddress client_addr;
	while (true) {
		if ((accpet = listen->Accept(client_addr)) == nullptr) {
			cout << "Accept Failed" << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Recv" << endl;
		int strlen = accpet->Receive(ch, 100);
		cout << "RecvLen = " << strlen << " : " << ch << endl;
	}
	SocketUtils::CleanUp();
}
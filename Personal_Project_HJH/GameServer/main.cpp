#include "pch.h"
#include "Protocol.pb.h"

int main() {
	SocketUtils::StaticInit();
	TCPSocketPtr listen = SocketUtils::CreateTCPSocket(INET);
	SocketAddress addr(INADDR_ANY, 8000);
	BYTE ch[100];
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
	int strlen = 0;
	while (true) {
		Protocol::S_TEST pkt;
		cout << "Recv" << endl;
		if ((strlen = accpet->Receive(ch, 100)) <= 0)
			break;
		pkt.ParseFromArray(ch, strlen);
		cout << strlen << " : " << pkt.id() << " " << pkt.hp() << " " << pkt.attack() << endl;
	}

	SocketUtils::CleanUp();
}
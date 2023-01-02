#include "pch.h"
#include <pch.h>
#include "Protocol.pb.h"

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
	Protocol::S_TEST pkt;
	pkt.set_id(1);
	pkt.set_hp(100);
	pkt.set_attack(10);
	
	auto buf = pkt.add_buffs();
	buf->set_buffid(100);
	buf->set_remaintime(1.2f);
	buf->add_victims(400);
	
	const int dataSize = static_cast<int>(pkt.ByteSizeLong());
	BYTE* cast = new BYTE[dataSize];
	pkt.SerializePartialToArray(cast, dataSize);

	while (true) {
		int len = client->Send(cast, dataSize);
		cout << "Send Len = " << len << endl;
		Sleep(1000);
	}
	SocketUtils::CleanUp();
}
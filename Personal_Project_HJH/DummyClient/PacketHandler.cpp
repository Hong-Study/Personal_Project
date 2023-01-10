#include "pch.h"
#include "PacketHandler.h"

void PacketHandler::Packet_Handler(SessionRef ref, BYTE* buffer, int32 len)
{
    Pkt_Header* head = reinterpret_cast<Pkt_Header*>(buffer);
    switch (head->type)
    {
    case Protocol::LOGIN:
        Handler_Login(ref, Handler_Packet<Protocol::S_TEST>(buffer, (int32)head->size));
        break;
    default:
        break;
    } 
}

void PacketHandler::Handler_Login(SessionRef ref, Protocol::S_TEST&& pkt)
{
    cout << pkt.id() << " " << pkt.hp() << " " << pkt.attack() << endl;
}

SendBufferRef PacketHandler::Make_send_buffer(Protocol::S_TEST ptr)
{
    return _Make_send_buffer(ptr, Protocol::LOGIN);
}
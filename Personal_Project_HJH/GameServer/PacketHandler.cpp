#include "pch.h"
#include "PacketHandler.h"

void PacketHandler::HandlerPacket(SessionRef ref, BYTE* buffer, int32 len)
{
    Pkt_Header* head = reinterpret_cast<Pkt_Header*>(buffer);
    switch (head->type)
    {
    case Protocol::MOVE:
        HandlerMove(ref, ParsingPacket<Protocol::S_DATA>(buffer, (int32)head->size));
        break;
    default:
        break;
    } 
}

void PacketHandler::HandlerMove(SessionRef ref, Protocol::S_DATA&& pkt)
{
    cout << pkt.id() << " " << pkt.map_level() << " " << pkt.match_room() << endl;
    ref->Send(MakeSendBuffer(pkt,Protocol::MOVE));
}

SendBufferRef PacketHandler::MakeSendBuffer(Protocol::S_DATA ptr, Protocol::INGAME type)
{
    return _MakeSendBuffer(ptr, type);
}

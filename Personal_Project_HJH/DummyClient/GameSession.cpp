#include "pch.h"
#include "GameSession.h"

void GameSession::OnConnected()
{
    Protocol::S_DATA pkt;
    pkt.set_id(1);
    pkt.set_map_level(2);
    pkt.set_match_room(10);
    SendBufferRef ref = PacketHandler::MakeSendBuffer(pkt, Protocol::MOVE);

    Send(ref);
}

void GameSession::OnDisconnected()
{

}

void GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
    SessionRef game_ref = static_pointer_cast<Session>(shared_from_this());
    PacketHandler::HandlerPacket(game_ref, buffer, len);
}

void GameSession::OnSend(int32 len)
{
    //TODO : 로그 남기기
}

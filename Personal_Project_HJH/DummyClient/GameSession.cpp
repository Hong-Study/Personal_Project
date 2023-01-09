#include "pch.h"
#include "GameSession.h"

void GameSession::OnConnected()
{
    Protocol::S_TEST pkt;
    pkt.set_id(1);
    pkt.set_hp(100);
    pkt.set_attack(10);
    SendBufferRef ref = PacketHandler::Make_send_buffer(pkt);

    Send(ref);
}

void GameSession::OnDisconnected()
{

}

void GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
    SessionRef game_ref = static_pointer_cast<Session>(shared_from_this());
    PacketHandler::Packet_Handler(game_ref, buffer, len);
}

void GameSession::OnSend(int32 len)
{
    
}


void GameSession::HANDLE_URL_MAKING(BYTE* buffer, int32 len)
{
}

void GameSession::HANDLE_URL_MAPPING(BYTE* buffer, int32 len)
{
}

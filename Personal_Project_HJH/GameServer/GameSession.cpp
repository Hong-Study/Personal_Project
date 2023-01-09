#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"

void GameSession::OnConnected()
{
    Gsession_manager.Add(static_pointer_cast<GameSession>(shared_from_this()));
}

void GameSession::OnDisconnected()
{
    Gsession_manager.Remove(static_pointer_cast<GameSession>(shared_from_this()));
}

void GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
    SessionRef game_ref = static_pointer_cast<Session>(shared_from_this());
    PakcetHandler::Packet_Handler(game_ref, buffer, len);
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

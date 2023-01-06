#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "PacketSession.h"

void GameSession::OnConnected()
{
    Gsession_manager.Add(static_pointer_cast<GameSession>(shared_from_this()));
}

void GameSession::OnDisconnected()
{
    Gsession_manager.Add(static_pointer_cast<GameSession>(shared_from_this()));
}

int32 GameSession::OnRecv(BYTE* buffer, int32 len)
{
    Pkt_Header* head = reinterpret_cast<Pkt_Header*>(buffer);
    Protocol::S_TEST pkt;
    cout << head->size << " " << sizeof(head) << endl;
    pkt.ParseFromArray(&head[1], head->size);

    cout << pkt.id() << " " << pkt.hp() << " " << pkt.attack() << endl;

    SendBufferRef send_buffer = PacketSession::Make_send_buffer(pkt);

    //Send(send_buffer);

    return len;
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

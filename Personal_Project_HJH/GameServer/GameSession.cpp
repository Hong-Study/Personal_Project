#include "pch.h"
#include "GameSession.h"

void GameSession::OnConnected()
{
}

int32 GameSession::OnRecv(BYTE* buffer, int32 len)
{
    Protocol::S_TEST pkt;
    pkt.ParseFromArray(buffer, len);

    cout << pkt.id() << " " << pkt.hp() << " " << pkt.attack() << endl;

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

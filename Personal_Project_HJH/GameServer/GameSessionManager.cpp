#include "pch.h"
#include "GameSessionManager.h"
#include "GameSession.h"

GameSessionManager Gsession_manager;

void GameSessionManager::Add(GameSessionRef session)
{
	lock_guard<SpinLock> guard(lock);
	sessions.insert(session);
}

void GameSessionManager::Remove(GameSessionRef session)
{
	lock_guard<SpinLock> guard(lock);
	sessions.erase(session);
}

void GameSessionManager::Broadcast(SendBufferRef send_buffer)
{
	lock_guard<SpinLock> guard(lock);
	for (GameSessionRef session : sessions)
		session->Send(send_buffer);
}

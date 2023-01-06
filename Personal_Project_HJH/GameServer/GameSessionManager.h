#pragma once

class GameSession;

using GameSessionRef = shared_ptr<GameSession>;

class GameSessionManager
{
public:
	void Add(GameSessionRef session);
	void Remove(GameSessionRef session);
	void Broadcast(SendBufferRef send_buffer);

private:
	SpinLock lock;
	set<GameSessionRef> sessions;
};

extern GameSessionManager Gsession_manager;
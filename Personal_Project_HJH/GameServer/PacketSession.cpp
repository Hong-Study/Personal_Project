#include "pch.h"
#include "PacketSession.h"

SendBufferRef PacketSession::Make_send_buffer(Protocol::S_TEST& ptr)
{
	return _Make_send_buffer(ptr, Protocol::LOGIN);
}

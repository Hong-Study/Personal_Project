#include "pch.h"
#include "PKT_Maker.h"

//BYTE* PKT_Maker::MakePacket_URLINPUT(const char* url, int length)
//{
//	BYTE* byte = MakePacket(url, length);
//	PKT_Header* head = reinterpret_cast<PKT_Header*>(&byte[0]);
//	head->pkt_State = PKT_STATE::URL_MAKING;
//
//	return byte;
//}
//
//BYTE* PKT_Maker::MakePacket_URLMAPPING(const char* url, int length)
//{
//	BYTE* byte = MakePacket(url, length);
//	PKT_Header* head = reinterpret_cast<PKT_Header*>(&byte[0]);
//	head->pkt_State = PKT_STATE::URL_MAPPING;
//	return byte;
//}
#pragma once

#pragma pack(1)
enum class PKT_STATE {
	URL_MAKING
	, URL_MAPPING
	, URL_ERROR
};

struct PKT_Header {
	PKT_STATE pkt_State;
	uint32 pkt_Size;
};

struct PKT_DATA {
	uint16 url_length;
	char* url_String;
	PKT_DATA(const char* url, int length) {
		url_String = const_cast<char*>(url);
 		url_length = length;
	}
	
};
#pragma pack()

//// 고쳐야된다 -> 메모리 풀을 구현하여 할당하는 시간을 최소화하기.
//class PKT_Maker
//{
//public:
//	BYTE* MakePacket_URLINPUT(const char* url, int length);
//	BYTE* MakePacket_URLMAPPING(const char* url, int length);
//	
//private:
//	BYTE* MakePacket(const char* url, int length);
//};
//
//inline BYTE* PKT_Maker::MakePacket(const char* url, int length)
//{
//	PKT_DATA* data = new PKT_DATA(url, length);
//	int pos = 0;
//	int size = sizeof(data) + sizeof(PKT_Header);
//
//	BYTE* byte = new BYTE[size];
//	PKT_Header* head = reinterpret_cast<PKT_Header*>(&byte[pos]);
//	pos += sizeof(PKT_Header);
//	memcpy(&byte[pos], data, sizeof(data));
//	head->pkt_Size = sizeof(data);
//	
//	return byte;
//}
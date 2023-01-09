#pragma once

class PakcetHandler
{
public:
	static void Packet_Handler(SessionRef ref, BYTE* buffer, int32 len);

	static SendBufferRef Make_send_buffer(Protocol::S_TEST ptr);

private:
	static void Handler_Login(SessionRef ref, Protocol::S_TEST&& pkt);
};

struct Pkt_Header {
	google::protobuf::uint32 size;
	Protocol::Pkt_Type type;
};

template<typename T>
inline SendBufferRef _Make_send_buffer(T& ptr, Protocol::Pkt_Type type)
{
	const uint16 data_size = static_cast<uint16>(ptr.ByteSizeLong());
	const uint16 packet_size = data_size + sizeof(Pkt_Header);

	SendBufferRef send_buffer = make_shared<SendBuffer>(packet_size);
	Pkt_Header* header = reinterpret_cast<Pkt_Header*>(send_buffer->Buffer());
	header->size = data_size;
	header->type = type;
	ptr.SerializeToArray(&header[1], data_size);
	send_buffer->Close(packet_size);


	return send_buffer;
}

template<typename Packet_Type>
inline Packet_Type Handler_Packet(BYTE* buffer, int32 len)
{
	Packet_Type pkt;
	pkt.ParseFromArray(buffer + sizeof(Pkt_Header), len);

	return pkt;
}
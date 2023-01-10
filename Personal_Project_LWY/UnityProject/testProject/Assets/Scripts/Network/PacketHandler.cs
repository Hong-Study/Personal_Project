using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Google.Protobuf;
using Google.Protobuf.Protocol;

class PacketHandler
{
    public static PacketHandler Instance = new PacketHandler();
    public static byte[] Make_login_handler(S_DATA pkt)
    {
        Pkt_Head head = new Pkt_Head();
        int size = Marshal.SizeOf<Pkt_Head>();
        head.size = (uint)pkt.CalculateSize();
        byte[] send_buffer = new byte[head.size + size];

        IntPtr ptr = Marshal.AllocHGlobal(size);
        Marshal.StructureToPtr(head, ptr, true);
        Marshal.Copy(ptr, send_buffer, 0, size);
        Marshal.FreeHGlobal(ptr);
        
        Array.Copy(pkt.ToByteArray(), 0, send_buffer, size, head.size);

        return send_buffer;
    }
}
struct Pkt_Head
{
    public uint size;
    public INGAME type;
};
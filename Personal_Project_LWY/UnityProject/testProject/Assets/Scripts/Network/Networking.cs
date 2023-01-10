using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Google.Protobuf.Protocol;
using System.Net.Sockets;
using System.Net;
using System;
using Google.Protobuf;
using System.Runtime.InteropServices;
using System.Drawing;

public class Networking : MonoBehaviour
{
    //private TcpClient socketConnection;
    private Socket socket;
    private string m_Ip = "127.0.0.1";
    private int m_Port = 8000;
    private IPEndPoint m_IpEndPoint;
    private bool isConnected = false;

    public void Start()
    {
        ConnectToTcpServer();
    }

    private void ConnectToTcpServer()
    {
        try
        {
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPAddress ipAddress = IPAddress.Parse(m_Ip);
            m_IpEndPoint = new IPEndPoint(ipAddress, m_Port);

            socket.Connect(m_IpEndPoint);
            isConnected = true;

            Debug.Log("Success Login");

            SendMessage();
            socket.Close();
        }
        catch (Exception e)
        {
            Debug.Log("On client connect exception " + e);
        }
    }

    /// Send message to server using socket connection. 	
    private void SendMessage()
    {
        if (!isConnected)
        {
            return;
        }
        try
        {
            if (isConnected)
            {
                int len = 0;
                S_DATA pkt = new S_DATA()
                {
                    Id = 1,
                    MapLevel = 100,
                    MatchRoom = 10
                };

                byte[] datas = PacketHandler.Make_login_handler(pkt);

                len = socket.Send(datas);
                Debug.Log(len + " : Success Send");

                //S_TEST pkt2 = new S_TEST();
                //pkt2.MergeFrom(datas);
                
                //data = reader.ReadLine();
                //Debug.Log(data);
            }
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: " + socketException);
        }
    }
}

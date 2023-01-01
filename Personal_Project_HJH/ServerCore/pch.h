#pragma once

#include <iostream>
using namespace std;

#include <winsock2.h>
#include <mswsock.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#include "StringUtils.h"
#include "SocketAddress.h"
#include "Types.h"
#include "UDPSocket.h"
#include "TCPSocket.h"
#include "SocketUtils.h"
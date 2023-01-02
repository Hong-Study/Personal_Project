#pragma once

#include "Types.h"
#include "CoreMacro.h"

//#include <windows.h>
#include <iostream>
using namespace std;

#include <winsock2.h>
#include <mswsock.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#include<vector>
#include<queue>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<future>
#include<functional>
#include<chrono>
#include<set>
#include<memory>

#include "SpinLock.h"
#include "ThreadPool.h"
#include "Service.h"
#include "Session.h"
#include "Listener.h"
#include "CoreGlobal.h"
#include "PKT_Maker.h"

inline void HandleError(string error) { cout << error << endl; }
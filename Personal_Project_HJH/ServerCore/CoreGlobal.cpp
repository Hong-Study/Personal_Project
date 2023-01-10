#include "pch.h"
#include "CoreGlobal.h"
#include "SocketUtils.h"

SpinLock spinLock;

ThreadPool* GThreadPool = nullptr;
class CoreGlobal {
public:
	CoreGlobal() {
		GThreadPool = new ThreadPool(10);
		//spinLock = new SpinLock();
		SocketUtils::Init();
	}

	~CoreGlobal() {
		delete GThreadPool;
		//delete spinLock;
		SocketUtils::Clear();
	}
}GCoreGlobal;
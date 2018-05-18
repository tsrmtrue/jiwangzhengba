#ifndef __NETWORK_THREAD_ROUGELIKE_H__
#define __NETWORK_THREAD_ROUGELIKE_H__

#include "networkThread.h"

class CRougelikeNetworkThread : public CNetworkThread
{
	typedef CNetworkThread BASECLASS;
public:
	CRougelikeNetworkThread(int id):BASECLASS(id){};
	~CRougelikeNetworkThread() {};

public:
	void onRun(unsigned long long nMsNow) override
	{
		//std::cout << "current peer " << m_mpPeers.size() << std::endl;
	};


protected:

};



#endif
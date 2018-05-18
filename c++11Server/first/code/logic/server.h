#ifndef __SERVER_H__
#define __SERVER_H__

#include <list>
#include <iostream>
#include<event2/event.h>    
#include<event2/thread.h>

#include "base/objectPool.h"
#include "base/threadMgr.h"
#include "logic/networkThread.h"
//#include "logic/sceneThread.h"

class CServer: public CThreadLE
{
	typedef CThreadLE BASECLASS;

public :
	CServer():BASECLASS(0) {};
	~CServer() {};

public:
	virtual bool initThread()
	{
		setNeedTimer(true);
		if (BASECLASS::initThread())
		{
			return startServer();
		}
		return false;
	}
	void onRun(unsigned long long nMsNow) override
	{
		//std::cout << "the server timer " << std::endl;
		//管理创建场景的问题。或者是通过消息传递过来在handleEvent里面做
	}

	bool startServer()
	{
		//根据配置启动场景对象，需要重新编译libevent，打开多线程的限制
		//if (0 != evthread_use_pthreads())
		//{
		//	return -1;
		//}

		//创建监听 线程
		m_pNThread = new CNetworkThread(2);
		if (!m_pNThread
			|| !m_pNThread->setTimeElapse(0,10000)
			|| !m_pNThread->initThread()
			|| !m_pNThread->addListener("192.168.0.114", 19999) //  // //虚拟机内网  // 120.78.189.65//115.29.161.78 //
			|| !m_pNThread->start())
		{
			return false;
		}
		m_lstThreads.push_back(m_pNThread);


		return true;
	}

public:
	CNetworkThread * m_pNThread{ nullptr };

private:
	std::list<IThread*> m_lstThreads;
};
extern CServer * g_pServer;



class CTestClient : public CThreadLE
{
	typedef CThreadLE BASECLASS;

public:
	CTestClient() :BASECLASS(0) {};
	~CTestClient() {};

public:
	virtual bool initThread()
	{
		m_totalConnectionCount = 0;
		m_ip = "192.168.0.114"; //192.168.0.112  //虚拟机外网120.78.189.65 //172.18.233.240  // //115.29.161.78 //
		setNeedTimer(true);
		if (BASECLASS::initThread())
		{
			return startServer();
		}
		return false;
	}
	void onRun(unsigned long long nMsNow) override
	{
		//std::cout << "the server timer " << std::endl;
		//管理创建场景的问题。或者是通过消息传递过来在handleEvent里面做
		if (m_totalConnectionCount++ < 10007)
		{
			m_pNThread->addConnector(m_ip.c_str(), 19999);
		}
	}

	bool startServer()
	{
		//根据配置启动场景对象，需要重新编译libevent，打开多线程的限制
		//if (0 != evthread_use_pthreads())
		//{
		//	return -1;
		//}
		//测试timer
		//CTestTimerThread* pTestTimerThread = new CTestTimerThread(2);
		//if (!pTestTimerThread
		//	|| !pTestTimerThread->setWaitMillisecond(1)
		//	|| !pTestTimerThread->initThread()
		//	|| !pTestTimerThread->start())
		//{
		//	return false;
		//}


		//创建发送 线程
		m_pNThread = new CNetworkThread(2);
		if (!m_pNThread
			|| !m_pNThread->setTimeElapse(0, 1000000)
			|| !m_pNThread->initThread()
			|| !m_pNThread->addConnector(m_ip.c_str(), 19999) 
			|| !m_pNThread->start())
		{
			return false;
		}
		m_lstThreads.push_back(m_pNThread);



		return true;
	}

public:
	CNetworkThread * m_pNThread{ nullptr };

private:
	std::list<IThread*> m_lstThreads;

	int m_totalConnectionCount;
	std::string m_ip;
};
extern CTestClient * g_pTestClient;
#endif



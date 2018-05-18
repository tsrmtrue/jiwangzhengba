#ifndef __NETWORK_THREAD_H__
#define __NETWORK_THREAD_H__

#include <map>
#include <event2/event.h>    
#include <event2/listener.h>    
#include <event2/bufferevent.h>    
#include <event2/bufferevent_struct.h>

#include "base/objectPool.h"
#include "base/threadMgr.h"
#include "logic/player.h"
#include "peerMgr.h"


void socket_read_cb(bufferevent *bev, void *arg);
void socket_event_cb(bufferevent *bev, short events, void *arg);
void listener_cb(evconnlistener *listener, evutil_socket_t fd,
	struct sockaddr *sock, int socklen, void *arg);

enum EPeerType
{//链接通以后需要有第一个协议互相通知身份
	E_PEER_TYPE_UNKNOWN,
	E_PEER_TYPE_GATE,
	E_PEER_TYPE_WORLD,
};

typedef  std::map<int, CLEPeer*> MAP_SOCKET_2_PEER;

class CNetworkThread : public CThreadLE
{
	typedef CThreadLE BASECLASS;


public:
	CNetworkThread(int id):BASECLASS(id){};
	~CNetworkThread() {};

public:
	virtual void addNewPeer(CLEPeer*p)
	{
		if (p)
		{
			m_mpPeers[p->getSocket()] = p;
		}
	}
	virtual void removePeer(CLEPeer*p)
	{
		if (p)
		{
			m_mpPeers.erase(p->getSocket());
			delete p;
		}
	}
	CLEPeer* getFirstPeer()
	{
		if (m_mpPeers.size() > 0)
		{
			return m_mpPeers.begin()->second;
		}
		return nullptr;
	}
	CLEPeer* getPeer(int socket)
	{
		auto iter = m_mpPeers.find(socket);
		if (iter != m_mpPeers.end())
		{
			return iter->second;
		}
		return nullptr;
	}


public:
	void onRun(unsigned long long nMsNow) override
	{
		m_test_count++;
		double d = duration_cast<duration<double>>(high_resolution_clock::now() - m_test_timestamp).count();
		if (d > 10)
		{
			std::cout << "10 seconds libevent cv timer trigger " << m_test_count <<
			"total player count "<<m_mpPeers.size()<< std::endl;
			m_test_count = 0;
			m_test_timestamp = high_resolution_clock::now();
		}

		//std::cout << "current peer " << m_mpPeers.size() << std::endl;
		for(auto iter = m_mpPeers.begin(); iter != m_mpPeers.end(); ++iter)
		// if (getFirstPeer())
		{
			iter->second->doTest();
		}
	};

	virtual bool initThread()
	{
		m_test_count = 0;
		m_test_timestamp = high_resolution_clock::now();

		setNeedTimer(true);
		if (BASECLASS::initThread())
		{
			//注册
			return true;
		}
		return false;
	}
	virtual bool addListener(const char* ip, short port);
	virtual bool addConnector(const char* ip, short port);
	const MAP_SOCKET_2_PEER & getAllPeer() {	return m_mpPeers;	}

protected:
	std::list<evconnlistener *> m_listListener; 
	std::map<int, CLEPeer*> m_mpPeers;

	//测试
	int m_test_count;
	high_resolution_clock::time_point m_test_timestamp;

};

class CTestTimerThread :public CThreadBlocking
{
public:
	using CThreadBlocking::CThreadBlocking;
	void onRun(unsigned long long nMsNow) override
	{
		m_test_count++;
		double d = duration_cast<duration<double>>(high_resolution_clock::now() - m_test_timestamp).count();
		if (d > 10)
		{
			std::cout << "10 seconds c++11 cv timer trigger " << m_test_count << std::endl;
			m_test_count = 0;
			m_test_timestamp = high_resolution_clock::now();
		}

	}

	bool initThread() override
	{
		m_test_count = 0;
		m_test_timestamp = high_resolution_clock::now();
		return true;
	}

private:
	int m_test_count;
	high_resolution_clock::time_point m_test_timestamp;

};

#endif
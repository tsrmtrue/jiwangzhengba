﻿#ifndef __NETWORK_MSG_H__
#define __NETWORK_MSG_H__

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include "protocols/protocols.h"
#include "base/socketPeer.h"
using namespace std::chrono;
class CGatePeer : public CLEPeer
{
	bool afterRecv() override
	{
		//尝试解包，只要满足长度就组包，并投递给相应的场景线程
		return true;
	}
	void onConnected() override
	{
	};

};

class CNetworkThread;
class CScene;
class CRougelikePeer: public CLEPeer
{
	typedef CLEPeer BASECLASS;
	unsigned int m_tick;
	int m_send_tick;
	high_resolution_clock::time_point m_start;
	CNetworkThread * m_pMother;

	//测试网络
	int m_testNetwork_Recv;
	high_resolution_clock::time_point m_testNetwork_timestamp;

	//

public:
	SObjectAction m_lastAction;
	CScene * m_pScene;

public:
	bool afterRecv() override;
	void onConnected() override;
	void onClose() override;

public:
	void setMother(CNetworkThread*);
	using CLEPeer::CLEPeer;

	//业务逻辑。
	void leaveScene();

	const void printTimeElapse(std::string s)
	{
		double d = duration_cast<duration<double>>(high_resolution_clock::now() - m_start).count();
		if (d < 0.05)
		{
			std::cout<<s <<d <<std::endl;
		}
		m_start = high_resolution_clock::now();
	}
};


class CRougelikeTestClient : public CLEPeer
{
	typedef CLEPeer BASECLASS;
	CNetworkThread * m_pMother;
	int m_send_tick;


	//测试网络
	int m_testNetwork_Send;
	high_resolution_clock::time_point m_testNetwork_timestamp;

public:
	bool afterRecv() override;
	void onConnected() override;
	void onClose() override;
	using CLEPeer::CLEPeer;

public:
	void setMother(CNetworkThread*pM) { m_pMother = pM; };

	void  doTest() override;
};


#endif


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

class CTestEchoPeer : public CLEPeer
{

public:
	using CLEPeer::CLEPeer;
	virtual bool afterRecv();
	void onConnected() override
	{
	};

};
class CNetworkThread;
class CRougelikePeer: public CLEPeer
{
	typedef CLEPeer BASECLASS;
	unsigned int m_tick;
	int m_send_tick;
	high_resolution_clock::time_point m_start;
	CNetworkThread * m_pMother;
public:
	SObjectAction m_lastAction;

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



#endif


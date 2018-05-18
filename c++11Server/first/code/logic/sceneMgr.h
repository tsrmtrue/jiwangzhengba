#ifndef __SCENEMGR_H__
#define __SCENEMGR_H__
#include <map>
#include <random>
#include "peerMgr.h"

class CScene
{
	typedef std::map<int, CRougelikePeer*> MAP_ID_2_PEER;
	MAP_ID_2_PEER m_mpPeer;


public:
	void onEnter(CRougelikePeer*p)
	{
		if (p)
		{
			m_mpPeer[p->getSocket()] = p;
			p->m_pScene = this;
		}
	}
	void onLeave(CRougelikePeer*p)
	{
		if(p)
		{
			m_mpPeer.erase(p->getSocket());
			p->m_pScene = NULL;
		}
	}

	MAP_ID_2_PEER& getMap() 
	{
		return m_mpPeer;
	}
	int getCount() { return m_mpPeer.size(); }
};

class CSceneMgr
{
	int m_roomID{ 0 };
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution{ -100, 100 };
public:
	int getRandomDir()
	{
		return distribution(generator);
	}
	void onPeerEnter(CRougelikePeer*p)
	{
		if(p)
		{
			if (m_pTempScene == NULL)
			{
				m_pTempScene = new CScene();
			}
			if (m_pTempScene)
			{
				m_pTempScene->onEnter(p);
				if (m_pTempScene->getCount() > 10)
				{
					m_mpScene[m_roomID++] = m_pTempScene;
					m_pTempScene = NULL;
				}
			}

		}

	}
	void onPeerLeave(CRougelikePeer*p)
	{
		if (p && p->m_pScene)
		{
			p->m_pScene->onLeave(p);
		}
	}


	typedef std::map<int, CScene*> MAP_ID_2_SCENE;
	MAP_ID_2_SCENE m_mpScene;
	CScene* m_pTempScene;
};
extern CSceneMgr * g_pSceneMgr;

#endif



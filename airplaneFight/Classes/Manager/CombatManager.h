#pragma once
#include "SingletonT.h"
#include "cocos2d.h"

class GameLayer;

class CombatManager
{
public:
    CombatManager();
    ~CombatManager();

    
private:

    GameLayer* m_pGameLayer;
public:
    GameLayer* GetRunGameLayer()
    {
        return m_pGameLayer;
    }
    void SetRunGameLayer(GameLayer* pLayer)
    {
        m_pGameLayer = pLayer;
    }
};

typedef SingletonT<CombatManager> CCombatManager;

#define  GetCombatManager CCombatManager::GetInstance 



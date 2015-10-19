#pragma once

#include "SingletonT.h"
#include <vector>
class Weapon;

typedef std::vector<Weapon*> WeaponVector;
class HeroInfoManager
{
public:
    HeroInfoManager();
    ~HeroInfoManager();

    
private:
    int m_baseHp;
    int m_baseAp;
    WeaponVector m_wapon;


public:
    const WeaponVector& GetWeapon() const
    {
        return m_wapon;
    }
    inline int GetBaseHP() const
    {
        return m_baseHp;
    }
    inline int GetBaseAP() const
    {
        return m_baseAp;
    }
};

typedef SingletonT<HeroInfoManager> CHeroInfoManager;

#define  GetHeroInfoManager CHeroInfoManager::GetInstance 



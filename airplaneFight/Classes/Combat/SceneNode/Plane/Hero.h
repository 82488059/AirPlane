#pragma once
#include "AirPlane.h"
class GameLayer;

// 自机
class Hero :
	public AirPlane
{
public:
    Hero();
    virtual ~Hero();
public:
    CREATE_FUNC(Hero);
public:
    virtual bool init();
public:
    void Update(float dt);


private:
    // 时间计数
    float m_runTime;
	//移动速度
	int m_nRapidity;
};


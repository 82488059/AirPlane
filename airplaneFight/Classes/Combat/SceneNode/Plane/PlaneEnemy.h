#pragma once
#include "AirPlane.h"
class GameLayer;

// 自机
class PlaneEnemy :
	public AirPlane
{
public:
    PlaneEnemy();
    virtual ~PlaneEnemy();
public:
    CREATE_FUNC(PlaneEnemy);
public:
    virtual bool init();
public:
    void Update(float dt);
    


private:
    // 时间计数
    float m_runTime;
};


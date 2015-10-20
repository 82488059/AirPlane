#pragma once
#include "AirPlane.h"
class GameLayer;

// 自机
class PlaneEnemy :
	public AirPlane
{
public:
    CREATE_FUNC(PlaneEnemy);
// override
public:
    virtual bool init() override;
    virtual void Update(float dt) override;
    

private:
    // 时间计数
    float m_runTime;
public:
    PlaneEnemy();
    virtual ~PlaneEnemy();
};


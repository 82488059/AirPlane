#pragma once
#include "AirPlane.h"
class GameLayer;

// 自机
class Hero :
	public AirPlane
{
public:
    CREATE_FUNC(Hero);
// override 
public:
    virtual bool init() override;
    virtual void Update(float dt) override;


private:
    // 时间计数
    float m_runTime;
	//移动速度
	int m_nRapidity;
public:
    Hero();
    virtual ~Hero();
};


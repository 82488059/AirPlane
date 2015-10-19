#pragma once
#include "AirPlane.h"
class GameLayer;

// �Ի�
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
    // ʱ�����
    float m_runTime;
};


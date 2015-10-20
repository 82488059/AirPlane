#pragma once
#include "AirPlane.h"
class GameLayer;

// �Ի�
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
    // ʱ�����
    float m_runTime;
public:
    PlaneEnemy();
    virtual ~PlaneEnemy();
};


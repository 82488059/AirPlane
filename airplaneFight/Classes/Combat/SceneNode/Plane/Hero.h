#pragma once
#include "AirPlane.h"
class GameLayer;

// �Ի�
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
    // ʱ�����
    float m_runTime;
	//�ƶ��ٶ�
	int m_nRapidity;
public:
    Hero();
    virtual ~Hero();
};


#pragma once
#include "AirPlane.h"
class GameLayer;

// �Ի�
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
    // ʱ�����
    float m_runTime;
	//�ƶ��ٶ�
	int m_nRapidity;
};


#pragma once
#include "AirPlane.h"
class GameLayer;

typedef enum DIRECTION
{
	nodirection,
	left,
	up,
	right,
	down
}DIRECTION;
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
    // 
	int getHeroRapidity();
	void setHeroRapidity(int nRapidity);
	void setHeroDirection(DIRECTION direction);
	DIRECTION getHeroDirection();
    void SetLayer(GameLayer* pLayer)
    {
        m_pGameLayer = pLayer;
    }


private:
    // ʱ�����
    float m_runTime;
	//�ƶ��ٶ�
	int m_nRapidity;
	//�ƶ�����
	DIRECTION m_eMoveDirection;
};


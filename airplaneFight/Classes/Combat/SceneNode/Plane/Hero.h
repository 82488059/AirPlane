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
    // 时间计数
    float m_runTime;
	//移动速度
	int m_nRapidity;
	//移动方向
	DIRECTION m_eMoveDirection;
};


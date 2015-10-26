#pragma once
#include "SceneNode.h"
#define _USE_TEST_PLANE_ 1
class GameLayer;
class Bullet;
// ·É»ú»ùÀà
class AirPlane :
    public SceneNode
{
// override
public:
    virtual bool Hurt(Bullet* pBullet) override;
    virtual bool init() override;
private:
    int m_hp;
    int m_ap;
    int m_baseHp;
    int m_baseAp;
    int m_maxHp;


protected:
#if _USE_TEST_PLANE_
    cocos2d::LabelTTF* m_pShowHp;

#endif

public:
	AirPlane();
	virtual ~AirPlane();
};


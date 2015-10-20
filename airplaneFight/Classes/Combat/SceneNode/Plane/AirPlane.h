#pragma once
#include "SceneNode.h"
class GameLayer;
class Bullet;
// ·É»ú»ùÀà
class AirPlane :
    public SceneNode
{
public:
	virtual bool Hurt(Bullet* pBullet);

private:
    int m_hp;
    int m_ap;


public:
	AirPlane();
	virtual ~AirPlane();
};


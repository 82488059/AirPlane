#pragma once
#include "SceneNode.h"
class AirPlane;

// ×Óµ¯»ùÀà
class Bullet :
    public SceneNode
{
public:
    Bullet();
    virtual ~Bullet();
	virtual bool HitTest(AirPlane* plane, float dt);
	int GetAP() const {
		return m_ap;
	}
private:
	int m_ap;
};


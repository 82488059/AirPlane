#pragma once
#include "SceneNode.h"
class AirPlane;

// ×Óµ¯»ùÀà
class Bullet :
    public SceneNode
{
// override 
public:
    virtual bool HitTest(AirPlane* plane, float dt) override;

public:
	int GetAP() const {
		return m_ap;
	}
private:
    int m_ap; 

public:
    Bullet();
    virtual ~Bullet();
};


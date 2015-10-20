#include "SceneNode.h"


SceneNode::SceneNode()
	: m_bIsDeath(false)
	, m_speed(0.f, 0.f)
{
}

SceneNode::~SceneNode()
{
}

bool SceneNode::init()
{
    return Sprite::init();
}

bool SceneNode::IsDeath()
{
    return m_bIsDeath;
}

void SceneNode::Update(float dt)
{
    Moving(dt);
}

void SceneNode::Moving(float dt)
{
    this->setPosition(getPosition() + dt*GetSpeed());
}
// ΚάΉ₯»χ
bool SceneNode::Hurt(Bullet* pBullet)
{ 
    return false; 
}
// Ή₯»χ
bool SceneNode::HitTest(AirPlane* plane, float dt)
{ 
    return false;
}
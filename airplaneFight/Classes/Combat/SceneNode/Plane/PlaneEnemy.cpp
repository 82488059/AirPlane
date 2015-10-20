#include "PlaneEnemy.h"
#include "GameLayer.h"
#include "BulletNormal.h"
USING_NS_CC;

PlaneEnemy::PlaneEnemy()
:m_runTime(0)
{
}


PlaneEnemy::~PlaneEnemy()
{
}

bool PlaneEnemy::init()
{
	if (!AirPlane::init())
    {
        return false;
    }
    auto bgSprite = Sprite::create("plane11.png");
	bgSprite->setRotation(180);
    bgSprite->setPosition(0, 0);
    addChild(bgSprite);

    return true;
}

void PlaneEnemy::Update(float dt)
{
    m_runTime += dt;

    if (m_runTime > 1.f)
    {
        m_runTime -= 1.f;
        Bullet* pB = BulletNormal::create();
        pB->setPosition(this->getPosition());
		pB->SetSpeed(Point(0, -10));
		m_pGameLayer->AddEnemyBullet(pB);

    }
}
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
    CCTexture2D* tex = CCTextureCache::getInstance()->addImage("plane11.png");
    this->initWithTexture(tex);
    //this->setRotation(180);
    //this->setTexture(tex);

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
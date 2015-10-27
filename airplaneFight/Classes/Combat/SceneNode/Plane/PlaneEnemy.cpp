#include "PlaneEnemy.h"
#include "GameLayer.h"
#include "BulletNormal.h"
USING_NS_CC;

PlaneEnemy::PlaneEnemy()
:m_runTime(0)
{
    SetHp(1);// = 1;
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
    Texture2D* tex = Director::getInstance()->getTextureCache()->addImage("enemy11.png");
    //Texture2D* tex = TextureCache::getInstance()->addImage("enemy11.png");
    this->initWithTexture(tex);
    //this->setRotation(180);
    //this->setTexture(tex);

    return true;
}

void PlaneEnemy::Update(float dt)
{
    AirPlane::Update(dt);
    m_runTime += dt;
    if (m_runTime > 3.f)
    {
        m_runTime -= 3.f;
        Bullet* pB = BulletNormal::create();
        pB->setRotation(180);
        pB->setPosition(this->getPosition());
		pB->SetSpeed(Point(0, -100));
		m_pGameLayer->AddEnemyBullet(pB);
    }
}
#include "Hero.h"
#include "HeroInfoManager.h"
#include "Weapon.h"
#include "GameLayer.h"
#include "BulletNormal.h"
USING_NS_CC;

Hero::Hero()
:m_runTime(0),
m_nRapidity(3),
m_eMoveDirection(nodirection)
{
}


Hero::~Hero()
{
}

bool Hero::init()
{
	if (!AirPlane::init())
    {
        return false;
    }
    auto bgSprite = Sprite::create("plane1.png");
    bgSprite->setPosition(0, 0);
    addChild(bgSprite);


    GetHeroInfoManager()->GetWeapon();

    return true;
}

void Hero::Update(float dt)
{
    m_runTime += dt;

    if (m_runTime > 1.f)
    {
        m_runTime -= 1.f;
        Bullet* pB = BulletNormal::create();
        pB->setPosition(this->getPosition());
		m_pGameLayer->AddHeroBullet(pB);

    }
}

int Hero::getHeroRapidity()
{
	return m_nRapidity;
}

void Hero::setHeroRapidity(int nRapidity)
{
	m_nRapidity = nRapidity;
}

DIRECTION Hero::getHeroDirection()
{
	return m_eMoveDirection;
}

void Hero::setHeroDirection(DIRECTION direction)
{
	m_eMoveDirection = direction;
}
#include "AirPlane.h"
#include "Bullet.h"
USING_NS_CC;

AirPlane::AirPlane()
	: m_hp(10000)
	, m_ap(1)
    , m_baseAp(1)
    , m_baseHp(10000)
    , m_maxHp(10000)
{
}


AirPlane::~AirPlane()
{
}
bool AirPlane::init()
{
    if (!SceneNode::init ())
    {
        return false;
    }
#if _USE_TEST_PLANE_
    m_pShowHp = LabelTTF::create("10000", "Arial", 10, Size(0,0));
    this->addChild(m_pShowHp, 1);

#endif


    return true;
}
bool AirPlane::Hurt(Bullet* pBullet)
{
	m_hp -= pBullet->GetAP();
    m_hp;
    char hp[6];
    sprintf(hp, "%d", m_hp);
    m_pShowHp->setString(hp);
	return true;

}

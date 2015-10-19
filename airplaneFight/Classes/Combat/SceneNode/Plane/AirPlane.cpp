#include "AirPlane.h"
#include "Bullet.h"

AirPlane::AirPlane()
	: m_hp(10000)
	, m_ap(1)
{
}


AirPlane::~AirPlane()
{
}

bool AirPlane::Hurt(Bullet* pBullet)
{
	m_hp -= pBullet->GetAP();


	return true;

}

#include "Bullet.h"
#include "AirPlane.h"
USING_NS_CC;

Bullet::Bullet()
	:m_ap(1)
{
	SetSpeed(Point(0.f, 10.f));
}


Bullet::~Bullet()
{
}

bool Bullet::HitTest(AirPlane* plane, float dt)
{
	// 简单测试，子弹速度快时打不中飞机 。
	Point end = this->getPosition() + GetSpeed()*dt;
	Point test = end - plane->getPosition();
	if (-10. < test.x && test.x < 10. && -10. < test.y && test.y < 10.)
	{
		plane->Hurt(this);
		return true;
	}

	return false;
}

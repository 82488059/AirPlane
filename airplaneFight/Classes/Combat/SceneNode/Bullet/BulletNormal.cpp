#include "BulletNormal.h"

USING_NS_CC;

BulletNormal::BulletNormal()
{
}


BulletNormal::~BulletNormal()
{
}

bool BulletNormal::init()
{
    if (!Bullet::init())
    {
        return false;
    }
    Sprite* sp = Sprite::create("heroBullet.png");
    sp->setPosition(0., 0.);
    addChild(sp);

    return true;
}
#include "Level1.h"
USING_NS_CC;

Level1::Level1()
    : m_runTime(0.f)
{
}


Level1::~Level1()
{
}

bool Level1::init()
{
    if (!GameLayer::init ())
    {
        return false;
    }
    auto size = Director::getInstance()->getVisibleSize();
    auto bgSprite = Sprite::create("img_bg_level_1.jpg");
    bgSprite->setPosition(size.width / 2, size.height / 2);
    addChild(bgSprite);

    this->scheduleUpdate();

    return true;
}


void Level1::Update(float dt)
{
    m_runTime += dt;


}

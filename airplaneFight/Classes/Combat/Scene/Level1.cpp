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
    addChild(bgSprite, 1, "bg1");

	auto spriteContent = bgSprite->getContentSize();
	auto bgSprite2 = Sprite::create("img_bg_level_1.jpg");
	bgSprite2->setPosition(size.width / 2, size.height / 2 + spriteContent.height);
	addChild(bgSprite2, 1, "bg2");
    this->scheduleUpdate();

    return true;
}


void Level1::Update(float dt)
{
    GameLayer::Update(dt);
    m_runTime += dt;
	MovebgSprite();
}

void Level1::MovebgSprite()
{
	auto size = Director::getInstance()->getVisibleSize();
	auto bgSprite1 = getChildByName("bg1");
	auto bgSprite2 = getChildByName("bg2");
	auto bgSize = bgSprite1->getContentSize();
	auto bgS1Point = bgSprite1->getPosition();
	auto bgS2Point = bgSprite2->getPosition();
	bgSprite1->setPosition(size.width / 2, bgS1Point.y - m_nbgSpeed);
	bgSprite2->setPosition(size.width / 2, bgS2Point.y - m_nbgSpeed);
	if ((bgS1Point.y + bgSize.height / 2) < 0)
	{
		bgSprite1->setPosition(size.width / 2, bgS2Point.y + bgSize.height - m_nbgSpeed);
	}
	else if ((bgS2Point.y + bgSize.height / 2) < 0)
	{
		bgSprite2->setPosition(size.width / 2, bgS1Point.y + bgSize.height - m_nbgSpeed);
	}
}
#include "RockerHandle.h"
#include "GameLayer.h"
#include "Hero.h"
USING_NS_CC;

RockerHandle::RockerHandle()
:m_bIsPressHandle(false)
{
}

RockerHandle::~RockerHandle()
{

}

bool RockerHandle::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto size = Director::getInstance()->getVisibleSize();
	auto baseSprite = Sprite::create("base.png");
	auto handleSprite = Sprite::create("handle.png");
	baseSprite->setPosition(size.width/2 + 65, 60);
	auto baseSpriteSize = baseSprite->getContentSize();
	handleSprite->setPosition(baseSpriteSize.width/2 + 2.5, baseSpriteSize.height/2 + 2.5);
	baseSprite->addChild(handleSprite, 1, "handleSprite");
	addChild(baseSprite, 1, "baseSprite");
	//´¥ÃþÒÆ¶¯¼àÌý
	auto touchEventListener = EventListenerTouchOneByOne::create();
	touchEventListener->setSwallowTouches(true);
	touchEventListener->onTouchBegan = CC_CALLBACK_2(RockerHandle::onTouchBegan, this);
	touchEventListener->onTouchMoved = CC_CALLBACK_2(RockerHandle::onTouchMoved, this);
	touchEventListener->onTouchEnded = CC_CALLBACK_2(RockerHandle::onTouchEnded, this);
	touchEventListener->onTouchCancelled = CC_CALLBACK_2(RockerHandle::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventListener, handleSprite);
	return true;
}

bool RockerHandle::onTouchBegan(Touch *touch, Event *event)
{
	auto pHandleSprite = (Sprite *)event->getCurrentTarget();
	auto pBaseSprite = (Sprite *)getChildByName("baseSprite");
	auto handleSpritePosition = pHandleSprite->getPosition();
	auto handleSpriteContent = pHandleSprite->getContentSize();
	auto touchPoint = pBaseSprite->convertToNodeSpace(touch->getLocation());
	auto nRadius = CaculateRadius(touchPoint, handleSpritePosition);
	if (nRadius <= handleSpriteContent.height/2)
	{
		log("true");
		m_bIsPressHandle = true;
		auto pGameLayer = (GameLayer *)getParent()->getChildByName("gameLayer");
		auto pHero = (Hero *)pGameLayer->GetHero();
		if (NULL != pHero)
		{
			pHero->SetSpeed(Point(0, 0));
		}
	}
	return true;
}

void RockerHandle::onTouchMoved(Touch *touch, Event *event)
{
	if (m_bIsPressHandle)
	{
		auto pHandleSprite = (Sprite *)event->getCurrentTarget();
		auto pBaseSprite = (Sprite *)getChildByName("baseSprite");
		auto handleSpritePosition = pHandleSprite->getPosition();
		auto handleSpriteContent = pHandleSprite->getContentSize();
		auto baseSpriteContent = pBaseSprite->getContentSize();
		auto touchPoint = pBaseSprite->convertToNodeSpace(touch->getLocation());
		auto nRadius = CaculateRadius(touchPoint, Vec2(baseSpriteContent.width / 2 + 2.5, baseSpriteContent.height / 2 + 2.5));
		log("radius:%f", nRadius);
		if (nRadius < 8)
		{
			auto pGameLayer = (GameLayer *)getParent()->getChildByName("gameLayer");
			auto pHero = (Hero *)pGameLayer->GetHero();
			if (NULL != pHero)
			{
				pHero->SetSpeed(Point(0, 0));
			}
			pHandleSprite->setPosition(touchPoint);
		}
		else if (nRadius >= 8 && nRadius < 17.5)
		{
			float px = (touchPoint.x - baseSpriteContent.width / 2 - 2.5) / nRadius;
			float py = (touchPoint.y - baseSpriteContent.height / 2 - 2.5) / nRadius;
			auto pGameLayer = (GameLayer *)getParent()->getChildByName("gameLayer");
			auto pHero = (Hero *)pGameLayer->GetHero();
			if (NULL != pHero)
			{
				pHero->SetSpeed(Point(200 * px, 200 * py));
				pGameLayer->RockerMoveHero();
			}
			pHandleSprite->setPosition(touchPoint);
		}
		else if(nRadius >= 17.5)
		{
			float px = (touchPoint.x - baseSpriteContent.width / 2 - 2.5) / nRadius;
			float py = (touchPoint.y - baseSpriteContent.height / 2 - 2.5) / nRadius;
			auto pGameLayer = (GameLayer *)getParent()->getChildByName("gameLayer");
			auto pHero = (Hero *)pGameLayer->GetHero();
			if (NULL != pHero)
			{
				pHero->SetSpeed(Point(150 *px, 150 * py));
				pGameLayer->RockerMoveHero();
			}
			pHandleSprite->setPosition(17.5 * px + baseSpriteContent.width / 2 + 2.5, 17.5 * py + baseSpriteContent.height / 2 + 2.5);
		}
	}
}

void RockerHandle::onTouchEnded(Touch *touch, Event *event)
{
	m_bIsPressHandle = false;
	auto pBaseSprite = (Sprite *)getChildByName("baseSprite");
	auto baseSpriteContent = pBaseSprite->getContentSize();
	auto pHandleSprite = (Sprite *)event->getCurrentTarget();
	auto pGameLayer = (GameLayer *)getParent()->getChildByName("gameLayer");
	auto pHero = (Hero *)pGameLayer->GetHero();
	if (NULL != pHero)
	{
		pHero->SetSpeed(Point(0, 0));
		pGameLayer->RockerStopMoveHero();
	}
	auto moveToOrigin = MoveTo::create(0.3, Vec2(baseSpriteContent.width / 2 + 2.5, baseSpriteContent.height/2 + 2.5));
	pHandleSprite->runAction(moveToOrigin);
}

void RockerHandle::onTouchCancelled(Touch *touch, Event *event)
{
	m_bIsPressHandle = false;
	auto pBaseSprite = (Sprite *)getChildByName("baseSprite");
	auto baseSpriteContent = pBaseSprite->getContentSize();
	auto pHandleSprite = (Sprite *)event->getCurrentTarget();
	auto pGameLayer = (GameLayer *)getParent()->getChildByName("gameLayer");
	auto pHero = (Hero *)pGameLayer->GetHero();
	if (NULL != pHero)
	{
		pHero->SetSpeed(Point(0, 0));
		pGameLayer->RockerStopMoveHero();
	}
	auto moveToOrigin = MoveTo::create(0.3, Vec2(baseSpriteContent.width / 2 + 2.5, baseSpriteContent.height / 2 + 2.5));
	pHandleSprite->runAction(moveToOrigin);
}

float RockerHandle::CaculateRadius(cocos2d::Vec2 point1, cocos2d::Vec2 point2)
{
	auto nRadius = hypot(fabs(point1.x - point2.x), fabs(point1.y - point2.y));
	return nRadius;
}
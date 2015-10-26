#include "RockerHandle.h"
USING_NS_CC;

RockerHandle::RockerHandle()
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
	baseSprite->addChild(handleSprite);
	addChild(baseSprite);
	return true;
	//´¥ÃþÒÆ¶¯¼àÌý
	auto touchEventListener = EventListenerTouchOneByOne::create();
	touchEventListener->setSwallowTouches(true);
	touchEventListener->onTouchBegan = CC_CALLBACK_2(RockerHandle::onTouchBegan, this);
	touchEventListener->onTouchMoved = CC_CALLBACK_2(RockerHandle::onTouchMoved, this);
	touchEventListener->onTouchEnded = CC_CALLBACK_2(RockerHandle::onTouchEnded, this);
	touchEventListener->onTouchCancelled = CC_CALLBACK_2(RockerHandle::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventListener, handleSprite);
}

bool RockerHandle::onTouchBegan(Touch *touch, Event *event)
{
	int a = 10;
	return true;
}

void RockerHandle::onTouchMoved(Touch *touch, Event *event)
{
	int a = 10;
}

void RockerHandle::onTouchEnded(Touch *touch, Event *event)
{
	int a = 10;
}

void RockerHandle::onTouchCancelled(Touch *touch, Event *event)
{
	int a = 10;
}

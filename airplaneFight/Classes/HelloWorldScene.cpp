#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite1 = Sprite::create("HelloWorld.png");
	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto sprite2 = Sprite::create("Icon-72.png");
	sprite2->setPosition(sprite1->getContentSize().width / 2, sprite1->getContentSize().height / 2);
	auto sprite3 = Sprite::create("Icon-Small.png");
	sprite3->setPosition(sprite2->getContentSize().width / 2, sprite2->getContentSize().height / 2);
	sprite1->addChild(sprite2, 1);
	sprite2->addChild(sprite3, 2);
	addChild(sprite1, 0);

	auto s = getContentSize();
	auto s1 = sprite1->getContentSize();
	auto s2 = sprite2->getContentSize();
	auto s3 = sprite3->getContentSize();

	auto p1 = sprite1->getPosition();
	auto p2 = sprite2->getPosition();
	auto p3 = sprite3->getPosition();
	auto p21 = sprite1->convertToWorldSpace(p2);
	auto p31 = sprite1->convertToWorldSpace(p3);
	auto p32 = sprite2->convertToWorldSpace(p3);

	// position the sprite on the center of the screen
    

    // add the sprite as a child to this layer
    
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

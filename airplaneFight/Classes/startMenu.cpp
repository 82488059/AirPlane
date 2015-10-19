#include "startMenu.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

USING_NS_CC;

Scene* startMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = startMenu::create();
	scene->addChild(layer);
	return scene;
}

bool startMenu::init()
{
	if (! Layer::init())
	{
		return false;
	}
	//������Ч
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("music/menuMusic.mp3");
	auto size = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	//��ӱ���
	auto bgSprite = Sprite::create("image/img_bg_logo.jpg");
	bgSprite->setPosition(size.width/2, size.height/2);
	addChild(bgSprite);

	//��ӱ���װ��
	auto bgLoGo = Sprite::create("image/LOGO.png");
	bgLoGo->setScale(0.5);
	bgLoGo->setPosition(size.width/2, size.height* 3/4);
	addChild(bgLoGo);

	//�����˵�
	//������ʼ�˵���
	auto startLabel = LabelTTF::create("startGame", "Arial", 20, Size(120, 30), TextHAlignment::CENTER);
	startLabel->setColor(Color3B::GREEN);
	auto startMenuItem = MenuItemLabel::create(startLabel, CC_CALLBACK_1(startMenu::menuStartGame, this));
	startMenuItem->setPosition(size.width/2, size.height/2 + 20);

	//�������ò˵���
	auto settingLabel = LabelTTF::create("settingGame", "Arial", 20, Size(120, 30), TextHAlignment::CENTER);
	settingLabel->setColor(Color3B::GREEN);
	auto settingMenuItem = MenuItemLabel::create(settingLabel, CC_CALLBACK_1(startMenu::menuSettingGame, this));
	startMenuItem->setPosition(size.width / 2, size.height / 2);

	//�����˳��˵���
	auto exitLabel = LabelTTF::create("exitGame", "Arial", 20, Size(120, 30), TextHAlignment::CENTER);
	exitLabel->setColor(Color3B::GREEN);
	auto exitMenuItem = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(startMenu::menuExitGame, this));
	exitMenuItem->setPosition(size.width / 2, size.height / 2 - 20);


	auto menu = Menu::create(startMenuItem, settingMenuItem, exitMenuItem, NULL);
	menu->alignItemsVertically();
	addChild(menu, 1);
	return true;
}

void startMenu::menuStartGame(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(GameScene::createScene());
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
		CocosDenshion::SimpleAudioEngine::getInstance()->end();
}

void startMenu::menuSettingGame(Ref* pSender)
{
	
}

void startMenu::menuExitGame(cocos2d::Ref *pSend)
{

}
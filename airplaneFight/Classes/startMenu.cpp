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
	//加载音效
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("menuMusic.mp3");
	auto size = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	//添加背景
	auto bgSprite = Sprite::create("img_bg_logo.jpg");
	bgSprite->setPosition(size.width/2, size.height/2);
	addChild(bgSprite);

	//添加背景装饰
	auto bgLoGo = Sprite::create("LOGO.png");
	bgLoGo->setScale(0.8);
	bgLoGo->setPosition(size.width/2, size.height* 3/4);
	addChild(bgLoGo);

	//创建菜单
	//创建开始菜单项
	//auto startLabel = LabelTTF::create("startGame", "Arial", 20, Size(120, 30), TextHAlignment::CENTER);
	//startLabel->setColor(Color3B::GREEN);
	//auto startMenuItem = MenuItemLabel::create(startLabel, CC_CALLBACK_1(startMenu::menuStartGame, this));
	//startMenuItem->setPosition(size.width/2, size.height/2 + 20);

	////创建设置菜单项
	//auto settingLabel = LabelTTF::create("settingGame", "Arial", 20, Size(120, 30), TextHAlignment::CENTER);
	//settingLabel->setColor(Color3B::GREEN);
	//auto settingMenuItem = MenuItemLabel::create(settingLabel, CC_CALLBACK_1(startMenu::menuSettingGame, this));
	//startMenuItem->setPosition(size.width / 2, size.height / 2);

	////创建退出菜单项
	//auto exitLabel = LabelTTF::create("exitGame", "Arial", 20, Size(120, 30), TextHAlignment::CENTER);
	//exitLabel->setColor(Color3B::GREEN);
	//auto exitMenuItem = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(startMenu::menuExitGame, this));
	//exitMenuItem->setPosition(size.width / 2, size.height / 2 - 20);

	auto startMenuItem = MenuItemImage::create("start.png", "start_press.png", CC_CALLBACK_1(startMenu::menuStartGame, this));
	startMenuItem->setScale(0.085);
	startMenuItem->setPosition(size.width / 2, size.height / 2 + 20);
	auto levelMenuItem = MenuItemImage::create("level.png", "level_press.png", CC_CALLBACK_1(startMenu::menuSettingGame, this));
	levelMenuItem->setScale(0.085);
	levelMenuItem->setPosition(size.width / 2, size.height / 2);
	auto scoreMenuItem = MenuItemImage::create("score.png", "score_press.png", CC_CALLBACK_1(startMenu::menuStartGame, this));
	scoreMenuItem->setScale(0.085);
	scoreMenuItem->setPosition(size.width / 2, size.height / 2 - 20);
	auto quitMenuItem = MenuItemImage::create("quit.png", "quit_press.png", CC_CALLBACK_1(startMenu::menuStartGame, this));
	quitMenuItem->setScale(0.085);
	quitMenuItem->setPosition(size.width / 2, size.height / 2 - 40);

	auto menu = Menu::create(startMenuItem, levelMenuItem, scoreMenuItem, quitMenuItem, NULL);
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
void startMenu::menuScore(cocos2d::Ref *pSend)
{
	
}

void startMenu::menuExitGame(cocos2d::Ref *pSend)
{
	Director::getInstance()->end();
}
#ifndef __STARTMENU_SCENE_H__
#define __STARTMENU_SCENE_H__

#include "cocos2d.h"

class  startMenu: public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

private:
	// a selector callback
	void menuStartGame(cocos2d::Ref* pSender);
	void menuSettingGame(cocos2d::Ref *pSender);
	void startMenu::menuScore(cocos2d::Ref *pSend);
	void menuExitGame(cocos2d::Ref *pSend);
	// implement the "static create()" method manually
	CREATE_FUNC(startMenu);
};

#endif // __STARTMENU_SCENE_H__
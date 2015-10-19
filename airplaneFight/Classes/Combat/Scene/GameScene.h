#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"

class GameLayer;
// ÓÎÏ·³¡¾°
class GameScene :
    public cocos2d::Layer
{

// create
public:
    static cocos2d::Scene* createScene();
    CREATE_FUNC(GameScene);
// virtual 
public:
    virtual bool init();
// new 
public:
    // Ë¢ÐÂ
    void Update(float dt);

private:
    float m_runTime;
    GameLayer* m_gameLayer;
//
public:
    GameScene();
    virtual ~GameScene();
};

#endif // !__GAMESCENE_H__
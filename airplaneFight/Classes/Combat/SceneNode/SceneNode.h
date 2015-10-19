#ifndef __SCENENODE_H__
#define __SCENENODE_H__
#include "cocos2d.h"
// 战场中的各种对像基类
class GameLayer;
class SceneNode :
    public cocos2d::Sprite
{
public:
	bool IsDeath()
	{
		return false;
	}
	virtual void Update(float dt)
	{
		Moving(dt);
	}
	virtual void Moving(float dt)
	{
		this->setPosition(getPosition()+dt*GetSpeed());
	}
	void SetSpeed(const cocos2d::Point& speed)
	{
		m_speed = speed;
	}
	const cocos2d::Point& GetSpeed() const
	{
		return m_speed;			 
	}
public:
	// 
	void SetLayer(GameLayer* pLayer)
	{
		m_pGameLayer = pLayer;
	}
protected:
	// 战场
	GameLayer* m_pGameLayer;
private:
	bool m_bIsDeath;
	cocos2d::Point m_speed;

public:
    SceneNode();
    virtual ~SceneNode();
};

#endif // !__SCENENODE_H__
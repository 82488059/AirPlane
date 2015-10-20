#ifndef __SCENENODE_H__
#define __SCENENODE_H__
#include "cocos2d.h"
class Bullet;
class AirPlane;
class GameLayer;

// ս���еĸ��ֶ������
class SceneNode :
    public cocos2d::Sprite
{
// override
public:
    virtual bool init() override;

// virtual
public:
    virtual bool IsDeath();
    virtual void Update(float dt);
    virtual void Moving(float dt);
    // �ܹ���
    virtual bool Hurt(Bullet* pBullet); // {return false; }
    // ����
    virtual bool HitTest(AirPlane* plane, float dt);// { return false; }

public:
	void SetDeath()
	{
		m_bIsDeath = true;
	}
	void SetSpeed(const cocos2d::Point& speed)
	{
		m_speed = speed;
	}
	const cocos2d::Point& GetSpeed() const
	{
		return m_speed;
	}
	// 
	void SetLayer(GameLayer* pLayer)
	{
		m_pGameLayer = pLayer;
	}
	GameLayer* GetLayer()
	{
		return m_pGameLayer;
	}
protected:
	// ս��
	GameLayer* m_pGameLayer;
private:
	bool m_bIsDeath;
	cocos2d::Point m_speed;

public:
    SceneNode();
    virtual ~SceneNode();
};

#endif // !__SCENENODE_H__
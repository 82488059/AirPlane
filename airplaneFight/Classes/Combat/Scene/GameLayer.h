#include "cocos2d.h"
#include "Combat\SceneNode\Plane\Hero.h"

USING_NS_CC;

class AirPlane;
class Bullet;
typedef std::list<AirPlane*> EnemyList;
typedef std::list<Bullet*> EnemyBulletList;
typedef std::list<Bullet*> HeroBulletList;
// ��Ϸ����

class GameLayer :
    public cocos2d::Layer 
{

// create
public:
    CREATE_FUNC(GameLayer);
// virtual 
public:
    virtual bool init();
// new 
public:
    // ˢ��
    void Update(float dt);
	void UpdateHero(float dt);
	void UpdateEnemy(float dt);
	void UpdateBullet(float dt);
	// �ӵ� 
	void AddHeroBullet(Bullet* pB);
	void AddEnemyBullet(Bullet* pB);
	// ����
    virtual void ProductEnemy(float dt);

protected:
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

protected:
    EnemyList m_enemyList;
    Hero* m_pHero;
	EnemyBulletList m_enemyBulletList;
	HeroBulletList m_heroBulletList;
//
public:
    GameLayer(); 
    virtual ~GameLayer();

private:
	void moveStart(float dt);
	void heroMove(DIRECTION direction);

private:
	int m_nKeyPressed;
	bool m_bIsPressed;
};

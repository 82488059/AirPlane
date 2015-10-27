#include "cocos2d.h"


USING_NS_CC;
class SceneNode;
class AirPlane;
class Bullet;
class Hero;
typedef std::list<AirPlane*> EnemyList;
typedef std::list<Bullet*> EnemyBulletList;
typedef std::list<Bullet*> HeroBulletList;
// 游戏场景

class GameLayer :
    public cocos2d::Layer 
{

// create
public:
    CREATE_FUNC(GameLayer);
// override 
public:
    virtual bool init() override;
// vritual
public:
    // 刷新
    virtual void Update(float dt);
    // 出怪
    virtual void ProductEnemy(float dt);
    // 矩形在地图内返回true
    virtual bool IsInMap(const SceneNode& node);
// new 
public:
	void UpdateHero(float dt);
	void UpdateEnemy(float dt);
	void UpdateBullet(float dt);
	// 子弹 
	void AddHeroBullet(Bullet* pB);
	void AddEnemyBullet(Bullet* pB);
	//设置地图速度
	void SetBGSpeed(int nSpeed){ m_nbgSpeed = nSpeed; }
	int GetBGSpeed(){ return m_nbgSpeed; }
	Hero *GetHero();
	void RockerMoveHero();
	void RockerStopMoveHero();

protected:
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

protected:
    EnemyList m_enemyList;
    Hero* m_pHero;
	EnemyBulletList m_enemyBulletList;
	HeroBulletList m_heroBulletList;
	//地图移动速度
	int m_nbgSpeed;
//
public:
    GameLayer(); 
    virtual ~GameLayer();

private:
	void HeroMove(float dt);

private:
	int m_nKeyPressed;
	bool m_bIsPressed;
};

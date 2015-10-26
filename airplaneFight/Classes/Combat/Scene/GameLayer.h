#include "cocos2d.h"


USING_NS_CC;
class SceneNode;
class AirPlane;
class Bullet;
class Hero;
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
// override 
public:
    virtual bool init() override;
// vritual
public:
    // ˢ��
    virtual void Update(float dt);
    // ����
    virtual void ProductEnemy(float dt);
    // �����ڵ�ͼ�ڷ���true
    virtual bool IsInMap(const SceneNode& node);
// new 
public:
	void UpdateHero(float dt);
	void UpdateEnemy(float dt);
	void UpdateBullet(float dt);
	// �ӵ� 
	void AddHeroBullet(Bullet* pB);
	void AddEnemyBullet(Bullet* pB);
	//���õ�ͼ�ٶ�
	void SetBGSpeed(int nSpeed){ m_nbgSpeed = nSpeed; }
	int GetBGSpeed(){ return m_nbgSpeed; }

protected:
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

protected:
    EnemyList m_enemyList;
    Hero* m_pHero;
	EnemyBulletList m_enemyBulletList;
	HeroBulletList m_heroBulletList;
	//��ͼ�ƶ��ٶ�
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

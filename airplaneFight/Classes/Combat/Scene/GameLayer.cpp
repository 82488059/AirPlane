#include "GameLayer.h"
#include "Hero.h"
#include "PlaneEnemy.h"
#include "CombatManager.h"
#include "Bullet.h"

GameLayer::GameLayer()
: m_pHero(NULL),
m_nKeyPressed(0),
m_bIsPressed(false)
{
}


GameLayer::~GameLayer()
{
}

bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_pHero = Hero::create();
	m_pHero->setPosition(Director::getInstance()->getVisibleSize().width / 2, 50);
	addChild(m_pHero, 1, "hero");
	m_pHero->SetLayer(this);
	GetCombatManager()->SetRunGameLayer(this);

	//在基类场景增加键盘按键移动飞机和飞机射出子弹的控制
	auto keyboardEventListener = EventListenerKeyboard::create();
	keyboardEventListener->onKeyPressed = CC_CALLBACK_2(GameLayer::onKeyPressed, this);
	keyboardEventListener->onKeyReleased = CC_CALLBACK_2(GameLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardEventListener, m_pHero);
	return true;
}


void GameLayer::Update(float dt)
{
	UpdateHero(dt);
	UpdateEnemy(dt);
	UpdateBullet(dt);
	ProductEnemy(dt);
}
void GameLayer::UpdateHero(float dt)
{
	m_pHero->Update(dt);

}
void GameLayer::UpdateEnemy(float dt)
{
	m_enemyList;
	for (auto it = m_enemyList.begin(); it != m_enemyList.end(); /*++it*/)
	{
		if ((*it)->IsDeath())
		{
			m_enemyList.erase(it++);
		}
		else
		{
			(*it)->Update(dt);
			++it;
		}
	}
}
void GameLayer::UpdateBullet(float dt)
{
	// m_heroBulletList;
	for (auto it = m_heroBulletList.begin(); it != m_heroBulletList.end(); /*++it*/)
	{
		if ((*it)->IsDeath())
		{
			m_heroBulletList.erase(it++);
		}
		else
		{
			for (auto enemy = m_enemyList.begin(); enemy != m_enemyList.end(); ++enemy)
			{
				if (!(*enemy)->IsDeath())
				{
					if ((*it)->HitTest(*enemy, dt))
					{
						break;
					}
				}
			}
			(*it)->Update(dt);
			++it;
		}
	}

	// m_enemyBulletList;
	for (auto it = m_enemyBulletList.begin(); it != m_enemyBulletList.end(); /*++it*/)
	{
		if ((*it)->IsDeath())
		{
			m_enemyBulletList.erase(it++);
		}
		else
		{
			(*it)->HitTest(m_pHero, dt);
			(*it)->Update(dt);
			++it;
		}
	}
}
void GameLayer::ProductEnemy(float dt)
{
	if (m_enemyList.empty())
	{
		AirPlane* pAP = PlaneEnemy::create();
		pAP->setPosition(Director::getInstance()->getVisibleSize().width / 2, 300);
		addChild(pAP, 1, "enemy");
		pAP->SetLayer(this);
		m_enemyList.push_back(pAP);
	}
}
void GameLayer::AddHeroBullet(Bullet* pB)
{
	this->addChild(pB, 3);
	this->m_heroBulletList.push_back(pB);
}
void GameLayer::AddEnemyBullet(Bullet* pB)
{
	this->addChild(pB, 3);
	this->m_enemyBulletList.push_back(pB);
}
// 键盘触摸回调事件
void GameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
															 m_pHero->setHeroDirection(right);
															 m_nKeyPressed++;
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
														  m_pHero->setHeroDirection(up);
														  m_nKeyPressed++;
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
															m_pHero->setHeroDirection(down);
															m_nKeyPressed++;
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
															m_pHero->setHeroDirection(left);
															m_nKeyPressed++;
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_A:
	{
														   m_pHero->setHeroDirection(left);
														   m_nKeyPressed++;
	}
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_D:
	{
														   m_pHero->setHeroDirection(right);
														   m_nKeyPressed++;
	}
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_S:
	{
														   m_pHero->setHeroDirection(down);
														   m_nKeyPressed++;
	}
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_W:
	{
														   m_pHero->setHeroDirection(up);
														   m_nKeyPressed++;
	}
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_A:
	{
												   m_pHero->setHeroDirection(left);
												   m_nKeyPressed++;
	}
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_D:
	{
												   m_pHero->setHeroDirection(right);
												   m_nKeyPressed++;
	}
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_S:
	{
												   m_pHero->setHeroDirection(down);
												   m_nKeyPressed++;
	}
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_W:
	{
												   m_pHero->setHeroDirection(up);
												   m_nKeyPressed++;
	}
		break;
	default:
		return;
	}
	schedule(CC_SCHEDULE_SELECTOR(GameLayer::moveStart), 0.01);
}

void GameLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("Key with keycode %d released", keyCode);
	m_nKeyPressed -= 1;
	if (m_nKeyPressed <= 0)
	{
		unschedule(CC_SCHEDULE_SELECTOR(GameLayer::moveStart));
	}
	
}

void GameLayer::moveStart(float dt)
{
	heroMove(m_pHero->getHeroDirection());
}

void GameLayer::heroMove(DIRECTION direction)
{
	auto heroCurrentPos = m_pHero->getPosition();
	auto nRapidity = m_pHero->getHeroRapidity();
	switch (direction)
	{
	case nodirection:
	{

	}
		break;
	case left:
	{
				 m_pHero->setPosition(heroCurrentPos.x - nRapidity, heroCurrentPos.y);
	}
		break;
	case up:
	{
			   m_pHero->setPosition(heroCurrentPos.x, heroCurrentPos.y + nRapidity);
	}
		break;
	case right:
	{
				  m_pHero->setPosition(heroCurrentPos.x + nRapidity, heroCurrentPos.y);
	}
		break;
	case down:
	{
				 m_pHero->setPosition(heroCurrentPos.x, heroCurrentPos.y - nRapidity);
	}
		break;
	default:
		break;
	}
}
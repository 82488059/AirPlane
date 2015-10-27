#include "GameLayer.h"
#include "Hero.h"
#include "PlaneEnemy.h"
#include "CombatManager.h"
#include "Bullet.h"

GameLayer::GameLayer()
: m_pHero(NULL),
m_nKeyPressed(0),
m_bIsPressed(false),
m_nbgSpeed(1)
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
	addChild(m_pHero, 2);
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
	for (auto it = m_enemyList.begin(); it != m_enemyList.end(); /*++it*/)
	{
        if ((*it)->IsDeath() || !IsInMap(**it))
		{
            (*it)->removeFromParent();
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
        for (auto enemy = m_enemyList.begin(); enemy != m_enemyList.end(); ++enemy)
        {
            if (!(*enemy)->IsDeath() || !IsInMap(**it))
            {
                if ((*it)->HitTest(*enemy, dt))
                {
                    break;
                }
            }
        }
        // (*it)->Update(dt);
        ++it;
    }
	for (auto it = m_heroBulletList.begin(); it != m_heroBulletList.end(); /*++it*/)
	{
        if ((*it)->IsDeath() || !IsInMap(**it))
		{
            (*it)->removeFromParent();
			m_heroBulletList.erase(it++);
		}
		else
		{
			(*it)->Update(dt);
			++it;
		}
	}

	// m_enemyBulletList;
    for (auto it = m_enemyBulletList.begin(); it != m_enemyBulletList.end(); ++it)
    {
        (*it)->HitTest(m_pHero, dt);
    }
	for (auto it = m_enemyBulletList.begin(); it != m_enemyBulletList.end(); /*++it*/)
	{
		if ((*it)->IsDeath() || !IsInMap (**it))
		{
            (*it)->removeFromParent();
			m_enemyBulletList.erase(it++);
		}
		else
		{
			// (*it)->HitTest(m_pHero, dt);
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

bool GameLayer::IsInMap(const SceneNode& node)
{
    static Size size = Director::getInstance()->getVisibleSize();
    Rect rect = node.getTextureRect();
    Point p = node.getPosition();
    rect.origin = p;
    if (rect.getMaxX () < 0 || rect.getMinX () > size.width
        || rect.getMinY() > size.height || rect.getMaxY () < 0)
    {
        return false;
    }

    return true;
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
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW
		|| keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW
		|| keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW
		|| keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW
		|| keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_A
		|| keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_W
		|| keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_D
		|| keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_S
		|| keyCode == EventKeyboard::KeyCode::KEY_A
		|| keyCode == EventKeyboard::KeyCode::KEY_W
		|| keyCode == EventKeyboard::KeyCode::KEY_D
		|| keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		m_bIsPressed = true;
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
																 m_pHero->SetSpeed(Point(300, 0));
		}
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		{
															  m_pHero->SetSpeed(Point(0, 300));
		}
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		{
																m_pHero->SetSpeed(Point(0, -300));
		}
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		{
																m_pHero->SetSpeed(Point(-300, 0));
		}
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_A:
		{
															   m_pHero->SetSpeed(Point(-300, 0));
		}
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_D:
		{
															   m_pHero->SetSpeed(Point(300, 0));
		}
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_S:
		{
															   m_pHero->SetSpeed(Point(0, -300));
		}
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_W:
		{
															   m_pHero->SetSpeed(Point(0, 300));
		}
															   break;

		case cocos2d::EventKeyboard::KeyCode::KEY_A:
		{
													   m_pHero->SetSpeed(Point(-300, 0));
		}
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_D:
		{
													   m_pHero->SetSpeed(Point(300, 0));
		}
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_S:
		{
													   m_pHero->SetSpeed(Point(0, -300));
		}
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_W:
		{
													   m_pHero->SetSpeed(Point(0, 300));

		}
			break;
		default:
			return;
		}
			m_nKeyPressed++;
			m_bIsPressed = true;
			schedule(CC_SCHEDULE_SELECTOR(GameLayer::HeroMove));
		}
}

void GameLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW
		|| keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW
		|| keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW
		|| keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW
		|| keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_A
		|| keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_W
		|| keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_D
		|| keyCode == EventKeyboard::KeyCode::KEY_CAPITAL_S
		|| keyCode == EventKeyboard::KeyCode::KEY_A
		|| keyCode == EventKeyboard::KeyCode::KEY_W
		|| keyCode == EventKeyboard::KeyCode::KEY_D
		|| keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		if (m_bIsPressed)
		{
			m_nKeyPressed--;
			if (m_nKeyPressed <= 0)
			{
				m_bIsPressed = false;
				unschedule(CC_SCHEDULE_SELECTOR(GameLayer::HeroMove));
			}
		}
	}
}

void GameLayer::HeroMove(float dt)
{
	auto heroCurrentPos = m_pHero->getPosition();
	auto size = Director::getInstance()->getVisibleSize();
	auto heroSize = m_pHero->getContentSize();
	if (m_pHero->GetSpeed().x <= 0 && m_pHero->GetSpeed().y <= 0)
	{
		if (heroCurrentPos.x - heroSize.width / 2 < 0 || heroCurrentPos.y - heroSize.height / 2 < 0)
		{
			return;
		}
	}
	else if(m_pHero->GetSpeed().x <= 0 && m_pHero->GetSpeed().y > 0)
	{
		if (heroCurrentPos.x - heroSize.width / 2 < 0 || heroCurrentPos.y + heroSize.height / 2 > size.height)
		{
			return;
		}
	}
	else if (m_pHero->GetSpeed().x > 0 && m_pHero->GetSpeed().y <= 0)
	{
		if (heroCurrentPos.x + heroSize.width / 2 > size.width || heroCurrentPos.y - heroSize.height / 2 < 0)
		{
			return;
		}
	}
	else if (m_pHero->GetSpeed().x > 0 && m_pHero->GetSpeed().y > 0)
	{
		if (heroCurrentPos.x + heroSize.width / 2 > size.width || heroCurrentPos.y + heroSize.height / 2 > size.height)
		{
			return;
		}
	}
	else
	{
		return;
	}
	m_pHero->Moving(dt);
}

Hero *GameLayer::GetHero()
{
	if (NULL != m_pHero)
	{
		return m_pHero;
	}
	else
	{
		return NULL;
	}
}

void GameLayer::RockerMoveHero()
{
	schedule(CC_SCHEDULE_SELECTOR(GameLayer::HeroMove));
}

void GameLayer::RockerStopMoveHero()
{
	unschedule(CC_SCHEDULE_SELECTOR(GameLayer::HeroMove));
}

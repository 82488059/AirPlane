#include "GameScene.h"
#include "Level1.h"

USING_NS_CC;

GameScene::GameScene()
    : m_runTime(0.f)
    , m_gameLayer(NULL)
{
}


GameScene::~GameScene()
{
}

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool GameScene::init()
{
    if (!Layer::init ())
    {
        return false;
    }

    m_gameLayer = Level1::create();
    addChild(m_gameLayer, 1);

    this->schedule(schedule_selector(GameScene::Update));

    return true;
}


void GameScene::Update(float dt)
{
    m_runTime += dt;
    m_gameLayer->Update(dt);

}

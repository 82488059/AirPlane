#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "gamelayer.h"

// ÓÎÏ·³¡¾°
class Level1 :
    public GameLayer
{

// create
public:
    CREATE_FUNC(Level1);
// override 
public:
    virtual bool init() override;
    // Ë¢ÐÂ
    virtual void Update(float dt) override;

private:
	void MovebgSprite();

private:
    float m_runTime;
	
//
public:
    Level1();
    virtual ~Level1();
};

#endif // !__LEVEL1_H__
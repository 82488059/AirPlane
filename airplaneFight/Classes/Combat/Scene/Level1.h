#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "gamelayer.h"

// ��Ϸ����
class Level1 :
    public GameLayer
{

// create
public:
    CREATE_FUNC(Level1);
// virtual 
public:
    virtual bool init();
// new 
public:
    // ˢ��
    void Update(float dt);

private:
    float m_runTime;

//
public:
    Level1();
    virtual ~Level1();
};

#endif // !__LEVEL1_H__
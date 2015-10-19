#pragma once
#include "Bullet.h"
// ×Óµ¯Àà
class BulletNormal :
    public Bullet
{
public:
    BulletNormal();
    virtual ~BulletNormal();
    CREATE_FUNC(BulletNormal);
    virtual bool init();
private:
    

};


#pragma once
#include "Bullet.h"
// �ӵ���
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


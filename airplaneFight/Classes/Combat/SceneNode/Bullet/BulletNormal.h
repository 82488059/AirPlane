#pragma once
#include "Bullet.h"
// �ӵ���
class BulletNormal :
    public Bullet
{
public:
    CREATE_FUNC(BulletNormal);
// override
public:
    virtual bool init() override;

private:
    
public:
    BulletNormal();
    virtual ~BulletNormal();
};


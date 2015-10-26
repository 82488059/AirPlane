#ifndef ROCKERHANDLE_H_
#define ROCKERHANDLE_H_

#include "cocos2d.h"

class RockerHandle : public cocos2d::Layer
{
public:
	RockerHandle();
	virtual ~RockerHandle();

public:
	CREATE_FUNC(RockerHandle);

protected:
	virtual bool init() override;
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) override;
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) override;
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) override;
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event) override;
};
#endif //ROCKERHANDLE_H_
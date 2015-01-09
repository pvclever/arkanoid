#pragma once

#include <list>

#include "cocos2d.h"

class Bricks : public cocos2d::Node
{
public:
	static Bricks* create();
	Bricks() //: mRunning(false), mTargetX(0), mDirection(1, 1)
	{
	///	scheduleUpdate();
	}
	virtual bool init();
	


};
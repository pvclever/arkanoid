#pragma once

#include "cocos2d.h"

class BallSprite : public cocos2d::Sprite
{
public:
	BallSprite() : mRunning(false), mDirection(1, 1)
	{
		this->scheduleUpdate();
	}
	static BallSprite* create();
	void update	(	float 	delta);
	void run()
	{
		mRunning = true;
	}
	void stop()
	{
		mRunning = false;
	}
	bool bounceFrom(cocos2d::Rect aRect);
	bool bounceInto(cocos2d::Rect aRect);
private:
	bool mRunning;
	cocos2d::Vec2 mDirection;
};
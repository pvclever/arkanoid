#pragma once

#include "cocos2d.h"

class BallSprite : public cocos2d::Sprite
{
public:
    BallSprite() : mRunning(false), mTargetX(0), mDirection(1, 1)
    {
        scheduleUpdate();
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
    void setTargetX(float aTargetX);
    void flipDirectionX()
    {
		mDirection.y = fabsf(mDirection.y);
    }
	//void flipDirection()
	//{
	//	mDirection.y = fabsf(mDirection.y);
	//	mDirection.x = -mDirection.x;
	//}
	//const cocos2d::Vec2& getDirection() const
	//{
	//	return mDirection;
	//}
	
	void bounceFrom(cocos2d::Rect aRect);
private:
    bool mRunning;
    float mTargetX;
    cocos2d::Vec2 mDirection;
};
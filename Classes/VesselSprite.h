#pragma once

#include "cocos2d.h"

class VesselSprite : public cocos2d::Sprite
{
public:
    VesselSprite() : mRunning(false), mTargetX(0)
    {
		scheduleUpdate();
	}
    static VesselSprite* create();
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
private:
    bool mRunning;
    float mTargetX;
};

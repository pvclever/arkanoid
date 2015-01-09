#include "BallSprite.h"
USING_NS_CC;

BallSprite* BallSprite::create()
{
    BallSprite* pSprite = new BallSprite();
    
    if (pSprite->initWithFile("ball.png"))
    {
        pSprite->autorelease();
        return pSprite;
    }
    
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void BallSprite::update	(	float 	delta)
{
    if (!mRunning)
    {
        return;
    }
    auto pos = getPosition();
    
    static const float kSpeedFactor = 150;

    this->setPosition(getPosition() + mDirection * kSpeedFactor * delta);
    if (mDirection.x >0 && pos.x >1000)
    {
        mDirection.x = -mDirection.x;
    }
    if (mDirection.x <0 && pos.x <= 0)
    {
        mDirection.x = -mDirection.x;
    }
    if (mDirection.y >0 && pos.y > 630)
    {
        mDirection.y = -mDirection.y;
    }
   
}

void BallSprite::bounceFrom(cocos2d::Rect aRect)
{
	auto pos = getPosition();
	if (pos.x < aRect.getMaxX())
	{
		mDirection.x = -fabsf(mDirection.x);
	} else if (pos.x > aRect.getMinX())
	{
		mDirection.x = fabsf(mDirection.x);
	}
	if (pos.y < aRect.getMaxY())
	{
		mDirection.y = -fabsf(mDirection.y);
	} else if (pos.y > aRect.getMinY())
	{
		mDirection.y = fabsf(mDirection.y);
	}
	
	
}

//void BallSprite::setTargetX(float aTargetX)
///{
///    mTargetX = aTargetX;
//}
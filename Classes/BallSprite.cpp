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
	const auto& pos = getPosition();
	
	static const float kSpeedFactor = 130.0f;

	this->setPosition(pos + mDirection * kSpeedFactor * delta);

}

bool BallSprite::bounceFrom(cocos2d::Rect aRect){
	if (getBoundingBox().intersectsRect(aRect))
	{
		/*
		
		auto box = getBoundingBox();
		if (box.getMinX() <= aRect.getMaxX())
		{
			mDirection.x = fabsf(mDirection.x);
		} else if (box.getMaxX() >= aRect.getMinX())
		{
			mDirection.x = -fabsf(mDirection.x);
		}
		
		if (box.getMinY() <= aRect.getMaxY())
		{
			mDirection.y = fabsf(mDirection.y);
		} else if (box.getMaxY() >= aRect.getMinY())
		{
			mDirection.y = fabsf(mDirection.y);
		}
*/
		auto pos = getPosition();
		if (pos.x >= aRect.getMaxX())
		{
			mDirection.x = fabsf(mDirection.x);
		} else if (pos.x <= aRect.getMinX())
		{
			mDirection.x = fabsf(mDirection.x);
		}
		
		if (pos.y >= aRect.getMaxY())
		{
			mDirection.y = fabsf(mDirection.y);
		} else if (pos.y <= aRect.getMinY())
		{
			mDirection.y = -fabsf(mDirection.y);
		}
		return true;
	}
	return false;
}


bool BallSprite::bounceInto(cocos2d::Rect aRect)
{
	if (getBoundingBox().intersectsRect(aRect))
	{
		auto pos = getPosition();
		if (pos.x >= aRect.getMaxX())
		{
			mDirection.x = -fabsf(mDirection.x);
		} else if (pos.x <= aRect.getMinX())
		{
			mDirection.x = fabsf(mDirection.x);
		}
		if (pos.y >= aRect.getMaxY())
		{
			mDirection.y = -fabsf(mDirection.y);
		} else if (pos.y <= aRect.getMinY())
		{
			mDirection.y = fabsf(mDirection.y);
		}
		return true;
	}
	return false;
}


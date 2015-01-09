#include "VesselSprite.h"
USING_NS_CC;

VesselSprite* VesselSprite::create()
{
    VesselSprite* pSprite = new VesselSprite();
    
    if (pSprite->initWithFile("vessel.png"))
    {
        pSprite->autorelease();
        return pSprite;
    }
    
    CC_SAFE_DELETE(pSprite);
    return nullptr;
}

void VesselSprite::update	(	float 	delta)
{
    if (!mRunning)
    {
        return;
    }
    float d = mTargetX - getPosition().x;
    if (fabs(d) < 10)
    {
        return;
    }
    static const float kSpeedFactor = 800;
    auto xpos = getPosition().x + kSpeedFactor * delta * (d>0 ? 1 : -1);
    this->setPosition(Vec2(xpos, getPosition().y));
}



void VesselSprite::setTargetX(float aTargetX)
{
    mTargetX = aTargetX;
}
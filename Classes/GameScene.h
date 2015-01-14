#pragma once
#include "cocos2d.h"
class BallSprite;
class VesselSprite;
class MessageHUD;
class GameScene : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
    void update	( float delta);
private:
	unsigned int mScore;
	BallSprite* mBallSprite;
    VesselSprite* mVesselSprite;
	MessageHUD* mMessageHUD;
	std::list<cocos2d::Sprite*> mBricksList;
	void checkCollisions(cocos2d::Rect aRect);
	cocos2d::EventListenerTouchOneByOne* mListener;
	GameScene() : mScore(0), mBallSprite(nullptr),
				mVesselSprite(nullptr), mMessageHUD(nullptr)
	{
	}
};

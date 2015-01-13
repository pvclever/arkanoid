#pragma once
#include "cocos2d.h"
class Bricks;
class BallSprite;
class VesselSprite;
class MessageHUD;
class GameScene : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
    void update	( float 	delta);
private:
	Bricks* mBricksSprite;
    BallSprite* mBallSprite;
    VesselSprite* mVesselSprite;
	std::list<cocos2d::Sprite*> mBricksList;
	void checkCollisions(cocos2d::Rect aRect);
	MessageHUD* mMessageHUD;
	unsigned int mScore;
	GameScene() : mScore(0)
	{
	}
};

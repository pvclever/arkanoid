#include "ui/UIButton.h"
#include "GameScene.h"
#include "VesselSprite.h"
#include "BallSprite.h"
#include "MessageHUD.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	for (size_t i = 0; i<10; i++)
	{
		for (size_t j = i; j< 20 - i - i; j++)
		{
			auto brick = Sprite::create("Brick.png");
			brick->setPosition(Vec2(origin.x + j * 32 - 10*32 + visibleSize.width/2, origin.y + visibleSize.height/2 + i*32  - 70));
			addChild(brick);
			mBricksList.push_back(brick);
		}
	}
	
	mVesselSprite = VesselSprite::create();
	mVesselSprite->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y  + mVesselSprite->getContentSize().height/2));
	addChild(mVesselSprite);
	
	mBallSprite  = BallSprite::create();
	mBallSprite->setPosition(Vec2(origin.x + visibleSize.width/2, mVesselSprite->getPosition().y +  mVesselSprite->getContentSize().height/2 + 10));
	addChild(mBallSprite);
	
	mListener = EventListenerTouchOneByOne::create();
	mListener->onTouchMoved = ([this](Touch* touch, Event* event){
		mVesselSprite->setTargetX(touch->getLocation().x);
	});
	mListener->onTouchBegan = ([this](Touch* touch, Event* event){
		cocos2d::Vec2 p = touch->getLocation();
		mVesselSprite->setTargetX(p.x);
		mVesselSprite->run();
		mBallSprite->run(); // need for the first time to start play
		return true;
	});
	mListener->onTouchEnded = ([this](Touch* touch, Event* event){
		mVesselSprite->stop();
	});
	
	auto dispatcher = this->getEventDispatcher();
	dispatcher->addEventListenerWithFixedPriority(mListener, 31);
	
	mMessageHUD = MessageHUD::createLayer();
	mMessageHUD->setPosition(Vec2(0,  origin.y + visibleSize.height));
	addChild(mMessageHUD, 2);
	
	scheduleUpdate();
	return true;
}

void GameScene::update	( float delta)
{
	static const Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (mBallSprite->getPosition().y < 5){
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		mBallSprite->stop();
		auto button = cocos2d::ui::Button::create();
		button->setTitleFontSize(50);
		button->setTitleText("GAME OVER");
		button->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.x + visibleSize.height/2));
		addChild(button);
		button->addClickEventListener([&](Ref* pSender){
			auto dispatcher = this->getEventDispatcher();
			dispatcher->removeEventListener(mListener);
			Director::getInstance()->replaceScene(TransitionFlipX::create(1.0, GameScene::createScene()));
		});
	}
	mBallSprite->bounceFrom(mVesselSprite->getBoundingBox());
	mBallSprite->bounceInto(this->getBoundingBox());
	checkCollisions(mBallSprite->getBoundingBox());
}



void GameScene::checkCollisions(cocos2d::Rect aRect){
	for (auto it = mBricksList.begin() ; it!= mBricksList.end(); it++)
	{
		if (mBallSprite->bounceFrom((*it)->getBoundingBox()))
		{
			auto fadeOut = FadeOut::create(1.5f);
			auto brick = (*it);
			auto callback = CallFunc::create([=]() {
				removeChild(brick);
			});
			auto seq = Sequence::create(fadeOut, callback, nullptr);
			(*it)->runAction(seq);
			it = mBricksList.erase(it);
			mScore++;
			mMessageHUD->setScore(mScore);
			return;
		}
	}
}
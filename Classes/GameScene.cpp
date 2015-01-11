#include "ui/UIButton.h"
#include "GameScene.h"
#include "VesselSprite.h"
#include "BallSprite.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	for (size_t i = 0; i<7; i++)
	{
		for (size_t j = i; j<16 - i; j++)
		{
			auto brick = Sprite::create("Brick.png");
			brick->setPosition(Vec2(j*32  + visibleSize.width/4, origin.y + visibleSize.height - 300 + i*32));
			addChild(brick);
			mBricksList.push_back(brick);
		}
	}

	vesselSprite = VesselSprite::create();
	vesselSprite->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y  + vesselSprite->getContentSize().height/2));
	addChild(vesselSprite);

	ballSprite  = BallSprite::create();
	ballSprite->setPosition(Vec2(origin.x + visibleSize.width/2, vesselSprite->getPosition().y +  vesselSprite->getContentSize().height/2 + 100));
	addChild(ballSprite);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchMoved = ([=](Touch* touch, Event* event){
		vesselSprite->setTargetX(touch->getLocation().x);
	});
	listener->onTouchBegan = ([=](Touch* touch, Event* event){
		cocos2d::Vec2 p = touch->getLocation();
		vesselSprite->setTargetX(p.x);
		vesselSprite->run();
		return true;
	});
	listener->onTouchEnded = ([=](Touch* touch, Event* event){
		vesselSprite->stop();
	});
	
	auto dispatcher = this->getEventDispatcher();
	dispatcher->addEventListenerWithFixedPriority(listener, 31);
	ballSprite->run();
	this->scheduleUpdate();
	return true;
}

void GameScene::update	( float 	delta)
{
	static const Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (ballSprite->getPosition().y < 5){
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		ballSprite->stop();
		auto button = cocos2d::ui::Button::create();
		button->setTitleFontSize(50);
		button->setTitleText("GAME OVER");
		button->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.x + visibleSize.height/2));
		addChild(button);
		button->addClickEventListener([=](Ref* pSender){
			Director::getInstance()->end();
			#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			exit(0);
			#endif
		});
	}
	ballSprite->bounceFrom(vesselSprite->getBoundingBox());
	ballSprite->bounceInto(this->getBoundingBox());
	checkCollisions(ballSprite->getBoundingBox());
	ballSprite->update(delta);
}



void GameScene::checkCollisions(cocos2d::Rect aRect){
	for (auto it = mBricksList.begin() ; it!= mBricksList.end(); it++)
	{
		if (ballSprite->bounceFrom((*it)->getBoundingBox()))
		{
			removeChild(*it);
			it = mBricksList.erase(it);
			return;
		}
	 }
	
}
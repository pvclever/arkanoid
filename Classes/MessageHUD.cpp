#include "MessageHUD.h"
USING_NS_CC;

MessageHUD::MessageHUD() {}

MessageHUD::~MessageHUD() {}

MessageHUD* MessageHUD::createLayer()
{
	MessageHUD* a = new MessageHUD();
	a->create();
	//a->setColor(cocos2d::Color3B(0, 0, 0));
	
	//a->setContentSize(cocos2d::Size::Size(1, 1));
	//a->setAnchorPoint(cocos2d::Vec2(0, 0));
	
	a->initOptions();

	return a;
}

void MessageHUD::initOptions()
{
	auto _messageLabel = cocos2d::Label::create("Score:", "Marker Felt.ttf", 30);
	_messageLabel->setColor(cocos2d::Color3B(255, 215, 0));
	addChild(_messageLabel, 1);
	_messageLabel->setAnchorPoint(Vec2(0,1));
	_messageLabel->setPosition(cocos2d::Vec2(0,0));
	
	mScoreLabel = cocos2d::Label::create("0", "Marker Felt.ttf", 30);
	mScoreLabel->setAnchorPoint(Vec2(0,1));
	mScoreLabel->setColor(cocos2d::Color3B(255, 215, 0));
	mScoreLabel->setPosition(cocos2d::Vec2(_messageLabel->getContentSize().width + 10,0));
	addChild(mScoreLabel, 1);

}

void MessageHUD::setScore(const unsigned int score)
{
	mScoreLabel->setString(Value((int)score).asString());
}

void MessageHUD::draw(cocos2d::Renderer * renderer, const cocos2d::Mat4 & transform,
					  bool transformUpdated) {}
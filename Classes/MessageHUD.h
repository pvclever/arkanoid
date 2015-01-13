#pragma once
#include "cocos2d.h"

class MessageHUD : public cocos2d::Layer
{
public:
	MessageHUD();
	~MessageHUD();
	
	static MessageHUD* createLayer();
	void initOptions();
	
	virtual void draw (cocos2d::Renderer * renderer, const cocos2d::Mat4 & transform,
					   bool transformUpdated);
	
	void setScore(const unsigned int score);
private:
	cocos2d::Label* mScoreLabel;
};
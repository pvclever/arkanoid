#include "Bricks.h"
USING_NS_CC;

Bricks* Bricks::create()
{
	Bricks* pSprite = new Bricks();
	
	if (pSprite->init()){
		pSprite->autorelease();
		return pSprite;
	}
	
	CC_SAFE_DELETE(pSprite);
	return nullptr;
}


bool Bricks::init()
{
	for (size_t i = 0; i<30; i++)
	{
		auto s = Sprite::create("Brick.png");
		s->setPosition(Vec2(i*32, 0));
		addChild(s);
		//mBricksList.push_back(s);
	}
	this->setContentSize(Size(32,32));
	
	return true;
}

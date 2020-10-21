#pragma once
#include "Sprite.h"
#include "Const.h"
#include "Bar.h"

class Ball : public Sprite {
public:
	Ball();
	~Ball();

	void Update();
	void UpdateBeforeRelease();
	void Reset();



	void InvertX();
	void InvertY();

	void onCollideWithWall();
	void onCollideWithBar(Bar bar);
	void onCollideWithBrick();

private:

	float NextBallPosX = posX + Acceleration + (GetSpriteWidth() / 2);
	float NextBallPosY = posY + Acceleration + (GetSpriteHeight() / 2);

	int NumOfBalls = 3;
	
};


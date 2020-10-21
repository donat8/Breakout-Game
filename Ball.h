#pragma once
#include "Sprite.h"
#include "Const.h"

class Ball : public Sprite {
public:
	Ball();
	~Ball();

	void Update();
	void UpdateBeforeRelease();
	void Reset();
	void onCollideWithWall();
	void onCollideWithPaddle();
	void onCollideWithBrick();

private:

	int NumOfBalls = 3;
	
};


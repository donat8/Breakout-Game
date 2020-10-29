#pragma once
#include <stdio.h>
#include <iostream>
#include "Sprite.h"
#include "Ball.h"

class Brick :public Sprite {
public:

	Brick(const char* Id, const char* Texture, const unsigned int *HitPoints, const char* HitSound, const char* BreakSound, unsigned int* BreakScore);

	void DrawBrick();

	Rect GetBrickRect()  const;
	void SetBrickRect();

	bool CheckBallCollision(Ball& ball) const;
	unsigned int ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter() const;


protected:
	const char* Id;
	const char* Texture;

	//times to hit to destroy
	unsigned int HitPoints;

	const char* HitSound;
	const char* BreakSound;

	//how much points per break
	const unsigned int BreakScore;

	Rect rect;
	bool destroyed = true;

};

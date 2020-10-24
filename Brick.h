#pragma once
#include <stdio.h>
#include <iostream>
#include "Sprite.h"
#include <vector>
#include "Ball.h"

class Brick :public Sprite {
public:

	Brick(const char* Id, const char* Texture, const unsigned int *HitPoints, const char* HitSound, const char* BreakSound, unsigned int* BreakScore);

	void DrawBrick();

	int GetBreakScore();
	int SetBreakScore();

	void PlayHitSound();
	void PlayBreakSound();



	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter() const;


protected:
	const char* Id;
	const char* Texture;

	//times to hit to destroy
	const unsigned int HitPoints;

	const char* HitSound;
	const char* BreakSound;

	//how much points per break
	const unsigned int BreakScore;

	Rect rect;
	bool destroyed = true;

};

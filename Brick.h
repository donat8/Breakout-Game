#pragma once
#include <stdio.h>
#include <iostream>
#include "Sprite.h"
#include <vector>
#include "Ball.h"

class Brick : public Sprite {
public:
	Brick(float posX, float posY, const char* texture);
	~Brick();

	void DrawBrick();

	int GetBreakScore();
	int SetBreakScore();

	void PlayHitSound();
	void PlayBreakSound();

	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter() const;


private:
	const char* id;
	const char* TexturePath;

	//times to hit to destroy
	static unsigned int HitPoints;

	const char* HitSound;
	const char* BreakSound;

	//how much points per break
	static unsigned int BreakScore;

	Rect rect;
	bool destroyed = true;

};

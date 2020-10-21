#pragma once
#include <stdio.h>
#include <iostream>
#include "Sprite.h"
#include <vector>

class Brick :Sprite {
public:
	Brick();
	~Brick();

	void DrawBrick();
	int GetBreakScore();

	void PlayHitSound();
	void PlayBreakSound();

	void DestroyBrickInGame();


private:
	const char* id;
	const char* TexturePath;
	//times to hit to destroy
	static unsigned int HitPoints;

	const char* HitSound;
	const char* BreakSound;

	//how much points per break
	static unsigned int BreakScore;

	
	

};

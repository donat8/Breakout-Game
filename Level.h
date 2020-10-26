#pragma once
#include "Brick.h"
#include <vector>

class Level{
public:
	Level()=default;


	ALLEGRO_BITMAP* SetLevelBackground();
	void InitBrickMap(Level *level);
	void DrawBrickMap();
	void CheckBrickBallCollision(Ball& ball);

	void StartLevel();

    const unsigned int *RowCount;
	const unsigned int *ColumnCount;
	const unsigned int *RowSpacing;
	const unsigned int *ColumnSpacing;
	const char *BackgroundTexture;

	Brick *BrickSoft;
	Brick *BrickMedium;
	Brick *BrickHard;
	Brick *BrickImpenetrable;

	const char* BricksMap;

	

protected:

	
	

	//char Id;
	//const char* Texture;
	//unsigned int HitPoints;
	//const char* HitSound;
	//const char* BreakSound;
	//unsigned int BreakScore;


	

	Brick *bricks[40];



	// brick configuration on screen


};

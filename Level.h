#pragma once
#include "Brick.h"
#include <vector>

class Level{
public:
	Level()=default;


	ALLEGRO_BITMAP* SetLevelBackground();
	void InitBrickMap();
	void DrawBrickMap();
	void StartLevel();

	unsigned int *RowCount;
	unsigned int *ColumnCount;
	unsigned int *RowSpacing;
	unsigned int *ColumnSpacing;
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


	

	Brick *bricks[30];



	// brick configuration on screen


};

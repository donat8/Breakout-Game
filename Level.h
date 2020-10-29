#pragma once
#include "Brick.h"
#include <vector>

class Level{
public:
	Level()=default;


	ALLEGRO_BITMAP* SetLevelBackground();

	void InitBrickMap(Level *level);
	void DrawBrickMap();
	unsigned int CheckBrickBallCollision(Ball& ball);

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

	Brick *bricks[60];

};

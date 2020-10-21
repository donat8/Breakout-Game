#pragma once

class Level {
public:
	Level();
	~Level();

	void SetLevelBackground();
	void InitBrickMap();
	void StartLevel();

protected:

	unsigned int RowCount;
	unsigned int ColumnCount;
	unsigned int RowSpacing;
	unsigned int ColumnSpacing;
	const char* BackgroundTexture;

	char Id[2];
	const char* Texture;
	unsigned int HitPoints;
	const char* HitSound;
	const char* BreakSound;
	unsigned int BreakScore;

	//list of brick configuration
	const char* Bricks;

};

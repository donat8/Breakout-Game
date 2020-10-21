#pragma once

class Level {
public:
	Level();
	~Level();

	void SetLevelBackground();
	void InitBrickMap();
	void StartLevel();

private:
	int id;
	int RowCount;
	int ColumnCount;
	int RowSpacing;
	int ColumnSpacing;
	const char* BackgroundTexturePath;
	const char* BricksMap[20][3];

};

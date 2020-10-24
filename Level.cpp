#include "Level.h"



ALLEGRO_BITMAP* Level::SetLevelBackground()
{
	return al_load_bitmap(BackgroundTexture);
}

void Level::InitBrickMap()
{
	int count=0;
	double BrickW = BrickSoft->GetSpriteWidth();
	double BrickH= BrickSoft->GetSpriteHeight();
	//set positions
	for (unsigned int i = 0; i <= *RowCount; i++) {
		for (unsigned int j = 0; i <= *ColumnCount; j++) {
			const char brick = BricksMap[count];
			Vec2 BrickPos;
			BrickPos.x = 20 + *RowSpacing * i+BrickW*count;
			BrickPos.y = 20 + *ColumnSpacing * j+BrickH*count;

			switch (brick) {
				case 'S':
					BrickSoft->SetPos(BrickPos);
					bricks[count] = BrickSoft;
					break;
				case 'M':
					BrickMedium->SetPos(BrickPos);
					bricks[count] = BrickMedium;
					break;
				case 'H':
					BrickHard->SetPos(BrickPos);
					bricks[count] = BrickHard;
					break;
				case 'I':
					BrickImpenetrable->SetPos(BrickPos);
					bricks[count] = BrickSoft;
					break;				
		    }	
			count++;
		}

	}
}

void Level::DrawBrickMap()
{
	for (auto brick : bricks)
		al_draw_bitmap(brick->GetSprite(), brick->GetPos().x, brick->GetPos().y, 0);
}



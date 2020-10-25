#include "Level.h"



ALLEGRO_BITMAP* Level::SetLevelBackground()
{
	return al_load_bitmap(BackgroundTexture);
}

void Level::InitBrickMap(Level *level)
{
	const unsigned int *RowCountt = new const unsigned int(*level->RowCount);
	int count=0;
	double BrickW = BrickSoft->GetSpriteWidth();
	double BrickH= BrickSoft->GetSpriteHeight();
	//set positions
	for (unsigned int i = 0; i <= *RowCount; i++) {
		for (unsigned int j = 0; j <= *ColumnCount; j++) {
			const char brick = BricksMap[count];
			Vec2 BrickPos;
			BrickPos.x = 20 + *RowSpacing * i+BrickW*count;
			BrickPos.y = 20 + *ColumnSpacing * j+BrickH*count;

			switch (brick) {
				case 'S':
					BrickSoft->SetPos(BrickPos);
					bricks[count] = BrickSoft;
					count++;
					break;
				case 'M':
					BrickMedium->SetPos(BrickPos);
					bricks[count] = BrickMedium;
					count++;
					break;
				case 'H':
					BrickHard->SetPos(BrickPos);
					bricks[count] = BrickHard;
					count++;
					break;
				case 'I':
					BrickImpenetrable->SetPos(BrickPos);
					bricks[count] = BrickSoft;
					count++;
					break;	
				

		    }	

			
		}

	}
}

void Level::DrawBrickMap()
{
	for (auto brick : bricks)
		al_draw_bitmap(brick->GetSprite(), brick->GetPos().x, brick->GetPos().y, 0);
}



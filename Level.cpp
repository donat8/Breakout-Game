#include "Level.h"



ALLEGRO_BITMAP* Level::SetLevelBackground()
{
	return al_load_bitmap(BackgroundTexture);
}

void Level::InitBrickMap(Level *level)
{
	const unsigned int *RowCountt = new const unsigned int(*level->RowCount);
	int countBricksMap=0;
	int count = 0;
	double BrickW = BrickSoft->GetSpriteWidth();
	double BrickH= BrickSoft->GetSpriteHeight();
	//set positions
	for (unsigned int i = 0; i < *RowCount; i++) {
		for (unsigned int j = 0; j < *ColumnCount; j++) {
		
			const char brick = BricksMap[countBricksMap];
			Vec2 BrickPos;

			BrickPos.x = 45 + *ColumnSpacing * j + BrickW * j;
			BrickPos.y = 54 + *RowSpacing * i + BrickH * i;
			switch (brick) {
				case 'S':
				{Brick* newBrick = new Brick(*BrickSoft);
				newBrick->SetPos(BrickPos);
				newBrick->SetBrickRect();
				bricks[count] = newBrick; }
					count++;
					break;
				case 'M':
				{Brick* newBrick = new Brick(*BrickMedium);
				newBrick->SetPos(BrickPos);
				newBrick->SetBrickRect();
				bricks[count] = newBrick; }
					count++;
					break;
				case 'H':
				{Brick* newBrick = new Brick(*BrickHard);
				newBrick->SetPos(BrickPos);
				newBrick->SetBrickRect();
				bricks[count] = newBrick; }
					count++;
					break;
				case 'I':
				{Brick* newBrick = new Brick(*BrickImpenetrable);
				newBrick->SetPos(BrickPos);
				newBrick->SetBrickRect();
				bricks[count] = newBrick; }
					count++;
					break;	
				default:
					j -= 1;
		    }	
			countBricksMap++;	
		}
	}
}

void Level::DrawBrickMap()
{	
	for (auto brick : bricks)
		brick->DrawBrick();
}

unsigned int Level::CheckBrickBallCollision(Ball& ball)
{
	unsigned int addScore=0;

	Vec2 centerOfBall=ball.GetCenterOfBall();

	for (auto brick : bricks) {
		Vec2 centerOfBrick = brick->GetCenter();
		if((centerOfBrick-centerOfBall).GetLength()>1.5+brick->GetSpriteWidth()||
			(centerOfBrick - centerOfBall).GetLength() >1.5+brick->GetSpriteHeight() )
			addScore+=brick->ExecuteBallCollision(ball);
	}
	return addScore;
}



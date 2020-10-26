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

			BrickPos.x = 20 + *ColumnSpacing * j + BrickW * j;
			BrickPos.y = 20 + *RowSpacing * i + BrickH * i;
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

void Level::CheckBrickBallCollision(Ball& ball)
{
	//bool collision = false;
	//int index;
	//float BallToBrickDistSq1;

	//for (int i = 0; i < 30; i++) {
	//	if (bricks[i]->CheckBallCollision(ball)) {
	//		if (bricks[i - 1]->CheckBallCollision(ball)) {
	//			const float distance1 = (ball.GetCenterOfBall() - bricks[i - 1]->GetCenter()).GetLengthSq();
	//			const float distance2 = (bricks[i]->GetCenter() - ball.GetCenterOfBall()).GetLengthSq();
	//			if (distance1 < distance2)
	//				bricks[i - 1]->ExecuteBallCollision(ball);
	//			else
	//				bricks[i]->ExecuteBallCollision(ball);
	//		}
	//		else
	//			bricks[i]->ExecuteBallCollision(ball);	
	//	}
	//}
	

	for (auto brick : bricks) {
		brick->ExecuteBallCollision(ball);
	}
}



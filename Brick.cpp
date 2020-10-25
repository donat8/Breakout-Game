#include "Brick.h"


Brick::Brick(const char* Id, const char* Texture, const unsigned int* HitPoints, const char* HitSound,
	const char* BreakSound, unsigned int* BreakScore)
	:Sprite(), Id(Id), HitPoints(*HitPoints), HitSound(HitSound), BreakSound(BreakSound),BreakScore(*BreakScore)
{
	Id = Id;
	SetSprite(Texture);
	HitPoints = HitPoints;
	HitSound = HitSound; 
	BreakSound = BreakSound;
	BreakScore = BreakScore;
	destroyed = false;

}

void Brick::DrawBrick()
{
	if(!destroyed)
		al_draw_bitmap(GetSprite(), pos.x, pos.y, 0);
}

Rect Brick::GetBrickRect() const
{
	return GetSpriteRect();
}

void Brick::SetBrickRect() 
{
	rect = GetSpriteRect();
}

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !destroyed && rect.IsOverlappingWith(ball.GetBallRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	
	

	if(CheckBallCollision(ball)){
		assert(CheckBallCollision(ball));
	const Vec2 ballPos = ball.GetPos();
	//signbit -if float is neg
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x)) {
		ball.InvertY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right) {
		ball.InvertY();
	}
	else {
		ball.InvertX();
	}
	destroyed = true;
	}
	
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}




#include "Brick.h"



Brick::Brick(float posX,float posY, const char* texture):Sprite(posX,posY),
	destroyed(false)
{
	rect = Rect(posX, GetSpriteWidth(),posY, GetSpriteHeight());
	SetSprite(texture);
}

void Brick::DrawBrick()
{
	if(!destroyed)
		al_draw_bitmap(sprite, pos.x, pos.y, 0);
}

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !destroyed && rect.IsOverlappingWith(ball.GetBallRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
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

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}




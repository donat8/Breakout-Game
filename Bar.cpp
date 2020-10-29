#include "Bar.h"
#include <cmath>
#include <iostream>


Bar::Bar(float posX,float posY) :Sprite(posX, posY)
{
	SetSprite("Textures/Bar.dds");
	halfWidth = GetSpriteWidth() / 2;
}

Bar::~Bar()
{
}

void Bar::Draw() const
{
	al_draw_bitmap(sprite, pos.x, pos.y, 0);
}

bool Bar::BallCollision(Ball& ball, double BarXBefore)
{
	const Rect bar = GetBarRect();

	if (bar.IsOverlappingWith(ball.GetBallRect())==true)
	{
		const Vec2 ballPos = ball.GetPos();
		//if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x)
		//	|| (ballPos.x >= bar.left && ballPos.x <= bar.right)) {

		//	/*Vec2 dir;
		//	const float DiffOnXAxis = ballPos.x - pos.x;
		//	if (std::abs(xDifference) < fixedZoneHalfWidth)
		//	{
		//		if (xDifference < 0.0f)
		//		{
		//			dir = Vec2(-fixedZoneExitX, -1.0f);
		//		}
		//		else
		//		{
		//			dir = Vec2(fixedZoneExitX, -1.0f);
		//		}
		//	}
		//	else
		//	{
		//		dir = Vec2(xDifference * exitXFactor, -1.0f);
		//	}
		//	ball.SetDirection(dir);*/
		//}
		/*else
		{*/

		//fix pos of ball after collision to avoid double coll

		float AfterBefore = GetBarRect().left - BarXBefore;

		Vec2 dir = Vec2(AfterBefore / 6, -1.0f);
		ball.SetDirection(dir);


		std::cout << AfterBefore << std::endl;
		//ball.InvertY();
		/*}*/

		return true;
	}
	return false;
}



void Bar::WallCollision(const Rect& walls)
{
	const Rect bar = GetBarRect();

	
	if (bar.left < walls.left)
		pos.x += walls.left - bar.left;
	else if (bar.right > walls.right)
		pos.x -= bar.right - walls.right;
}

void Bar::Update(const ALLEGRO_KEYBOARD_STATE key)
{
	if (al_key_down(&key, ALLEGRO_KEY_RIGHT))
		pos.x += speed*multiplier;
	if (al_key_down(&key, ALLEGRO_KEY_LEFT))
		pos.x -= speed * multiplier;
}


Rect Bar::GetBarRect() const
{
	return GetSpriteRect();
}

void Bar::ResetCooldown()
{
}


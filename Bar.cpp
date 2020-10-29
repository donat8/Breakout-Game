#include "Bar.h"
#include <cmath>
#include <iostream>


Bar::Bar(float posX,float posY) :Sprite(posX, posY)
{
	SetSprite("Textures/Bar.dds");
}

Bar::~Bar()
{
	al_destroy_bitmap(sprite);
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

		float AfterBefore = GetBarRect().left - BarXBefore;

		Vec2 dir = Vec2(AfterBefore / 6, -1.0f);
		ball.SetDirection(dir);	
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



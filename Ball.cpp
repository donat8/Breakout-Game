#include "Ball.h"


Ball::Ball(float posX, float posY, const Vec2& dir_in): Sprite(posX,posY)	
{
	SetSprite("Textures/Ball.dds");
	SetDirection(dir_in);
}

void Ball::Draw()
{
	al_draw_bitmap(sprite, pos.x,pos.y, 0);
}

void Ball::Update(float val)
{
	pos += vel * val;
}

Rect Ball::GetBallRect() const
{
	return GetSpriteRect();
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

Vec2 Ball::GetCenterOfBall() const
{
	return Vec2(GetSpriteWidth() / 2, GetSpriteHeight() / 2);
}


void Ball::InvertX(){
	vel.x = -vel.x;
}

void Ball::InvertY() {
	vel.y = -vel.y;
}

int Ball::BallToWallCollision(const Rect& walls)
{
	int collided = 0;
	Rect ball = GetSpriteRect();
	
	//collide with top 
	if (ball.left < walls.left|| ball.right>walls.right) {
		InvertX();
		collided = 1;
	}
	if (ball.top < walls.top) {
		InvertY();
	}
	return collided;
}

void Ball::SetDirection(const Vec2& dir)
{
	vel = dir.GetNormalized() * speed;
}
 


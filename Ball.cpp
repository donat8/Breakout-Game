#include "Ball.h"



Ball::Ball():Sprite(Const::BALL_INIT_X,Const::BALL_INIT_Y)
{
	SetSprite("Textures/Ball.dds");
}


void Ball::Update()
{
	al_draw_bitmap(sprite, Sprite::posX, Sprite::posY, 0);
}

void Ball::UpdateBeforeRelease() {
	al_draw_bitmap(sprite, Sprite::posX, Sprite::initposY, 0);
}

void Ball::onCollideWithWall()
{
	if (GetPosY() + GetAcceleration() + (GetSpriteHeight() / 2) < 0/*screen height*/) {
		this->Down();
	}
}

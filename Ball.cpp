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

void Ball::Reset()
{
	al_draw_bitmap(sprite, Sprite::initposX, Sprite::initposY, 0);
}



void Ball::InvertX(){

}

void Ball::InvertY() {

}



void Ball::onCollideWithWall()
{
	

	//collide with top 
	if (NextBallPosY < 0/*screen top */ ) {
		this->Down();
		Collided = true;
	}
	//collide with Left
	if (NextBallPosX < 0) {
		this->Right();
		Collided = true;
	}
	//collide with right
	if (NextBallPosX > Const::SCREEN_WIDTH){
		this->Left();
		Collided = true;
	}
}
 
void Ball::onCollideWithBar(Bar bar){
	double topy1=bar.GetPosY();
	double leftx1=bar.GetPosX();
	double rightx1=leftx1+bar.GetSpriteWidth();
	double boty1=topy1+bar.GetSpriteHeight();

	double topY2 = NextBallPosY;
	double leftX2 = NextBallPosX;
	double rightX2 = leftX2 + GetSpriteWidth();
	double botY2 = topY2 + GetSpriteHeight();

	if ((rightx1 < leftX2) || (leftx1 > rightX2))
		return false;
	if ((boty1 < topY2) || (topy1 > botY2))
		return false;
}


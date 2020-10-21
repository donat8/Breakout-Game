#include "Sprite.h"

Sprite::Sprite(const int& initposx, const int& initposy)
{
	this->initposX = initposx;
	this->initposY = initposy;
	this->posX = initposx;
}

Sprite::~Sprite()
{
	al_destroy_bitmap(sprite);
}

void Sprite::SetSprite(const char* path)
{ 
	al_destroy_bitmap(sprite);
	sprite = al_load_bitmap(path);
}

//hm
void Sprite::Update()
{
	////for ball
	//this->posX += Acceleration;
	//this->posY += Acceleration;

	//for bouncer
	
	al_draw_bitmap(sprite, posX, initposY, 0);
}

void Sprite::Move(float x)
{
	this->posX = x-GetSpriteWidth()/2;
}

void Sprite::DrawInit()
{
	al_draw_bitmap(sprite, initposX, initposY,0 );
}


ALLEGRO_BITMAP* Sprite::GetSprite()
{
	return this->sprite;
}

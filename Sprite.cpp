#include "Sprite.h"
#include <iostream>

Sprite::Sprite(float posX, float posY)
{
	/*pos =Vec2(posX, posY);*/
	pos.x = posX;
	pos.y = posY;
}

Sprite::~Sprite()
{
	al_destroy_bitmap(sprite);
}

void Sprite::SetSprite(const char* path)
{ 
	al_destroy_bitmap(sprite);
	
	sprite = al_load_bitmap(path);
	if (sprite == NULL) {
		std::cout << "Cannot load bitmap path:" << path << std::endl;
		exit(1);
	}

}

float Sprite::GetSpriteWidth() const 
{
	return al_get_bitmap_width(sprite); 
}

float Sprite::GetSpriteHeight() const 
{
	return al_get_bitmap_height(sprite); 
}

//hm
//void Sprite::Update()
//{
//
//	//for bouncer
//	
//	al_draw_bitmap(sprite, pos.x, initposY, 0);
//}

void Sprite::Move(float x)
{
	this->pos.x = x-GetSpriteWidth()/2;
}


ALLEGRO_BITMAP* Sprite::GetSprite()
{
	return this->sprite;
}

Rect Sprite::GetSpriteRect() const
{
	//std::cout << GetSpriteWidth() << std::endl;

	return Rect(pos,GetSpriteWidth(),GetSpriteHeight());
}

Vec2 Sprite::GetPos() {
	return this->pos;
}

void Sprite::SetPos(Vec2 new_pos)
{ 
	this->pos = new_pos; 
}
#include "Brick.h"


Brick::Brick():Sprite(x,y)
{
	SetSprite();
}

void Brick::DrawBrick()
{
	al_draw_bitmap(sprite, x, y, 0);
}

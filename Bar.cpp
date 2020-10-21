#include "Bar.h"
#include "Const.h"


Bar::Bar():Sprite(Const::BAR_INIT_X,Const::BAR_INIT_Y)
{
	SetSprite("Textures/Bar.dds");
}

Bar::~Bar()
{
}

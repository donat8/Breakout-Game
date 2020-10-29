#include "Rect.h"
#include <iostream>

Rect::Rect(float left_in, float right_in, float top_in, float bottom_in)
	:left(left_in),right(right_in),top(top_in),bottom(bottom_in)
{
}

Rect::Rect(const Vec2& topLeft, const Vec2& bottomRight)
	: Rect(topLeft.x,bottomRight.x,topLeft.y,bottomRight.y)
{
}

Rect::Rect(const Vec2& topLeft, float width, float height)
	:Rect(topLeft.x,topLeft.x+width,topLeft.y,topLeft.y+height)
{
}

bool Rect::IsOverlappingWith(const Rect& other) const
{
   	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;	
}


Vec2 Rect::GetCenter() const
{
	return Vec2((left+right)/2.0f,(top+bottom)/2.0f);
}

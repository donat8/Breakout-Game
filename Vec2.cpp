#include "Vec2.h"
#include <cmath>

Vec2::Vec2(float x, float y):x(x),y(y)
{
}

Vec2 Vec2::operator+(const Vec2& other) const
{
	return Vec2(x+other.x,y+other.y);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
	return *this = *this + other;
}

Vec2 Vec2::operator*(float other) const
{
	return Vec2(x*other,y*other);
}

Vec2& Vec2::operator*=(float other)
{
	return *this = *this * other;
}

Vec2 Vec2::operator-(const Vec2& other) const
{
	return Vec2(x - other.x, y - other.y);
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	return *this = *this - other;
}

float Vec2::GetLength() const
{
	return std::sqrt(GetLengthSq());
}

float Vec2::GetLengthSq() const
{
	return x*x+y*y;
}

Vec2& Vec2::Normalize()
{
	return *this = GetNormalized();
}

Vec2 Vec2::GetNormalized() const
{
	const float len = GetLength();
	if (len != 0.0f)
		return *this * (1.0f / len);

	return *this;
}

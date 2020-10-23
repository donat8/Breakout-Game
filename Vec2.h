#pragma once

class Vec2
{
public:
	Vec2() = default;

	Vec2(float x, float y);
	Vec2 operator+(const Vec2& other) const;
	Vec2& operator+=(const Vec2& other);
	Vec2 operator*(float other) const;
	Vec2& operator*=(float other);
	Vec2 operator-(const Vec2& other) const;
	Vec2& operator-=(const Vec2& other);
	float GetLength() const;
	float GetLengthSq() const;
	Vec2& Normalize();
	Vec2 GetNormalized() const;

public:
	float x;
	float y;
};


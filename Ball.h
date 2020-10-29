#pragma once

#include "Consts.h"
#include "Rect.h"
#include "Vec2.h"
#include "Sprite.h"

class Ball : public Sprite{
public:
	Ball()=default;
	Ball(float posX,float posY,const Vec2& dir_in);

	void Draw();

	//change pos
	void Update(float val);

	Rect GetBallRect() const;

	Vec2 GetVelocity() const;

	Vec2 GetCenterOfBall() const;

	//invert axis of ball when it collides
	void InvertX();
	void InvertY();

	int BallToWallCollision(const Rect& walls);

	void SetDirection(const Vec2& dir);

private:

	float speed = 4.0f;
	Vec2 vel;
};


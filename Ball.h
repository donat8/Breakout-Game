#pragma once

#include "Consts.h"
#include "Bar.h"
#include "Vec2.h"

class Ball : public Sprite{
public:
	Ball()=default;
	Ball(float posX,float posY,const Vec2& dir_in);
	~Ball();

	void Draw();

	//change pos
	void Update(float val);

	void UpdateBeforeRelease();

	void ResetBall();

	Rect GetBallRect() const;

	Vec2 GetVelocity() const;

	Vec2 GetCenterOfBall() const;

	//invert axis of ball when it collides
	void InvertX();
	void InvertY();
	//0 - ne collidea, 1- collidea, 2- collidea sa podom
	int onCollideWithWall(const Rect& walls);

	void SetDirection(const Vec2& dir);

private:

	float speed = 4.0f;
	Vec2 vel;
};


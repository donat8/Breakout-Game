#pragma once
#include "Sprite.h"
#include "Ball.h"
#include "Consts.h"
#include "Vec2.h"



class Bar : public Sprite
{
public:
    Bar(float posX,float posY);
    ~Bar();

    void Draw() const;

    bool BallCollision(Ball& ball, double BarXBefore);

    void WallCollision(const Rect& walls);

    void Update(const ALLEGRO_KEYBOARD_STATE key);

    Rect GetBarRect() const;

private:

    const float speed = 2.0f;
    float multiplier = 3.0f;
 




};


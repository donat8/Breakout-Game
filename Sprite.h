#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Rect.h"

class Sprite {

public:
	Sprite() = default;
	Sprite(float posX,float posY);
	~Sprite();

	/*virtual void Reset();*/
	ALLEGRO_BITMAP* sprite = NULL;
	void SetSprite(const char* path);

	ALLEGRO_BITMAP* GetSprite();
	float GetSpriteWidth() const;
	float GetSpriteHeight() const;
	Rect GetSpriteRect() const;
	

	Vec2 GetPos();
	void SetPos(Vec2 new_pos);

	//for moving with the mouse
	virtual void Move(float x);

	void DrawInit();

	//virtual void Update();

	/*int GetAcceleration() { return this->Acceleration; };*/

	/*void Up() { posY -= Acceleration/10000000;	};
	void Down() { posY += Acceleration/ 10000000; };*/

	//void Left() {
	//	posX -= Acceleration;
	///*	Acceleration += Acceleration / 3;
	//	if (Acceleration > 20) {
	//		Acceleration = 20;
	//	}*/
	//};

	//void Right() { posX += Acceleration; 
	//	/*Acceleration += Acceleration / 3;
	//	if (Acceleration > 20) {
	//		Acceleration = 20;
	//	}*/
	//};

	//void RestartAcceleration() { Acceleration = initAcceleration; };



protected:
	Vec2 pos;

	//initial position and acceleration
	int initposX = 0;
	int initposY = 0;


};

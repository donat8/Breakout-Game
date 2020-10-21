#pragma once
#include <allegro5/allegro.h>
#include<allegro5/allegro_image.h>

class Sprite {

public:
	Sprite(const int& initposx,const int& initposy);
	~Sprite();

	/*virtual void Reset();*/
	ALLEGRO_BITMAP* sprite = NULL;
	void SetSprite(const char* path);
	ALLEGRO_BITMAP* GetSprite();
	int GetSpriteWidth() { return al_get_bitmap_width(sprite); };
	int GetSpriteHeight() { return al_get_bitmap_height(sprite); };

	int GetPosX() { return this->posX; };
	int GetPosY() { return this->posY; };

	//for moving with the mouse
	virtual void Move(float x);

	void DrawInit();

	virtual void Update();

	int GetAcceleration() { return this->Acceleration; };

	void Up() { posY -= Acceleration/10000000;	};
	void Down() { posY += Acceleration/ 10000000; };

	void Left() {
		posX -= Acceleration;
	/*	Acceleration += Acceleration / 3;
		if (Acceleration > 20) {
			Acceleration = 20;
		}*/
	};

	void Right() { posX += Acceleration; 
		/*Acceleration += Acceleration / 3;
		if (Acceleration > 20) {
			Acceleration = 20;
		}*/
	};

	void RestartAcceleration() { Acceleration = initAcceleration; };



	void GetTop();
	void GetBottom();
	void GetRight();
	void GetLeft();

	bool Collided = false;

protected:
	float posX, posY = 0;
	float Acceleration = 1;

	//initial position and acceleration
	int initposX = 0;
	int initposY = 0;
	int initAcceleration = 1;


private:
	



	




	


};

#pragma once

#include <stdio.h>
#include <iostream>

#include "Sprite.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "TimerFps.h"
#include "Ball.h"
#include "Bar.h"
#include "Level.h"
#include "XMLParser.h"

enum ballState {
	ball_stationary,
	ball_released,
	ball_freely_moving
};


class Game {
public:
	Game();
	~Game();

	void init(int width, int height);

	void handleEvents();
	void Update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	int cnt;
	bool isRunning;

	ALLEGRO_DISPLAY *window;
	ALLEGRO_FONT* font;

	Rect walls;
	Bar *bar;
	Ball* ball;

	double BarXBefore=0;

	char ballState=ball_stationary;
	
	ALLEGRO_EVENT event;
	ALLEGRO_EVENT_QUEUE* queue;

	Level *Level1;
	Level *Level2;
	Level *Level3;

	ALLEGRO_BITMAP *background;

	XMLParser *parser=new XMLParser("Levels/Level1.xml");


	bool mouseFlag = false;
	bool ballFlag = false;

	ALLEGRO_KEYBOARD_STATE keyState;

	TimerFps *timer; 

};
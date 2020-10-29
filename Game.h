#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "Sprite.h"

#include "TimerFps.h"
#include "Ball.h"
#include "Bar.h"
#include "Level.h"
#include "XMLParser.h"
#include "Player.h"

enum ballState {
	ball_stationary,
	ball_released,
	ball_freely_moving
};

enum state{START,GAME_ACTIVE,GAMEOVER,GAMEWON};


class Game {
public:
	Game(int width, int height);
	~Game();

	void init();

	void handleEvents();
	void Update();
	void render();

	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning;

	ALLEGRO_DISPLAY *window;
	ALLEGRO_FONT* font;
	//mebe define somewhere else
	ALLEGRO_COLOR col;

	Rect walls;
	Bar *bar;
	Ball* ball;

	double BarXBefore=0;

	int ballState=ball_stationary;
	int state=START;
	
	ALLEGRO_EVENT event;
	ALLEGRO_EVENT_QUEUE* queue;

	std::vector<Level> Levels;
	unsigned int Level_no;

	/*Level *Level1=new Level();*/
	//Level *Level2;
	//Level *Level3;

	int Scene = 0;

	Player* player;



	XMLParser *parser=new XMLParser();

	bool mouseFlag = false;
	bool ballFlag = false;

	ALLEGRO_KEYBOARD_STATE keyState;

	TimerFps *timer; 

	ALLEGRO_BITMAP *bg;
};
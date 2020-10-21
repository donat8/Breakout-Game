#include "Game.h"



Game::Game() {}

Game::~Game() {}



void Game::init(int width, int height) 
{
	al_init();

	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	

	al_install_keyboard();
	al_install_mouse();

	al_init();

	window = al_create_display(width, height);

	queue = al_create_event_queue();

	timer = new TimerFps(60);
	timer->startTimer();

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(window));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer->getTimer()));
	
	
	//int flags = 0; 
	//if (fullscreen)
	//	flags = SDL_WINDOW_FULLSCREEN;
	
	
	isRunning = true;
	font = al_load_ttf_font("Font/zig_____.ttf", 64, 0);
	
	Bouncer = new Sprite(Const::BAR_INIT_X,Const::BAR_INIT_Y);
	Bouncer->SetSprite("Textures/Bar.dds");

	al_destroy_bitmap(background);
	background = al_load_bitmap("Textures/Boards/Board_01.dds");

	ball = new Ball();
	
}

void Game::handleEvents() {
		
	al_get_keyboard_state(&keyState);
	
	if (!al_is_event_queue_empty(queue)) {

		al_wait_for_event(queue, &event);
		//x closes the window, esc doesn't still do anything (maybe revert to menu)
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
			isRunning = false;

		//on mouse click can use mouse for moving the Bouncer
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			mouseFlag = true;
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES && mouseFlag == true) {
			Bouncer->Move(event.mouse.x);
			ball->Move(event.mouse.x);
		}

		if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
			Bouncer->Right();
			ball->Right();

		}
		if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
			Bouncer->Left();
			ball->Left();
		}
		//CAP @60fps or more
		if (event.type == ALLEGRO_EVENT_TIMER)
			al_flip_display();
	
		//on SPACE key start the ball
		if (event.type == ALLEGRO_KEY_SPACE)
			ballFlag = true;
		if (ballFlag == true) {
			ball->Up();
			ball->Update();
		}
	/*	else
			
		ball->UpdateBeforeRelease();*/
	}
}



void Game::Update() {

	al_draw_bitmap(background,0,0,0);
	Bouncer->Update();

	ball->UpdateBeforeRelease();
	//ball->Update();

	
}

void Game::render() 
{

}

void Game::clean() {

	al_destroy_timer(timer->getTimer());
	al_destroy_display(window);
	al_destroy_font(font);

	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_destroy_bitmap(background);
	std::cout << "Game cleansed" << std::endl;

}
	





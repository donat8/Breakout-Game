#include "Game.h"




Game::Game() 
{
	
	parser->LoadXMLFile("Levels/Level1.xml");
	parser->ReadXMLFile(*Level1);

	font = al_load_ttf_font("Font/zig_____.ttf", 32, 0);

	Vec2 direction;
	direction.x = 0;
	direction.y = -1;

	walls = Rect(0, Consts::SCREEN_WIDTH, 0.0f, Consts::SCREEN_HEIGHT);
	bar = new Bar(Consts::BAR_INIT_X, Consts::BAR_INIT_Y);
	ball = new Ball(Consts::BALL_INIT_X, Consts::BALL_INIT_Y, direction);

	//create queue for events
	queue = al_create_event_queue();


	
	//Level2 = new Level("Levels/Level2.txt");
	//Level3 = new Level("Levels/Level3.txt");

	al_destroy_bitmap(background);
	background = al_load_bitmap("Textures/Boards/Board_01.dds");

	//timer
	timer = new TimerFps(60);

	isRunning = true;
}

Game::~Game() {}

//todo: fullscreen

void Game::init(int width, int height) 
{
	ObjecInit_Ex::InitObject(al_init(),"Allegro");
	ObjecInit_Ex::InitObject(al_init_font_addon(),"Font addon");
	ObjecInit_Ex::InitObject(al_init_ttf_addon(),"Font TTF Addon");
	ObjecInit_Ex::InitObject(al_init_image_addon(),"Image addon");
	
	//mouse and keyboard
	ObjecInit_Ex::InitObject(al_install_keyboard(),"Keyboard");
	ObjecInit_Ex::InitObject(al_install_mouse(),"Mouse");

	//create display
	window = al_create_display(width, height);


	//register events
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(window));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer->getTimer()));
	
	

	timer->startTimer();
}

void Game::handleEvents() {

	BarXBefore = bar->GetPos().x;

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
			{
		    	bar->Move(event.mouse.x);
		    	BarXBefore = bar->GetPos().x;
			}
			 if (ballState == ball_stationary)
			   	ball->Move(event.mouse.x);
		}
		Vec2 ballStatPos = Vec2(bar->GetPos().x+bar->GetSpriteWidth()/2-ball->GetSpriteWidth()/2, bar->GetPos().y-bar->GetSpriteHeight()/2-5);

		/*CAP @60fps or more*/
		if (event.type == ALLEGRO_EVENT_TIMER) {
			bar->Update(keyState);
			switch (ballState) {
			case ball_stationary:
				ball->SetPos(ballStatPos);
				ball->Update(0);
				if (al_key_down(&keyState, ALLEGRO_KEY_SPACE))
					ballState = ball_released;
				break;
			case ball_released:
				ball->Update(1);
				ball->BallToWallCollision(walls);
				bar->BallCollision(*ball, BarXBefore);

				ball->Update(1);
				break;
			}		
		}
	}
}



void Game::Update() {

	
	

	


	
}

void Game::render() 
{
	
	if (event.type == ALLEGRO_EVENT_TIMER) {
	
		al_draw_bitmap(background, 0, 0, 0);
		bar->WallCollision(walls);
		
	
		bar->Draw();
		ball->Draw();
		
		al_flip_display();
		
	}
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
	





#include "Game.h"
#include <Windows.h>
Game::Game(int width, int height)
{
	ObjecInit_Ex::InitObject(al_init(), "Allegro");
	ObjecInit_Ex::InitObject(al_init_font_addon(), "Font addon");
	ObjecInit_Ex::InitObject(al_init_ttf_addon(), "Font TTF Addon");
	ObjecInit_Ex::InitObject(al_init_image_addon(), "Image addon");
	ObjecInit_Ex::InitObject(al_init_acodec_addon(), "Codec addon");

	//mouse and keyboard
	ObjecInit_Ex::InitObject(al_install_keyboard(), "Keyboard");
	ObjecInit_Ex::InitObject(al_install_mouse(), "Mouse");
	ObjecInit_Ex::InitObject(al_install_audio(), "Audio");

	//for audio
	al_reserve_samples(1);

	//font and color
	font = al_load_ttf_font("Font/zig_____.ttf", 20, 0);
	col = al_map_rgba(255, 255, 255, 1);

	//init of ball, wall, and bar
	walls = Rect(0, Consts::SCREEN_WIDTH, 0.0f, Consts::SCREEN_HEIGHT);
	bar = new Bar(Consts::BAR_INIT_X, Consts::BAR_INIT_Y);
	ball = new Ball(Consts::BALL_INIT_X, Consts::BALL_INIT_Y, Vec2(0,-1));

	//create queue for events
	queue = al_create_event_queue();

	//timer init
	timer = new TimerFps(60);
	//player init
	player = new Player();

	window = al_create_display(width, height);

	isRunning = true;
}

Game::~Game() {}


void Game::init() 
{

	Level* Level1 = new Level();
	Level* Level2 = new Level();;
	Level* Level3 = new Level();

	this->Levels.push_back(*Level1);
	this->Levels.push_back(*Level2);
	this->Levels.push_back(*Level3);
	this->Level_no = 0;

	//register events
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(window));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer->getTimer()));

	timer->startTimer();
}

void Game::handleEvents() {

	al_get_keyboard_state(&keyState);

	if (!al_is_event_queue_empty(queue)) {
		al_wait_for_event(queue, &event);
		//for exiting the screen
    	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
    		isRunning = false;

		switch (state) {
		    case GAME_ACTIVE: {
		    	//on mouse click can use mouse for moving the bar
		     	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		     		mouseFlag = true;
		     	}
		     	//moves the bar and ball with mouse
		     	if (event.type == ALLEGRO_EVENT_MOUSE_AXES && mouseFlag == true) {
		     		bar->Move(event.mouse.x);
		     		if (ballState == ball_stationary)
		     			ball->Move(event.mouse.x);
		     	}
		     	Vec2 ballStatPos = Vec2(bar->GetPos().x + bar->GetSpriteWidth() / 2 - ball->GetSpriteWidth() / 2, bar->GetPos().y - bar->GetSpriteHeight() / 2 - 5);
		     	if (event.type == ALLEGRO_EVENT_TIMER) {
		     
		     		bar->Update(keyState);
		     
		     		switch (ballState) {
		     		    case ball_stationary:{
		     		    	ball->SetPos(ballStatPos);
		     		    	ball->Update(0);
		     		    	if (al_key_down(&keyState, ALLEGRO_KEY_SPACE))
		     		    		ballState = ball_released;
		     		    	break;
		     		    }
		     		    case ball_released:{
		    			    ball->BallToWallCollision(walls);
		    			    ball->Update(1.5f);
		    			    bar->BallCollision(*ball, BarXBefore);
		    			    player->AddPlayerScore(this->Levels[this->Level_no].CheckBrickBallCollision(*ball));
		    			    if (ball->GetPos().y >= Consts::SCREEN_HEIGHT-30) {
		    			    	player->RemoveOneBall();
			 				ballState = ball_stationary;
		    			    }
			 			if (player->GetRemainingBalls() == 0) {
			 				state = GAMEOVER;
			 			}
		    			    break;
		    		    }
		         	}
		      	}	
				if (player->GetPlayerScore() == 14250) {
					state = GAMEWON;
					break;
				}
				if (player->GetPlayerScore() == maxScoreLvl1) {
					IsLoaded = false;
					maxScoreLvl1 += maxScoreLvl1+450;
					state = LOAD_LEVEL;	
				}
		    	break;
		    }
		    case GAMEOVER: {
		    	 if (event.type == ALLEGRO_KEY_DOWN || event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
		    		 ballState = ball_stationary;
		  	       	 player->ResetBalls();
		  	       	 player->ResetPlayerScore();
		  	       	 this->Levels[0].InitBrickMap(&Levels[0]);
		    		 //restart level!
		    		 state = START;
		    	 }
		    	 break;
		    }
	    	case GAMEWON:
		   		 if (event.type == ALLEGRO_KEY_DOWN || event.keyboard.keycode == ALLEGRO_KEY_ENTER){
		   			 ballState = ball_stationary;
					 player->ResetBalls();
					 player->ResetPlayerScore();
		   			 state = START;
		   		 }
		   		 break;
		   	 case START:
		   		 if (event.type == ALLEGRO_KEY_DOWN || event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
					 maxScoreLvl1 = 4350;
		   			 this->Level_no = 0;
		   			 state = GAME_ACTIVE;
					 parser->LoadXMLFile("Levels/Level1.xml");
					 parser->ReadXMLFile(&Levels[0]);
					 Levels[0].InitBrickMap(&Levels[0]);
					 bg = al_load_bitmap(Levels[0].BackgroundTexture);
		   		 }
		   		 break;
			 case LOAD_LEVEL:
				 if (event.type == ALLEGRO_KEY_DOWN || event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
					 if (!IsLoaded) {
					     Level_no++;
					     if (Level_no == 1)
					    	 parser->LoadXMLFile("Levels/Level2.xml");
					     if (Level_no == 2)
					    	 parser->LoadXMLFile("Levels/Level3.xml");
					     parser->ReadXMLFile(&Levels[Level_no]);
					     Levels[Level_no].InitBrickMap(&Levels[Level_no]);
					     al_destroy_bitmap(bg);
					     bg = al_load_bitmap(Levels[Level_no].BackgroundTexture);
					     ballState = ball_stationary;
					     IsLoaded == true;
					     state = GAME_ACTIVE;
					 }
				 }
				 break;
	    }
    }		
}


void Game::draw() 
{
	switch (state) {
    	case GAME_ACTIVE: {
    		if (event.type == ALLEGRO_EVENT_TIMER) {
    			BarXBefore = bar->GetPos().x;
    			al_draw_bitmap(bg, 0, 0, 0);
    			bar->WallCollision(walls);
    			if (ballState == ball_stationary)
    				al_draw_text(font, col, 230, 550, NULL, Consts::SPACE_TO_RELEASE);
    			bar->Draw();
    			if (!mouseFlag)
    				al_draw_text(font, col, 185, 575, NULL, Consts::MOVE_THE_MOUSE);
    			ball->Draw();
    			this->Levels[this->Level_no].DrawBrickMap();
    			player->DrawHearts();
    			player->DrawPlayerScore();
    		}
    		break;
    	}
	    case GAMEOVER:
	    	al_draw_text(font, col, 200, 200, NULL, Consts::GAME_OVER);
	    	al_draw_text(font, col, 200, 250, NULL, Consts::ENTER_RESTART);
			break;
	    case GAMEWON: 
	    	al_draw_text(font, col, 200, 200, NULL, Consts::CONGRATULATIONS);
	    	al_draw_text(font, col, 200, 250, NULL, Consts::YOU_WON);
	    	al_draw_text(font, col, 200, 270, NULL, Consts::ENTER_RESTART);
			break;
	    
	    case START:
	    	al_draw_text(font, col, 200, 200, NULL, "Hey!");
	    	al_draw_text(font, col, 200, 240, NULL,Consts::ENTER_START);
			break;
		case LOAD_LEVEL:
			al_draw_text(font, col, 200, 200, NULL, Consts::LOADING);
			al_draw_text(font, col, 200, 240, NULL, Consts::ENTER_CONTINUE);
			break;
	}
	al_flip_display();

}

void Game::clean() {

	al_destroy_timer(timer->getTimer());
	al_destroy_display(window);
	al_destroy_font(font);
	al_destroy_bitmap(bg);
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_uninstall_audio();

	std::cout << "Game cleansed" << std::endl;

}
	





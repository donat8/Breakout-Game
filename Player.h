#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>


class Player {
public:
	Player();

	unsigned int GetRemainingBalls();
	void AddPlayerScore(const unsigned int &points);
	void DrawPlayerScore();
	void DrawHearts();
	void RemoveOneBall();
	unsigned int GetPlayerScore();

	//kod new game-a
	void ResetBalls();

	//kod gubljenja života
	void ResetPlayerScore();

private:
	unsigned int PlayerScore = 0;
	unsigned int RemainingBalls = 3;
	ALLEGRO_BITMAP* heartFull;
	ALLEGRO_BITMAP* heartEmpty;
	ALLEGRO_FONT* font;
	ALLEGRO_COLOR color;



};
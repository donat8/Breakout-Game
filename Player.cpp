#include "Player.h"

Player::Player()
{
	heartFull = al_load_bitmap("Textures/Heart_full.dds");
	heartEmpty = al_load_bitmap("Textures/Heart_empty.dds");
	font = al_load_ttf_font("Font/zig_____.ttf", 20, 0);
	color = al_map_rgb(255,255,255);
}

unsigned int Player::GetRemainingBalls()
{
	return this->RemainingBalls;
}

void Player::AddPlayerScore(const unsigned int& points)
{
	PlayerScore += points;
}

void Player::DrawPlayerScore() {
	

	al_draw_textf(font, color,18, 20, NULL,"SCORE: %d",PlayerScore );
}

void Player::DrawHearts()
{
	if (RemainingBalls == 1) {
		al_draw_bitmap(heartFull, 680, 10, 0);
		al_draw_bitmap(heartEmpty, 715, 10, 0);
		al_draw_bitmap(heartEmpty, 750, 10, 0);
	}
	if (RemainingBalls == 2) {
		al_draw_bitmap(heartFull, 680, 10, 0);
		al_draw_bitmap(heartFull, 715, 10, 0);
		al_draw_bitmap(heartEmpty, 750, 10, 0);
	}

	if (RemainingBalls == 3) {
		al_draw_bitmap(heartFull, 680, 10, 0);
		al_draw_bitmap(heartFull, 715, 10, 0);
		al_draw_bitmap(heartFull, 750, 10, 0);
	}
}

void Player::RemoveOneBall()
{
	RemainingBalls--;
}

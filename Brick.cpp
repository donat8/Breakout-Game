#include "Brick.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>



Brick::Brick(const char* Id, const char* Texture, const unsigned int* HitPoints, const char* HitSound,
	const char* BreakSound, unsigned int* BreakScore)
	:Sprite(), Id(Id), HitPoints(*HitPoints), HitSound(HitSound), BreakSound(BreakSound),BreakScore(*BreakScore)
{
	this->rect = Rect();
	SetSprite(Texture);
	destroyed = false;
	this->Texture = Texture;
}

void Brick::DrawBrick()
{
	if(!destroyed)
		al_draw_bitmap(GetSprite(), pos.x, pos.y, 0);
}


Rect Brick::GetBrickRect() const
{
	return GetSpriteRect();
}

void Brick::SetBrickRect() 
{
	rect = GetSpriteRect();
}

bool Brick::CheckBallCollision(Ball& ball) const
{
	const Vec2 ballPos = ball.GetPos();
	const Vec2* newBallPosx = new Vec2(ballPos.x + ball.GetVelocity().x, ballPos.y + ball.GetVelocity().y);
	const Vec2* newBallPosy = new Vec2(newBallPosx->x + ball.GetSpriteWidth(), newBallPosx->y + ball.GetSpriteHeight());
	Rect newBallRect = Rect(*newBallPosx,*newBallPosy );

	return !destroyed && rect.IsOverlappingWith(newBallRect);

}

unsigned int Brick::ExecuteBallCollision(Ball& ball)
{	
	if(CheckBallCollision(ball)){

	    assert(CheckBallCollision(ball));
		const Vec2 ballPos = ball.GetPos();
		

	    //signbit -if float is neg
	    if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x)) {
			ball.InvertY();
	    }
	    else if (ballPos.x >= rect.left && ballPos.x <= rect.right) {
	    	ball.InvertY();
	    }
	    else {
	    	ball.InvertX();
	    }
	    HitPoints--;
		ALLEGRO_SAMPLE* sample=NULL;

		unsigned int addTheScore = 0;

		sample = al_load_sample(HitSound);
		if (!sample)
			std::cout << "didnt load HitSound" << std::endl;
		al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

		if (HitPoints == 0) {
			destroyed = true;
			sample = al_load_sample(BreakSound);
			al_play_sample(sample, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			addTheScore += BreakScore;
		}		
		return addTheScore;
    }	
	return 0;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}




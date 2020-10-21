#include "TimerFps.h"

TimerFps::TimerFps(const int& fps)
{
	this->timer = al_create_timer(1.0/fps);
	ObjecInit_Ex::InitObject(this->timer, "timer");
}

void TimerFps::startTimer()
{
	al_start_timer(this->timer);
}

ALLEGRO_TIMER* TimerFps::getTimer() const
{
	return this->timer;
}

TimerFps::~TimerFps()
{
}
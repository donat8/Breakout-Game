#pragma once
#include <allegro5/allegro5.h>
#include "ObjectInit_Ex.h"


class TimerFps {
public:
	TimerFps(const int& fps);
	~TimerFps();

	void startTimer();

	ALLEGRO_TIMER* getTimer() const;

private:

	ALLEGRO_TIMER* timer = nullptr;
};

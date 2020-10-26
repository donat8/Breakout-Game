#pragma once

class Player {
public:
	Player();
	~Player();

	unsigned int GetRemainingBalls() { return RemainingBalls; }	
	void AddPlayerScore(const unsigned int &points);
	bool RemoveRemainingBall();

	//kod new game-a
	void Reset();

	//kod gubljenja života
	void ResetPosition();

private:
	unsigned int PlayerScore = 0;
	unsigned int RemainingBalls = 0;



};
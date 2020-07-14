#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

#include "entity.h"
#include "ground.h"


class Player : public Entity {
public:	
	Player(float p_x, float p_y, std::vector<SDL_Texture*> p_tex);
	float distanceFromCursor();
	bool jump();
	void update(Ground& ground);
	const char* getScore();
	const char* getHighscore();
	int getScoreInt();
	int isDead();
	void reset();
private:
	float velocityX, velocityY;
	bool grounded;
	void animEyes();
	float clamp(float p_value, float p_min, float p_max);
	int score = 0;
	int highscore = 0;
	int timer = 0;
	int dead = 0;
};
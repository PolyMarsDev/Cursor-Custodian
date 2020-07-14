#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "groundtile.h"
class Ground {
public:
	Ground(SDL_Texture* left, SDL_Texture* center, SDL_Texture* right, SDL_Texture* hole);
	GroundTile& getTile(int p_index);
	int getStatus(int p_index);
	int getLength();
	bool isTileBelow(float x, int width);
	void update(int score);
	void reset();
private:
	std::vector<GroundTile> groundTiles;
	SDL_Texture* groundTex[4];
	int lastStatus = 1;
	int holeCount = 0;
};
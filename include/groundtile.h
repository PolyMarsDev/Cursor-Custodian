#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "entity.h"

class GroundTile : public Entity
{
public:
	GroundTile(SDL_Texture* p_tex, int p_index);
	int getStatus();
	void setStatus(int p_status, SDL_Texture* groundTex[4]);
private:
	int status;
};
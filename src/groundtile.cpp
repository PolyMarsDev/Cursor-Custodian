#include "groundtile.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;

GroundTile::GroundTile(SDL_Texture* p_tex, int p_index)
	: Entity{p_index * 64.0f, SCREEN_HEIGHT - 64.0f, p_tex}
{
	status = 1;
}

int GroundTile::getStatus()
{
	return status;
}

void GroundTile::setStatus(int p_status, SDL_Texture* groundTex[4])
{
	status = p_status;
	setTex(groundTex[status]);
}
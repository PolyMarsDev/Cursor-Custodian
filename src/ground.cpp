#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>
#include <stdlib.h>

#include "ground.h"
#include "groundtile.h"

Ground::Ground(SDL_Texture* left, SDL_Texture* center, SDL_Texture* right, SDL_Texture* hole)
{
	groundTex[0] = left;
	groundTex[1] = center;
	groundTex[2] = right;
	groundTex[3] = hole;

	for (int i = 0; i < 14; i++)
	{
		groundTiles.push_back(GroundTile(groundTex[1], i));
	}
}

GroundTile& Ground::getTile(int p_index)
{
	return groundTiles.at(p_index);
}

int Ground::getStatus(int p_index)
{
	return groundTiles[p_index].getStatus();
}

int Ground::getLength()
{
	return groundTiles.size();
}

bool Ground::isTileBelow(float x, int width)
{
	for (int i = 0; i < getLength(); i++)
	{
		switch (getStatus(i)) {
		case 0:
			if (x + width > groundTiles[i].getX() + 24 && x < groundTiles[i].getX() + 64)
			{
				return true;
			}
			break;
		case 1:
			if (x + width > groundTiles[i].getX() && x < groundTiles[i].getX() + 64)
			{
				return true;
			}
			break;
		case 2:
			if (x + width > groundTiles[i].getX() && x < groundTiles[i].getX() + 40)
			{
				return true;
			}
			break;
		}
	} 
	return false;
}

void Ground::reset()
{
	for (int i = 0; i < 14; i++)
	{
		groundTiles[i].setStatus(1, groundTex);
		groundTiles[i].setX(i * 64.0f);
	}
	lastStatus = 1;
	holeCount = 0;
}

void Ground::update(int score)
{
	for (int i = 0; i < getLength(); i++)
	{
		groundTiles[i].setX(groundTiles[i].getX() - 1);
		if (groundTiles[i].getX() + 64 < 0)
		{
			groundTiles[i].setX(64 * (getLength() - 1) - 1);
			switch (lastStatus) {
			case 0:
			{
				groundTiles[i].setStatus(1, groundTex);
				lastStatus = 1;
				holeCount = 0;
				break;
			} 
			case 1:
			{
				int randomInt = rand()%2 + 1;
				groundTiles[i].setStatus(randomInt, groundTex);
				lastStatus = randomInt;
				holeCount = 0;
				break;
			} 
			case 2:
			{
				groundTiles[i].setStatus(3, groundTex);
				lastStatus = 3;
				holeCount = 0;
				break;
			} 
			case 3:
			{
				int randomInt = rand()%2;
				if (randomInt == 1)
				{
					randomInt = 3;
					holeCount++;
				}
				else {
					holeCount = 0;
				}
				if ((holeCount > 4 && score > 99) || (holeCount > 3 && score < 100))
				{
					randomInt = 0;
					holeCount = 0;
				}
				groundTiles[i].setStatus(randomInt, groundTex);
				lastStatus = randomInt;
				break;
			}
			}
		}
	}
}
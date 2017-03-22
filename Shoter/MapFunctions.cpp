#include "Map.h"


Map::Map()
{
	size.x = MAP_SIZE_X;
	size.y = MAP_SIZE_Y;

	Hero hero;
}

void Map::update(double dt)
{
	if (onMap())
	{
		hero.update(dt);
	}
	
	for (auto& bul : bullets)
	{
		if (bul.onMap(size))
		{
			bul.update(dt);
		}
		else
		{
			bullets.erase(bullets.begin());
		}
	}
}

bool Map::onMap()
{
	bool mapOK = true;
	if (hero.position.x < hero.radius)
	{
		hero.velocity = 0;
		mapOK = false;
	}
	if (hero.position.y < hero.radius)
	{
		hero.velocity = 0;
		mapOK = false;
	}
	if (hero.position.x + hero.radius > size.x)
	{
		hero.velocity = 0;
		mapOK = false;
	}
	if (hero.position.y + hero.radius > size.y)
	{
		hero.velocity = 0;
		mapOK = false;
	}

	return mapOK;
}

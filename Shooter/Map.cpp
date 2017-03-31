#include "Map.h"


Map::Map():
	hero(),
	bullets()
{
	size.x = MAP_SIZE_X;
	size.y = MAP_SIZE_Y;
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
		hero.SetPosition(Vector2(HERO_RADIUS, hero.position.y));
		mapOK = false;
	}
	if (hero.position.y < hero.radius)
	{
		hero.SetPosition(Vector2(hero.position.x, HERO_RADIUS));
		mapOK = false;
	}
	if (hero.position.x + hero.radius > size.x)
	{
		hero.SetPosition(Vector2(MAP_SIZE_X - HERO_RADIUS, hero.position.y));
		mapOK = false;
	}
	if (hero.position.y + hero.radius > size.y)
	{
		hero.SetPosition(Vector2(hero.position.x, MAP_SIZE_Y - HERO_RADIUS));
		mapOK = false;
	}

	return mapOK;
}

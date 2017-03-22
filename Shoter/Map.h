#pragma once
#include "Hero.h"
#include "Bullet.h"

class Map
{
public:
	Vector2 size;
	Hero hero;
	std::vector<Bullet> bullets;
	

	Map();

	void update(double dt);
	bool onMap();
};
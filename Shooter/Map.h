#pragma once
#include "Hero.h"
#include "Bullet.h"

class Map
{
public:
	Hero hero;
	std::vector<Bullet> bullets;
	Vector2 size;

	Map();

	void update(double dt);
	bool onMap();
};
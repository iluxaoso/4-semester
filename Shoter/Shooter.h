#pragma once
#include "Map.h"
#include "includes.h"

class Shooter
{
public:
	Map map;

	std::vector<sf::CircleShape> bullets;
	sf::Sprite hero;
	sf::RenderWindow window;
	sf::Event event;
	sf::Texture texture;

	Shooter();
	
	int run();

	int Events();
	int Key();
	int Mouse();
	int MouseButton();

	bool onMap(const sf::CircleShape &circle) const;

	int DrawMap();
};
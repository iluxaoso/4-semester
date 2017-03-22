#include "Shooter.h"
#include "includes.h"


Shooter::Shooter()
{
	Map map;

	sf::Texture texture;
	texture.loadFromFile("hero.png");

	sf::Sprite hero;
	hero.setTexture(texture);
	hero.setScale(0.5, 0.5);
	hero.setPosition(map.size.x / 2, map.size.y / 2);

	std::vector <sf::CircleShape> bullets;

	sf::RenderWindow window(sf::VideoMode(map.size.x, map.size.y), "Map");

	sf::Event();
}

int Shooter::run()
{
	while (window.isOpen())
	{
		Events();

		window.clear(sf::Color::Black);
		DrawMap();

		window.display();

		map.update(DT);
	}

	return 0;
}

int Shooter::Events()
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			Key();
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			MouseButton();
			break;
		}
		case sf::Event::MouseMoved:
		{
			Mouse();
			break;
		}
		}
	}

	return 0;
}

int Shooter::Key()
{
	switch (event.key.code)
	{
	case sf::Keyboard::A:
	{
		map.hero.SetVelocity(Vector2(-HERO_VELOCITY, 0));
		break;
	}

	case sf::Keyboard::Left:
	{
		map.hero.SetVelocity(Vector2(-HERO_VELOCITY, 0));
		break;
	}

	case sf::Keyboard::D:
	{
		map.hero.SetVelocity(Vector2(HERO_VELOCITY, 0));
		break;
	}

	case sf::Keyboard::Right:
	{
		map.hero.SetVelocity(Vector2(HERO_VELOCITY, 0));
		break;
	}

	case sf::Keyboard::W:
	{
		map.hero.SetVelocity(Vector2(0, -HERO_VELOCITY));
		break;
	}

	case sf::Keyboard::Up:
	{
		map.hero.SetVelocity(Vector2(0, -HERO_VELOCITY));
		break;
	}

	case sf::Keyboard::Down:
	{
		map.hero.SetVelocity(Vector2(0, HERO_VELOCITY));
		break;
	}

	case sf::Keyboard::S:
	{
		map.hero.SetVelocity(Vector2(0, HERO_VELOCITY));
		break;
	}
	}

	return 0;
}

int Shooter::MouseButton()
{
	sf::Vector2f heroPosition = hero.getPosition();

	Vector2 mousePosition(event.mouseButton.x - heroPosition.x, event.mouseButton.y - heroPosition.y);

	map.bullets.push_back(Bullet(map.hero.GetDirection().norm() * BULLET_VELOCITY, map.hero.GetPosition()));

	for (auto& bul : bullets)
	{
		if (onMap(bul))
		{
			bullets.erase(bullets.begin());
		}
	}

	return 0;
}

int Shooter::Mouse()
{
	sf::Vector2u circleSize = hero.getTexture()->getSize();
	hero.setOrigin(circleSize.x / 2, circleSize.y / 2);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f center = hero.getPosition();
	sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

	hero.setRotation(90 + atan2f(d.y, d.x) * 180 / M_PI);

	return 0;
}

int Shooter::DrawMap()
{
	map.hero.position = map.hero.GetPosition();

	map.hero.SetPosition(Vector2(map.hero.position.x, map.hero.position.y));
	hero.setRotation(360. - map.hero.GetDirection().getAngleBetween(Vector2(0, -1)));

/*	for (auto& bul : bullets)
	{
		bulletShape.setFillColor(sf::Color::Yellow);
		bulletShape.setPosition(bulletPosition.x, bulletPosition.y);
		bullets.push_back(bulletShape);

		bulletPosition = bul.getPosition();
		bul.setPosition(sf::Vector2f(bulletPosition.x, bulletPosition.y));

		window.draw(bul);
	}*/
	Vector2 bulletPosition;
	sf::CircleShape bulletShape(BULLET_RADIUS);

	for (int i = 0; i < map.bullets.size(); i++)
	{
		bulletShape.setFillColor(sf::Color::Red);
		bulletShape.setPosition(bulletPosition.x, bulletPosition.y);
		bullets.push_back(bulletShape);

		bulletPosition = map.bullets[i].GetPosition();
		bullets[i].setPosition(bulletPosition.x, bulletPosition.y);

		window.draw(bullets[i]);
	}
	
	window.draw(hero);

	for (auto& bullet : bullets)
	{
		if (!onMap(bullet))
		{
			bullets.erase(bullets.begin());
			std::cout << bullet.getPosition().x << " " << bullet.getPosition().y << std::endl;
		}
	}

	return 0;
}

bool Shooter::onMap(const sf::CircleShape &circle) const
{
	sf::Vector2f circlePos = circle.getPosition();

	if (circlePos.x < 0 || circlePos.y < 0 || circlePos.x > map.size.x || circlePos.y > map.size.y)
	{
		return false;
	}

	return true;
}
#include <SFML\Graphics.hpp>
#include <cmath>

int DrawTriangle(sf::RenderWindow& window, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c)
{
	sf::Vertex line1[] =
	{
		sf::Vertex(a),
		sf::Vertex(b)
	};
	window.draw(line1, 2, sf::Lines);
	sf::Vertex line2[] =
	{
		sf::Vertex(a),
		sf::Vertex(c)
	};
	window.draw(line2, 2, sf::Lines);
	sf::Vertex line3[] =
	{
		sf::Vertex(c),
		sf::Vertex(b)
	};
	window.draw(line3, 2, sf::Lines);

	return 0;
}

int DrawTriangleSerp(sf::RenderWindow& window, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, int counter)
{
	if (counter <= 0)
	{
		return 0;
	}

	DrawTriangle(window, a, b, c);

	sf::Vector2f mid1((a.x + b.x) / 2, (a.y + b.y) / 2);
	sf::Vector2f mid2((c.x + b.x) / 2, (c.y + b.y) / 2);
	sf::Vector2f mid3((a.x + c.x) / 2, (a.y + c.y) / 2);

	DrawTriangle(window, mid1, mid2, mid3);

	DrawTriangleSerp(window, a, mid1, mid3, counter-1);
	DrawTriangleSerp(window, mid1, b, mid2, counter-1);
	DrawTriangleSerp(window, mid3, mid2, c, counter-1);

	return 0;
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  while (window.isOpen())
  {
	  sf::Event event;
	  while (window.pollEvent(event))
	  {
		  if (event.type == sf::Event::Closed)
		  {
			  window.close();
		  }
	  }

	  window.clear(sf::Color::Red);

	  
	  
	  /*sf::CircleShape circle(150);

	  circle.setPosition(5, 100);
	  circle.setFillColor(sf::Color(150, 50, 250));
	  circle.setOutlineThickness(5);
	  circle.setOutlineColor(sf::Color(250, 150, 100));
	  window.draw(circle);
	  */

	  DrawTriangleSerp(window, sf::Vector2f(10, 590), sf::Vector2f(790, 590), sf::Vector2f(400, 10), 10);
	
	window.display();
  }
  
  return 0;
}

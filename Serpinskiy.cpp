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

	sf::Vector2f mid1((a + b) * 0,5);
	sf::Vector2f mid2((c + b) * 0,5);
	sf::Vector2f mid3((a + c) * 0,5);

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

	  DrawTriangleSerp(window, sf::Vector2f(10, 590), sf::Vector2f(790, 590), sf::Vector2f(400, 10), 10);
	
	window.display();
  }
  
  return 0;
}

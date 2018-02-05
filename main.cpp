#include "QuadTree.hpp"
#include "Object.hpp"
#include <iostream>
#include <random>
int main()
{
	std::random_device r;
	std::default_random_engine e1(r());

	std::vector<QuadTree*> mNodeList;
	QuadTree Quad(sf::IntRect(0,0,800,600),mNodeList);
	for (int i = 0; i < 100; i++)
	{
		std::uniform_int_distribution<int> a(1, 800);
		std::uniform_int_distribution<int> b(1, 600);
		int x = a(e1);
		int y = b(e1);

		Quad.insert(std::make_shared<Object>(sf::Vector2f(x, y), sf::Vector2f(5, 5)));
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "QuadTree Borysiak");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(Quad);
		window.display();
	}

	return 0;
}
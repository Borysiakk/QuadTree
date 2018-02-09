#include "QuadTree.hpp"
#include "Object.hpp"
#include <iostream>
#include <random>
#include <SFML\Window.hpp>
int main()
{

	std::random_device r;
	std::default_random_engine e1(r());
	std::vector<QuadTree*> mNodeList;

	QuadTree Quad(sf::FloatRect(0, 0, 800, 600), mNodeList);
	sf::Clock clock;
	for (int i = 0; i < 10; i++)
	{
		std::uniform_int_distribution<int> uniform_dist_a(1, 795);
		std::uniform_int_distribution<int> uniform_dist_b(1, 595);
		int x = uniform_dist_a(e1);
		int y = uniform_dist_b(e1);

		Quad.Insert(std::make_shared<Object>(sf::Vector2f(x, y), sf::Vector2f(5, 5)));
	}
	std::cout << clock.getElapsedTime().asSeconds() << "\n";
	sf::RenderWindow window(sf::VideoMode(800, 600), "QuadTree Borysiak");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)window.close();
		}

		window.clear(sf::Color::White);
		window.draw(Quad);
		window.display();
	}

	return 0;
}
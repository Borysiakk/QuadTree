#include "QuadTree.hpp"
#include "Object.hpp"
#include <iostream>
#include <random>
#include <SFML\Window.hpp>

int main()
{
	int count = 50;
	std::random_device r;
	std::default_random_engine e1(r());
	std::vector<QuadTree*> mNodeList;

	QuadTree Quad(sf::FloatRect(0, 0, 800, 600), mNodeList);
	sf::Clock clock1;
	for (int i = 0; i < count; i++)
	{
		std::uniform_int_distribution<int> uniform_dist_a(1, 800);
		std::uniform_int_distribution<int> uniform_dist_b(1, 600);
		int x = uniform_dist_a(e1);
		int y = uniform_dist_b(e1);

		Quad.Insert(std::make_shared<Object>(sf::Vector2f(x, y), sf::Vector2f(5, 5)));
	}

	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(50, 50));
	shape.setFillColor(sf::Color::Cyan);
	sf::RenderWindow window(sf::VideoMode(800, 600), "QuadTree");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)window.close();

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			QuadTree::ObjectsQuadTree vObject;
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			shape.setPosition(pos.x, pos.y);

			sf::Clock clock;
			Quad.GetItems(sf::FloatRect(sf::Vector2f(shape.getPosition()), sf::Vector2f(shape.getSize())), vObject);
			sf::Time time = clock.getElapsedTime();
			std::cout << "Czas = " << time.asMicroseconds() << " Microseconds \n";
			std::cout << "Ilosc kolizji = " << vObject.size() << "\n";
		}
		window.clear(sf::Color::White);
		window.draw(shape);
		window.draw(Quad);
		window.display();
	}

	return 0;
}
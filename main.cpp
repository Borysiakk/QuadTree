#include "QuadTree.hpp"
#include "Object.hpp"
#include <iostream>
int main()
{
	std::vector<QuadTree*> mNodeList;
	QuadTree Quad(sf::IntRect(0,0,800,600),mNodeList);
	Quad.insert(new Object(sf::Vector2f(10,10), sf::Vector2f(5,5)));
	Quad.insert(new Object(sf::Vector2f(50,10), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(150, 10), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(180, 10), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(250, 10), sf::Vector2f(5, 5)));

	Quad.insert(new Object(sf::Vector2f(100, 500), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(300, 550), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(320, 500), sf::Vector2f(5, 5)));

	Quad.insert(new Object(sf::Vector2f(500, 350), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(520, 350), sf::Vector2f(5, 5)));

	Quad.insert(new Object(sf::Vector2f(500, 200), sf::Vector2f(5, 5)));

	sf::RenderWindow window(sf::VideoMode(800, 600), "QuadTree Borysiak");

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
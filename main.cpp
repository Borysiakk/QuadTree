#include "QuadTree.hpp"
#include "Object.hpp"
#include <iostream>
int main()
{
	std::vector<QuadTree*> mNodeList;
	QuadTree Quad(sf::IntRect(0,0,800,600),mNodeList);
	Quad.insert(new Object(sf::Vector2f(650, 10), sf::Vector2f(5,5)));
	Quad.insert(new Object(sf::Vector2f(670, 10), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(690, 10), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(710, 10), sf::Vector2f(5, 5)));
	//Quad.insert(new Object(sf::Vector2f(720, 10), sf::Vector2f(5, 5)));



	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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
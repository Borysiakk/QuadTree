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
	Quad.insert(std::make_shared<Object>(sf::Vector2f(5,5),sf::Vector2f(50,50)));
	Quad.insert(std::make_shared<Object>(sf::Vector2f(740, 5), sf::Vector2f(50, 50)));
	Quad.insert(std::make_shared<Object>(sf::Vector2f(740, 540), sf::Vector2f(50, 50)));

	
	Quad.insert(std::make_shared<Object>(sf::Vector2f(320, 290), sf::Vector2f(50, 50)));
	Quad.insert(std::make_shared<Object>(sf::Vector2f(450, 290), sf::Vector2f(50, 50)));



	sf::RenderWindow window(sf::VideoMode(800, 600), "QuadTree Borysiak");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					sf::Clock clock;
					int size = Quad.getElement(sf::FloatRect(event.mouseButton.x, event.mouseButton.y, 5, 5)).size();
					sf::Time elapsed2 = clock.getElapsedTime();
					std::cout << "Ilosc kolizji do sprawdzenia : " << size << " Sprawdzone w czasie : "<<elapsed2.asMicroseconds()<<" Microseconds \n";
					clock.restart();
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(Quad);
		window.display();
	}

	return 0;
}
#include "QuadTree.hpp"
#include "Object.hpp"
#include <iostream>
#include <random>
#include <SFML\Window.hpp>
int main()
{

	std::vector<QuadTree*> mNodeList;

	QuadTree Quad(sf::FloatRect(0, 0, 800, 600), mNodeList);
	Quad.Insert(std::make_shared<Object>(sf::Vector2f(5, 5), sf::Vector2f(5, 5)));
	Quad.Insert(std::make_shared<Object>(sf::Vector2f(20, 20), sf::Vector2f(5, 5)));
	Quad.Insert(std::make_shared<Object>(sf::Vector2f(46, 50), sf::Vector2f(5, 5)));
	Quad.Insert(std::make_shared<Object>(sf::Vector2f(46, 40), sf::Vector2f(5, 5)));


	std::cout << Quad.mObjects.size() << "\n";
	std::cout << "Quad [0]\n";
	std::cout << Quad.mChildren[0]->mObjects.size() << "\n";
	std::cout << "Quad [0][0]\n";
	//std::cout << Quad.mChildren[0]->mChildren[0]->mObjects.size() << "\n";
	//std::cout << "Quad [0][0][0]\n";
	//std::cout << Quad.mChildren[0]->mChildren[0]->mChildren[0]->mObjects.size() << "\n";
	//std::cout << "Quad [0][0][0][0]\n";
	//std::cout << Quad.mChildren[0]->mChildren[0]->mChildren[0]->mChildren[0]->mObjects.size() << "\n";




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
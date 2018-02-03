#include "QuadTree.hpp"
#include "Object.hpp"
int main()
{
	std::vector<QuadTree*> mNodeList;
	QuadTree Quad(sf::IntRect(0,0,800,600),mNodeList);
	Quad.insert(new Object(sf::Vector2f(10, 10), sf::Vector2f(5,5)));
	Quad.insert(new Object(sf::Vector2f(20, 10), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(30, 10), sf::Vector2f(5, 5)));
	Quad.insert(new Object(sf::Vector2f(40, 10), sf::Vector2f(5, 5)));

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
#pragma once
#include <SFML\Graphics.hpp>

class Object
{
public:
	Object(sf::Vector2f Position,sf::Vector2f Size);
private:
	sf::RectangleShape rectangle;

};


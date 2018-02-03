#include "Object.hpp"

Object::Object(sf::Vector2f Position, sf::Vector2f Size) :rectangle(Size)
{
	rectangle.setPosition(Position);
}

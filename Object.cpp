#include "Object.hpp"

Object::Object(sf::Vector2f Position, sf::Vector2f Size) :rectangle(Size)
{
	setPosition(Position);
}

const sf::Vector2f & Object::getSize()
{
	return rectangle.getSize();
}

void Object::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(rectangle,states);
}

#include "Object.hpp"

Object::Object(sf::Vector2f Position, sf::Vector2f Size) :rectangle(Size)
{
	setPosition(sf::Vector2f(Position.x,Position.y));
	rectangle.setFillColor(sf::Color::Blue);
}

sf::FloatRect Object::getBoundingBox()
{
	return sf::FloatRect(getPosition(), rectangle.getSize());
}

const sf::Vector2f & Object::getSize()
{
	return rectangle.getSize();
}

void Object::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rectangle,getTransform());
}

#pragma once
#include <SFML\Graphics.hpp>

class Object :public sf::Drawable,public sf::Transformable
{
public:
	Object(sf::Vector2f Position,sf::Vector2f Size);
	const sf::Vector2f & getSize();
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RectangleShape rectangle;

};


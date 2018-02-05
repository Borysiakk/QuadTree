#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
class Object :public sf::Drawable,public sf::Transformable
{
public:
	using Ptr = std::shared_ptr<Object>;

	Object(sf::Vector2f Position,sf::Vector2f Size);
	const sf::FloatRect & getBoundingBox();
	const sf::Vector2f & getSize();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RectangleShape rectangle;

};


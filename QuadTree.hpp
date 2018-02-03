#pragma once
#include <SFML\Graphics.hpp>

#include <array>
#include <memory>
#include <vector>

#include "Object.hpp"

enum class IntersectsType
{
	None,
	NorthWest,							  	 									
	NorthEast,																
	SouthWest,																	
	SouthEast,																	
};

class QuadTree:public sf::Drawable
{
public:
	static const auto DefaultNodes = 4u;
	using Ptr = std::unique_ptr<QuadTree>;
	using ArrayQuadTree = std::array<Ptr, DefaultNodes>;
	using ObjectsQuadTree = std::vector<Object*>;

	QuadTree(sf::IntRect Bounds,std::vector<QuadTree*> & ListNode);
	void insert(Object * object);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	bool isNodeTree();
	void BalancedQuadTree();
	void CreateArrayChildren();
	IntersectsType intersects(Object * Obj);

	std::vector<QuadTree*> & mListNode;
	sf::RectangleShape rectangle;
	ObjectsQuadTree mObjects;
	ArrayQuadTree mChildren;
	sf::IntRect mBounds;
};


#pragma once
#include <SFML\Graphics.hpp>

#include <array>
#include <memory>
#include <vector>

#include "Object.hpp"

enum class IntersectsType :int
{
	None      = -1,
	NorthWest =  0,							  	 									
	NorthEast =  1,																
	SouthWest =  2,																	
	SouthEast =  3,																	
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

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool isNodeTree();
	void CreateArrayChildren();
	IntersectsType intersects(Object * Obj);

	std::vector<QuadTree*> & mListNode;
	sf::RectangleShape rectangle;
	ObjectsQuadTree mObjects;
	ArrayQuadTree mChildren;
	sf::IntRect mBounds;
};


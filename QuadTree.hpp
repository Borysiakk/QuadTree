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

class QuadTree
{
public:
	static const auto DefaultNodes = 4u;
	using Ptr = std::unique_ptr<QuadTree>;
	using ArrayQuadTree = std::array<Ptr, DefaultNodes>;
	using ObjectsQuadTree = std::vector<Object*>;

	QuadTree(sf::IntRect Bounds,std::vector<QuadTree*> & ListNode);

private:
	bool isNodeTree();
	void BalancedQuadTree();
	void CreateArrayChildren();
	IntersectsType intersects(Object * Obj);

	sf::IntRect mBounds;
	ArrayQuadTree mChildren;
	ObjectsQuadTree mObjects;
	std::vector<QuadTree*> & mListNode;
};


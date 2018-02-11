#pragma once
#include <SFML\Graphics.hpp>

#include <array>
#include <memory>
#include <vector>

#include "Object.hpp"

enum class IntersectsType :int
{
	None      = -2,
	Different = -1,
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
	using ObjectsQuadTree = std::vector<Object::Ptr>;

	QuadTree(sf::FloatRect Bounds,std::vector<QuadTree*> & ListNode);
	void Insert(Object::Ptr object);
	void GetItems(sf::FloatRect rectangle,ObjectsQuadTree & vObject);
	ObjectsQuadTree GetItems(sf::Vector2f point);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	void Partition();
	void RemoveItem(int index);
	void PushItemUp(int index);
	bool PushItemDown(int index);
	ObjectsQuadTree NodeAllObject();
	bool InsertInChild(Object::Ptr object);
	bool ContainsRect(sf::FloatRect rectangle);
	IntersectsType ContainsPatition(sf::FloatRect rect);

	std::vector<QuadTree*> & mListNode;
	sf::RectangleShape rectangle;
	ObjectsQuadTree mObjects;
	ArrayQuadTree mChildren;
	sf::FloatRect mBounds;
	bool IsPartitioned;
};


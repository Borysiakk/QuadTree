﻿#include "QuadTree.hpp"
#include <iostream>

QuadTree::QuadTree(sf::FloatRect Bounds, std::vector<QuadTree*> & ListNode) :mBounds(Bounds), mListNode(ListNode), IsPartitioned(false)
{
	rectangle.setPosition(mBounds.left, mBounds.top);
	rectangle.setSize(sf::Vector2f(mBounds.width, mBounds.height));
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(-0.5f);
	mListNode.push_back(this);
}

void QuadTree::Insert(Object::Ptr object)
{
	if (!InsertInChild(object))
	{
		mObjects.push_back(object);
		if (!IsPartitioned && mObjects.size() > 3)
		{
			Partition();
		}
	}
}

void QuadTree::Partition()
{
	int Width = mBounds.width / 2;
	int Height = mBounds.height / 2;
	int MiddleX = mBounds.left + (mBounds.width / 2);
	int MiddleY = mBounds.top + (mBounds.height / 2);

	mChildren[0] = std::make_unique<QuadTree>(sf::FloatRect(mBounds.left, mBounds.top, Width, Height), mListNode);
	mChildren[1] = std::make_unique<QuadTree>(sf::FloatRect(MiddleX, mBounds.top, Width, Height), mListNode);
	mChildren[2] = std::make_unique<QuadTree>(sf::FloatRect(mBounds.left, MiddleY, Width, Height), mListNode);
	mChildren[3] = std::make_unique<QuadTree>(sf::FloatRect(MiddleX, MiddleY, Width, Height), mListNode);

	IsPartitioned = true;

	int i = 0;
	while (i < mObjects.size())
	{
		if (!PushItemDown(i))
		{
			i++;
		}
	}
}

void QuadTree::RemoveItem(int index)
{
	mObjects.erase(mObjects.begin() + index);
}

void QuadTree::PushItemUp(int index)
{
	if (InsertInChild(mObjects[index]))
	{
		RemoveItem(index);
	}
}

bool QuadTree::PushItemDown(int index)
{
	if(InsertInChild(mObjects[index]))
	{
		RemoveItem(index);
		return true;
	}

	else return false;
}

bool QuadTree::ContainsRect(sf::FloatRect rect)
{
	return mBounds.intersects(rect);
}

bool QuadTree::InsertInChild(Object::Ptr object)
{
	if (!IsPartitioned) return false;
	auto type = ContainsPatition(object->getBoundingBox());
	if (type != IntersectsType::None)
	{
		mChildren[static_cast<int>(type)]->Insert(object);
	}
	else return false;

	return true;
}

IntersectsType QuadTree::ContainsPatition(sf::FloatRect rect)
{
	int MiddleX = mBounds.left + (mBounds.width / 2);
	int MiddleY = mBounds.top + (mBounds.height / 2);

	bool top = (rect.top + rect.height > MiddleY);
	bool bottom = (rect.top < MiddleY);

	bool right = (rect.left + rect.width > MiddleX);
	bool left = (rect.left < MiddleX);

	if (top == true && bottom == true)
	{
		return IntersectsType::None;
	}

	else if (top == true && bottom == false)
	{
		if (right == true && left == true)
		{
			return IntersectsType::None;
		}
		else if (right == true && left == false)
		{
			return IntersectsType::SouthEast;
		}
		else if (right == false && left == true)
		{
			return IntersectsType::SouthWest;
		}
	}
	else if (top == false && bottom == true)
	{
		if (right == true && left == true)
		{
			return IntersectsType::None;
		}
		else if (right == true && left == false)
		{
			return IntersectsType::NorthEast;
		}
		else if (right == false && left == true)
		{
			return IntersectsType::NorthWest;
		}
	}
	else
	{
		return IntersectsType::None;
	}
}

void QuadTree::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto & node : mListNode)
	{
		target.draw(node->rectangle);
		for (auto & obj : node->mObjects)
		{
			target.draw(*obj);
		}
	}
}


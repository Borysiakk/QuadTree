#include "QuadTree.hpp"
#include <iostream>

QuadTree::QuadTree(sf::IntRect Bounds, std::vector<QuadTree*> & ListNode):mBounds(Bounds),mListNode(ListNode)
{
	rectangle.setPosition(mBounds.left, mBounds.top);
	rectangle.setSize(sf::Vector2f(mBounds.width, mBounds.height));
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(-0.5f);
	mListNode.push_back(this);
}

void QuadTree::insert(Object * object)
{
	bool end = false;
	QuadTree * root = this;
	while (!end)
	{
		if (root->isNodeTree() == false)
		{
			if (root->mObjects.size() >= 2)
			{
				root->mObjects.push_back(object);
				root->CreateArrayChildren();
				root->BalancedQuadTree();
				end = true;
			}
			else
			{
				root->mObjects.push_back(object);
				end = true;
			}
		}
		else
		{
			IntersectsType type = root->intersects(object);
			switch (type)
			{
			case IntersectsType::None:
			{
				root->mObjects.push_back(object);
				end = true;
				break;
			}
			case IntersectsType::NorthWest:
			{
				root = root->mChildren[0].get();
				break;
			}
			case IntersectsType::NorthEast:
			{
				root = root->mChildren[1].get();
				break;
			}
			case IntersectsType::SouthWest:
			{
				root = root->mChildren[2].get();
				break;
			}
			case IntersectsType::SouthEast:
			{
				root = root->mChildren[3].get();
				break;
			}
			}
		}
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

bool QuadTree::isNodeTree()
{
	if (mChildren[0] != nullptr)return true;
	else return false;
}

void QuadTree::BalancedQuadTree()
{
	//std::cout << "--------\n";
	ObjectsQuadTree Objects = std::move(mObjects);
	for (auto & obj : Objects)
	{
		IntersectsType type = intersects(obj);
		//std::cout << static_cast<int>(type) << "\n";
		switch (type)
		{
		case IntersectsType::None:
		{
			mObjects.push_back(obj);
			break;
		}
		case IntersectsType::NorthWest:
		{
			mChildren[0]->mObjects.push_back(obj);
			break;
		}
		case IntersectsType::NorthEast:
		{
			mChildren[1]->mObjects.push_back(obj);
			break;
		}
		case IntersectsType::SouthWest:
		{
			mChildren[2]->mObjects.push_back(obj);
			break;
		}
		case IntersectsType::SouthEast:
		{
			mChildren[3]->mObjects.push_back(obj);
			break;
		}
		}
	}
}

void QuadTree::CreateArrayChildren()
{
	int Width = mBounds.width / 2;
	int Height = mBounds.height / 2;
	int MiddleX = mBounds.left + (mBounds.width / 2);
	int MiddleY = mBounds.top + (mBounds.height / 2);

	mChildren[0] = std::make_unique<QuadTree>(sf::IntRect(mBounds.left, mBounds.top, Width, Height), mListNode);
	mChildren[1] = std::make_unique<QuadTree>(sf::IntRect(MiddleX, mBounds.top, Width, Height), mListNode);
	mChildren[2] = std::make_unique<QuadTree>(sf::IntRect(mBounds.left, MiddleY, Width, Height), mListNode);
	mChildren[3] = std::make_unique<QuadTree>(sf::IntRect(MiddleX, MiddleY, Width, Height), mListNode);
}

IntersectsType QuadTree::intersects(Object * Obj)
{
	sf::FloatRect rect = sf::FloatRect(Obj->getPosition(),Obj->getSize());

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
		//Południe
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

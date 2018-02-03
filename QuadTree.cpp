#include "QuadTree.hpp"

QuadTree::QuadTree(Object * Obj, std::vector<QuadTree*> & ListNode):mListNode(ListNode)
{
	mListNode.push_back(this);
}

bool QuadTree::isNodeTree()
{
	if (mChildren[0] != nullptr)return true;
	else return false;
}

void QuadTree::BalancedQuadTree()
{
}

void QuadTree::CreateArrayChildren()
{
	int Width = mBounds.width / 2;
	int Height = mBounds.height / 2;
	int MiddleX = mBounds.left + (mBounds.width / 2);
	int MiddleY = mBounds.top + (mBounds.height / 2);

	mChildren[0] = std::make_unique<QuadTree>(sf::IntRect(mBounds.left, mBounds.top, Width, Height));
	mChildren[1] = std::make_unique<QuadTree>(sf::IntRect(MiddleX, mBounds.top, Width, Height));
	mChildren[2] = std::make_unique<QuadTree>(sf::IntRect(mBounds.left, MiddleY, Width, Height));
	mChildren[3] = std::make_unique<QuadTree>(sf::IntRect(MiddleX, MiddleY, Width, Height));
}

IntersectsType QuadTree::intersects(sf::IntRect rect)
{

	return IntersectsType();
}

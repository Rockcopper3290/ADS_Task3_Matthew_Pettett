//Class: ADS 103
//Name: Matthew Pettett
//Student ID: A00051029

#pragma once
#include "BST.h"

//AVL is self balancing binary search tree
//AVL - Adelson, Velski & Landis
class AVL : public BST
{
public:
	bool displayRotations = true;

	//works out height of sub tree
	int height(TreeNode* node);

	//difference between left and right sub trees
	int difference(TreeNode* node);

	//ROTATIONS
	//return: new parent of subtree
	//parameter: current parent of sub tree
	//right branch, right child
	TreeNode* RRrotation(TreeNode* parent);
	//left branch, left child
	TreeNode* LLrotation(TreeNode* parent);
	//left branch, right child
	TreeNode* LRrotation(TreeNode* parent);
	//right branch, left child
	TreeNode* RLrotation(TreeNode* parent);

	//BALANCE
	//balances a tree structure where parent is the middle top node
	//returns new parent after balancing(rotations)
	TreeNode* balance(TreeNode* parent);

	//INSERT
	//recursive insert that considers parent a sub tree
	//this insert also balances itself
	//returns the new root node of the tree
	TreeNode* insertAVL(TreeNode* parent, TreeNode* newTreeElement);

	//overriding insert from parent
	void insert(TreeNode* newTreeElement);
};


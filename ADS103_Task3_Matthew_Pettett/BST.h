//Class: ADS 103
//Name: Matthew Pettett
//Student ID: A00051029

#pragma once
#include <queue>
#include <fstream> //file reading/writing stuff
#include "TreeNode.h"


//HELPER CLASS FOR OUTPUT
class TreeLevelNode {
public:
	TreeNode* treeNodeElement;
	int level;

	//constructor
	TreeLevelNode(TreeNode* treeNodeElement, int level)
	{
		this->treeNodeElement = treeNodeElement;
		this->level = level;
	}
};

//Binary Search Tree
//root node sort of acting as center
//everything smaller then root, is stored on left branch somewhere
//everything else to the right
class BST
{
public:
	TreeNode* root = NULL;
	virtual void insert(TreeNode* newTreeNodeElement);
	TreeNode* search(int treeNodeElement, bool showSearchPath = false);

	//recursive traversal functions
	void inOrderTraversal(TreeNode* current);
	void preOrderTraversal(TreeNode* current);
	void postOrderTraversal(TreeNode* current);

	//show
	void show(TreeNode* p);
	void writeToFile(TreeNode* p, string outputFileName);
};


#pragma once
#include <queue>
#include <fstream> //file reading/writing stuff
#include "TreeNode.h"


//HELPER CLASS FOR OUTPUT
class TreeLevelNode {
public:
	TreeNode* student;
	int level;

	//constructor
	TreeLevelNode(TreeNode* student, int level)
	{
		this->student = student;
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
	virtual void insert(TreeNode* newStudent);
	TreeNode* search(int studentID, bool showSearchPath = false);

	//recursive traversal functions
	void inOrderTraversal(TreeNode* current);
	void preOrderTraversal(TreeNode* current);
	void postOrderTraversal(TreeNode* current);

	//show
	void show(TreeNode* p);
	void writeToFile(TreeNode* p, string outputFileName);
};


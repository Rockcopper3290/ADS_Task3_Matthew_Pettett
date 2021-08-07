#pragma once
#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
public:
	int treeElement;
	TreeNode* leftChild;
	TreeNode* rightChild;

	TreeNode(int treeElement);
};


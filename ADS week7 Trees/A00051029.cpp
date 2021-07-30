//Class: ADS 103
//Name: Matthew Pettett
//Student ID: A00051029


#include <iostream>
#include <string>
#include <vector>  // For storage
#include <fstream> //file reading/writing stuff

#include "BST.h"
#include "AVL.h"

using namespace std;

int main() {

	//ifstream q1_readFile;
	//q1_readFile.open("input-q1a2.txt");
	//// If file could not be opened, program will exit with an error message
	//if (!q1_readFile.is_open())
	//{
	//	cout << "\t!!ERROR!!" << endl;
	//	cout << "\tQuestion 1 output file named 'output-a1q1.txt' was unable to be opened." << endl;
	//	exit(1);
	//}
	//int numberOfNumbers;
	//q1_readFile >> numberOfNumbers;
	//vector<int> nums;
	//for (int i = 0; i < numberOfNumbers; i++)
	//{
	//	int temp;
	//	q1_readFile >> temp; //NOTE spaces and endlines are skipped in file reading ;)
	//	nums.push_back(temp);
	//}
	//cout << numberOfNumbers << endl;
	//cout << endl;
	//for (int i = 0; i < numberOfNumbers; i++)
	//{
	//	
	//	cout << nums[i] << " ";
	//}
	//cout << endl;
	//q1_readFile.close();


	///*
	BST bst1;
	//StudentNode* sNodePtr = new StudentNode(123, "asasd");
	bst1.insert(new StudentNode(3433, "Jeff"));
	bst1.insert(new StudentNode(2222, "Bill"));
	bst1.insert(new StudentNode(1221, "Trevor"));
	bst1.insert(new StudentNode(4533, "Uncle"));
	bst1.insert(new StudentNode(3333, "Adam"));
	bst1.insert(new StudentNode(6666, "Bridge"));
	bst1.insert(new StudentNode(7777, "Bam"));
	bst1.insert(new StudentNode(4343, "Bucket"));

	bst1.show(bst1.root);

/*
	cout << "try find student matching id 1221..." << endl;
	StudentNode* sPtr = bst1.search(1221, true);

	if (sPtr == NULL)
		cout << "Cannot find a student matching id 1221" << endl;
	else
		cout << "Found " << sPtr->name << " with id 1221" << endl;


	cout << "Students inorder traversal" << endl;
	cout << "==========================" << endl;
	bst1.inOrderTraversal(bst1.root);

	cout << "Students preorder traversal" << endl;
	cout << "===========================" << endl;
	bst1.preOrderTraversal(bst1.root);

	cout << "Students postorder traversal" << endl;
	cout << "===========================" << endl;
	bst1.postOrderTraversal(bst1.root);
	*/


	/*
	cout << endl << endl;
	cout << "AVL" << endl;
	cout << "===" << endl;
	AVL avl1;
	avl1.displayRotations = true;
	avl1.insert(new StudentNode(2333, "Jeff"));
	avl1.insert(new StudentNode(2222, "Bill"));
	avl1.insert(new StudentNode(1221, "Trevor"));
	cout << "Tree height thus far: " << avl1.height(avl1.root) << endl;
	avl1.insert(new StudentNode(4533, "Uncle"));
	avl1.insert(new StudentNode(3333, "Adam"));
	avl1.insert(new StudentNode(6666, "Bridge"));
	avl1.insert(new StudentNode(7777, "Bam"));
	avl1.insert(new StudentNode(4343, "Bucket"));
	cout << "AVL ROOT : " << avl1.root->name << " " << avl1.root->studentID << endl;
	cout << "Students AVL inorder traversal" << endl;
	cout << "==============================" << endl;
	avl1.inOrderTraversal(avl1.root);


	cout << "try find student matching id 4343..." << endl;
	StudentNode* sPtr2 = avl1.search(4343, true);
	if (sPtr2 != NULL)
		cout << "Found " << sPtr2->name << " with id 4343" << endl;
	else
		cout << "Cannot find id 4343 in avl1 tree" << endl;
		*/

	system("pause");
}
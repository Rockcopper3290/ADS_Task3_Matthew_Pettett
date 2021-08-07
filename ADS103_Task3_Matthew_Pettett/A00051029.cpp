//Class: ADS 103
//Name: Matthew Pettett
//Student ID: A00051029


#include <iostream> //Input/Output stream
#include <string> // For usage of sting 
#include <vector>  // For storage
#include <fstream> //file reading/writing stuff

#include "BST.h"
#include "AVL.h"
#include "Heaps.h"

using namespace std;

void fileOpenedCheck_errorMessage(string textFileName)
{
	cout << "\t!!ERROR!!" << endl;
	cout << "\tText file named '" << textFileName << "' was unable to be opened." << endl;
	exit(1);
};

int main() {
	// Question 1 -------------------------------------------------------------------------
	ifstream q1_readFile;
	string q1_inputFileName = "input-q1a2.txt";
	// Opens and reads text file called "input-q1a2.txt"
	q1_readFile.open(q1_inputFileName);
	// If file could not be opened, program will exit with an error message (AKA: Idiot proofing)
	if (!q1_readFile.is_open())
		fileOpenedCheck_errorMessage(q1_inputFileName);

	// Amount of numbers that needs to be sorted into an AVL tree
	int numberOfNumbers;
	q1_readFile >> numberOfNumbers;
	//Setup AVL Tree
	AVL avl1;
	vector<int> numsStorage;
	for (int i = 1; i <= numberOfNumbers; i++)
	{
		int temp;
		q1_readFile >> temp; //NOTE spaces and endlines are skipped in file reading ;)
		numsStorage.push_back(temp);
		avl1.insert(new TreeNode(temp));
	}

	//close read file
	q1_readFile.close();

	ofstream q1_writeFile;
	string q1_outputFileName = "output-q1a2.txt";
	// Opens and reads text file called "input-q1a2.txt"
	q1_writeFile.open(q1_outputFileName);

	// If file could not be opened, program will exit with an error message (AKA: Idiot proofing)
	if (!q1_writeFile.is_open())
		fileOpenedCheck_errorMessage(q1_outputFileName);

	avl1.writeToFile(avl1.root, q1_outputFileName);
	q1_writeFile.close();



	// Question 2 -------------------------------------------------------------------------
	ifstream q2_readFile;
	string q2_inputFileName = "input-q2a2.txt";
	// Opens and reads text file called "input-q2a2.txt"
	q2_readFile.open(q2_inputFileName);
	// If file could not be opened, program will exit with an error message (AKA: Idiot proofing)
	if (!q2_readFile.is_open())
		fileOpenedCheck_errorMessage(q2_inputFileName);

	ofstream q2_writeFile;
	string q2_outputFileName = "output-q2a2.txt";
	// Opens and reads text file called "output-q2a2.txt"
	q2_writeFile.open(q2_outputFileName);
	// If file could not be opened, program will exit with an error message (AKA: Idiot proofing)
	if (!q2_writeFile.is_open())
		fileOpenedCheck_errorMessage(q2_outputFileName);


	// Amount of numbers that needs to be sorted into an AVL tree
	q2_readFile >> numberOfNumbers;
	//Setup AVL Tree
	Heaps maxHeap;
	//clears the numsStorage so that we can reuse it
	numsStorage.clear();
	for (int i = 1; i <= numberOfNumbers; i++)
	{
		int temp;
		q2_readFile >> temp; //NOTE spaces and endlines are skipped in file reading ;)
		numsStorage.push_back(temp);
		maxHeap.Insert_Max_RTF(HeapNode(temp), q2_outputFileName);

	}
	//close read file
	q2_readFile.close();

	//close write file
	q2_writeFile.close();



	system("pause");
}


//Class: ADS 103
//Name: Matthew Pettett
//Student ID: A00051029


#include <iostream> //Input/Output stream
#include <string> // For usage of sting 
#include <vector>  // For storage
#include <fstream> //file reading/writing stuff

#include "BST.h"
#include "AVL.h"

using namespace std;

void fileOpenedCheck_errorMessage(string textFileName)
{
	cout << "\t!!ERROR!!" << endl;
	cout << "\Text file named '" << textFileName << "' was unable to be opened." << endl;
	exit(1);
};

int main() {
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
		avl1.insert(new StudentNode(temp));
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







	system("pause");
}


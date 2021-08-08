//Class: ADS 103
//Name: Matthew Pettett
//Student ID: A00051029

#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <fstream>

#include "HeapNode.h"


using namespace std;

class Heaps
{
public:

	vector<HeapNode> heap;
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyup(int index);
	void heapifyup_Max(int index);

	void heapifydown(int index);

	// inserts given elements to create either a min heap
	// or a max heap respectively.
	void Insert_Min(HeapNode element);
	void Insert_Max(HeapNode element);

	// inserts given elements to create a max heap 
	// but also writes it to a txt file.
	void Insert_Max_RTF(HeapNode element, string outputFileName);

	void DeleteMin();
	HeapNode* ExtractMin();
	void showHeap();
	int Size();

	void writeToFile(string outputFileName);

};


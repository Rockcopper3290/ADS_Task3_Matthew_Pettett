#include "Heaps.h"

int Heaps::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;
    if (leftIndex < heap.size())
        return leftIndex;
    else
        return -1;
}

int Heaps::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;
    if (rightIndex < heap.size())
        return rightIndex;
    else
        return -1;
}

int Heaps::parentIndex(int child)
{
    int parent = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return parent;
}

//after inserting, we heapifyup from where that new inserted player ended up
//compares current node to parent and swaps the smaller to the top
//recursive function, each swap means we call heapifyup on the next higher level
//where we swapped a value
void Heaps::heapifyup(int index)
{
    //IF index is not the root(top of the tree)
    //AND parent index within heap bounds (not negative)
    //AND current nodes rank less then parent nodes rank
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].heapElement < heap[parentIndex(index)].heapElement) {
        //if so, swap values between current node and parent
        swap(heap[index], heap[parentIndex(index)]);
        //since we swapped, lets run heapifyup again recursively on the parent from here
        heapifyup(parentIndex(index));
    }
}
void Heaps::heapifyup_Max(int index)
{

    //While index is not the root(top of the tree)
    //AND current nodes rank less then parent nodes rank
    while (index > 0 && heap[parentIndex(index)].heapElement < heap[index].heapElement) {

        // Swap parent and current node
        swap(heap[parentIndex(index)].heapElement, heap[index].heapElement);

        // Update i to parent of i
        index = parentIndex(index);
    }
}

//down is less efficient to up because we have to compare both children first before moving down
//usually called when destroyed root of tree
//recursive function, keeps calling itself as it swaps down the tree
void Heaps::heapifydown(int index)
{
    //get left and right children indexes
    int childL = leftChildIndex(index);
    int childR = rightChildIndex(index);
    //child variable representing path we'll compare down
    int childIndex = childL;
    //IF childL is not -1 AND childR is not -1
    //AND right childs rank is less then lefts
    if (childL >= 0 && childR >= 0 && heap[childR].heapElement < heap[childL].heapElement)
    {
        //make right child index the focus instead of left
        childIndex = childR;
    }

    //IF childIndex is not the root node and is not -1
    //AND current nodes bigger then child nodes 
    if (childIndex > 0 && heap[index].heapElement > heap[childIndex].heapElement)
    {
        //we should swap current with child, because we want smaller ones closer to the top
        swap(heap[index], heap[childIndex]);

        //recurse further down
        heapifydown(childIndex);
    }

}

//inserts at the lowest next free spot in the tree (this keeps things balanced :D)
void Heaps::Insert_Min(HeapNode element) {
    heap.push_back(element);
    heapifyup(Size() - 1);
}
void Heaps::Insert_Max(HeapNode element) {
    heap.push_back(element);
    heapifyup_Max(Size() - 1);
}
void Heaps::Insert_Max_RTF(HeapNode element, string outputFileName) {
    heap.push_back(element);
    writeToFile(outputFileName);
    heapifyup_Max(Size() - 1);
    writeToFile(outputFileName);
}

void Heaps::DeleteMin() {
    //cant delete if heap is empty
    if (heap.size() == 0)
    {
        cout << "Heap empty!" << endl;
        return;
    }
    //copy value in last element into root
    heap[0] = heap[heap.size() - 1];//heap.at(heap.size()-1);
    //delete last element
    heap.pop_back();
    //then heapifydown starting from root (index 0)
    heapifydown(0);
    cout << "Root Player deleted" << endl;

}
//get root player node from heap tree structure (or first element in our vector)
HeapNode* Heaps::ExtractMin() {
    //heap empty, no players to return
    if (heap.size() == 0)
        return NULL;
    else
    {
        //return &(heap.front());
        HeapNode* p = &(heap.front());//get memory address of player at front of array/heap
        return p;
    }
}
void Heaps::showHeap() {
    cout << "Heap -->";
    for (HeapNode p : heap)
    {
        cout << p.heapElement << " ";
    }
    cout << endl;
}
int Heaps::Size() {
    return heap.size();
}

void Heaps::writeToFile(string outputFileName)
{
    ofstream writeToFile;
    // Opens and reads text file called "input-q2a2.txt"
    // 'app' or append allows me to add text to a file without overwriting the file
    writeToFile.open(outputFileName, fstream::app);
    // If file could not be opened, program will exit with an error message (AKA: Idiot proofing)
    if (!writeToFile.is_open())
    {
        cout << "\t!!ERROR!!" << endl;
        cout << "\tOutput file named '" << outputFileName << "' was unable to be opened." << endl;
        exit(1);
    }

    for (HeapNode p : heap)
        writeToFile << p.heapElement << " ";

    writeToFile << endl;

    // closes the file that your writing to
    writeToFile.close();
}
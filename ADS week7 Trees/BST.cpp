#include "BST.h"

void BST::insert(StudentNode* newTreeElement)
{
    //IF the root is NULL(tree is empty), then make this treeElement the root
    if (root == NULL)
    {
        root = newTreeElement;
        return; //exit function early, we are done here
    }

    //some pointers to help us navigate the tree to find where to put the new treeElement
    StudentNode* current = root; //current node we're pointing at
    StudentNode* parent = NULL; //parent of current treeElement (A.K.A. node visitored last time)

    while (true)//infinite loop
    {
        //lets keep track of where we were before moving down further
        parent = current;
        //LEFT OR RIGHT?!
        //if the new treeElements (treeElement) is less then the treeElement at current node, then go down LEFT
        if (newTreeElement->treeElement < current->treeElement)
        {
            //< means we go down deeper into tree on left side
            current = current->leftChild;
            //if current is NULL, we just found an empty space to insert our new Student :D
            if (current == NULL)
            {
                //done, stick student here
                parent->leftChild = newTreeElement;
                return; //done, bail
            }
        }
        else
        {
            //go down right path
            current = current->rightChild;
            //if current is NULL, insert there
            if (current == NULL)
            {
                parent->rightChild = newTreeElement;
                return;
            }
        }
    }
}

StudentNode* BST::search(int treeElement, bool showSearchPath)
{
    //if tree empty, cant find student matching treeElement then
    if (root == NULL)
    {
        return NULL;
    }

    StudentNode* current = root;

    //keep looping until I find a match
    while (current->treeElement != treeElement)
    {
        

        if (showSearchPath)

        //havent found it yet, lefts explore left or right down in the tree
        if (treeElement < current->treeElement)
        {
            //go left
            current = current->leftChild;
        }
        else
        {
            //go right
            current = current->rightChild;
        }

        //if current is NULL, search treeElement cannot be found
        if (current == NULL)
        {
            return NULL;
        }

    }

    return current; //should be pointing to match in tree :D
}

//outputs stuff in the tree in ascending order :D
void BST::inOrderTraversal(StudentNode* current)
{
    //current == null is end of this branch path, this if
    //stops from infinite looping
    if (current != NULL)
    {
        inOrderTraversal(current->leftChild);
        inOrderTraversal(current->rightChild);
    }
}

void BST::preOrderTraversal(StudentNode* current)
{
    if (current != NULL)
    {
        preOrderTraversal(current->leftChild);
        preOrderTraversal(current->rightChild);
    }
}

void BST::postOrderTraversal(StudentNode* current)
{
    if (current != NULL)
    {
        postOrderTraversal(current->leftChild);
        postOrderTraversal(current->rightChild);
    }
}

//referenced second algorithm here https://www.geeksforgeeks.org/level-order-tree-traversal/
void BST::show(StudentNode* p)
{
    // Base Case
    if (root == NULL) return;

    // Create an empty queue for level order traversal
    queue<StudentLevelNode> q;

    // Enqueue Root and initialize height
    q.push(StudentLevelNode(root, 0));

    int previousOutputLevel = -1;

    while (q.empty() == false)
    {
        //Print front of queue and remove it from queue
        StudentLevelNode node = q.front();
        if (node.level != previousOutputLevel)
        {
            cout << endl;
            cout << node.level << "- ";
            previousOutputLevel = node.level;
        }
        cout << node.student->treeElement<< " ";
        q.pop();

        /* Enqueue left child */
        if (node.student->leftChild != NULL)
            q.push(StudentLevelNode(node.student->leftChild, node.level + 1));

        /* Enqueue right child */
        if (node.student->rightChild != NULL)
            q.push(StudentLevelNode(node.student->rightChild, node.level + 1));

    }
}

void BST::writeToFile(StudentNode* p, string outputFileName)
{
    ofstream writeToFile;
    // Opens and reads text file called "input-q1a2.txt"
    writeToFile.open(outputFileName);
    // If file could not be opened, program will exit with an error message (AKA: Idiot proofing)
    if (!writeToFile.is_open())
    {
        cout << "\t!!ERROR!!" << endl;
        cout << "\tOutput file named '" << outputFileName << "' was unable to be opened." << endl;
        exit(1);
    }

    // Base Case
    if (root == NULL) return;

    // Create an empty queue for level order traversal
    queue<StudentLevelNode> q;

    // Enqueue Root and initialize height
    q.push(StudentLevelNode(root, 0));

    int previousOutputLevel = -1;

    while (q.empty() == false)
    {
        //Print front of queue and remove it from queue
        StudentLevelNode node = q.front();
        if (node.level != previousOutputLevel)
        {
            writeToFile << endl;
            writeToFile << node.level << "- ";
            previousOutputLevel = node.level;
        }
        writeToFile << node.student->treeElement << " ";
        q.pop();

        /* Enqueue left child */
        if (node.student->leftChild != NULL)
            q.push(StudentLevelNode(node.student->leftChild, node.level + 1));

        /* Enqueue right child */
        if (node.student->rightChild != NULL)
            q.push(StudentLevelNode(node.student->rightChild, node.level + 1));
    }

    // closes the file that your writing to
    writeToFile.close();
}




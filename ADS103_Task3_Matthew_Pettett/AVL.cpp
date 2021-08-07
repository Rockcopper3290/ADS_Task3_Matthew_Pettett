#include "AVL.h"

//using recursion, we keep exploring down, and pass final height values up
int AVL::height(TreeNode* node)
{
    int h = 0;
    //helps break recursion cycle when we get to nulls at the bottom of branches
    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);

        //max gets biggest of the 2 and discards the smaller
        int maxH = max(leftH, rightH);
        h = maxH + 1;
    }
    return h;
}

int AVL::difference(TreeNode* node)
{
    //if empty treee, well its balanced, its 0
    if (node == NULL)
        return 0;

    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balanceFactor = leftH - rightH;

    return balanceFactor;
}

TreeNode* AVL::RRrotation(TreeNode* parent)
{
    TreeNode* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;

    return temp;
}

TreeNode* AVL::LLrotation(TreeNode* parent)
{
    TreeNode* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;

    return temp;
}
//needs 2 rotations,
//first rotation rotates bottom 2 nodes which turns the whole structure into a RR rotation
//second rotation uses RRrotation
TreeNode* AVL::LRrotation(TreeNode* parent)
{
    TreeNode* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    return LLrotation(parent);
}

TreeNode* AVL::RLrotation(TreeNode* parent)
{
    TreeNode* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);

    return RRrotation(parent);
}

TreeNode* AVL::balance(TreeNode* parent)
{
    //get balance factor
    int balanceFactor = difference(parent);

    //IF balanceFactor not within -1,0,1, then lets work out what rotations to do
    if (balanceFactor > 1)
    {
        //left branch is heavy, now work out is left or right child heavy
        if (difference(parent->leftChild) > 0)
        {
            //left child unbalanced
            parent = LLrotation(parent);
        }
        else
        {
            //right child unbalanced
            parent = LRrotation(parent);
        }
    }
    else if (balanceFactor < -1)
    {
        //right branch is heavy, but which child
        if (difference(parent->rightChild) > 0)
        {
            //left child heavy
            parent = RLrotation(parent);
        }
        else
        {
            //right child heavy
            parent = RRrotation(parent);
        }
    }


    return parent;
}

TreeNode* AVL::insertAVL(TreeNode* parent, TreeNode* newTreeElement)
{
    //if sub tree empty, this becomes the parent
    if (parent == NULL)
    {
        parent = newTreeElement;
        return parent;
    }

    //parent not null, so we haven't found an empty space to stick new student yet
    //so we need to go down either left or right path
    if (newTreeElement->treeElement < parent->treeElement)
    {
        parent->leftChild = insertAVL(parent->leftChild, newTreeElement);
        parent = balance(parent);
        return parent;
    }
    else //assume id >= parent's id
    {
        parent->rightChild = insertAVL(parent->rightChild, newTreeElement);
        parent = balance(parent);
        return parent;
    }
}

void AVL::insert(TreeNode* newTreeElement)
{
    root = insertAVL(root, newTreeElement);
}

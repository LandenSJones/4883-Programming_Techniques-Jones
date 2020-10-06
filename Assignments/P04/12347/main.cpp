//Landen Jones
//UVA12347
//This program recieves input data in the form of pre-order. We build the tree based upon this, and we print out in post order.
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
//Node that will represent a node in a binary tree. It will have possible variables of both left and right children.
//It will also contain a value, and a boolean that will show if there has already been a variable assigned to either child.
struct node
{
    node *left, *right;
    bool hasLeft, hasRight;
    int value;
    node(int newValue)
    {     hasLeft = false;
          hasRight = false;
          value = newValue;
    }
};
//This function recursively finds the correct node that is being created. 
void Assign(node *currentNode, int value)
{
    //If it is the first node being placed, we set a new head node.
    if (currentNode->value == 0)
        currentNode->value = value;
    //If the value is lower, we traverse right, and recursively decide the rest (left/right)
    else if (value < currentNode->value)
    {
        if (!currentNode->hasLeft)
        {
            node *newNode = new node(value);
            currentNode->left = newNode;
            currentNode->hasLeft = true;
        }

        else
            Assign(currentNode->left, value);
    }
    //If the value is anything else(greater), we traverse right, and recursively decide the rest (left/right)
    else
    {
        if (!currentNode->hasRight)
        {
            node *newNode = new node(value);
            currentNode->right = newNode;
            currentNode->hasRight = true;
        }
        else
            Assign(currentNode->right, value);
    }
}
//Prints Post-Order
void PrintOut(node *&current)
{
    if (current->hasLeft)
        PrintOut(current->left);
    if (current->hasRight)
        PrintOut(current->right);
    cout << current->value << '\n';
}
int main()
{
    ifstream infile;
    //infile.open("input");
    //We set base node to 0, given thath it is possible that we have no input.
    node *baseNode = new node(0);
    int current;
    while (cin >> current)
        Assign(baseNode, current);
    PrintOut(baseNode);
    return 0;
}

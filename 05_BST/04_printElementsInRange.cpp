#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

binaryTreeNode<int> *takeInputLevelWise()
{
    queue<binaryTreeNode<int> *> pendingNodes;
    // cout<<"Enter root data"<<endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            binaryTreeNode<int> *leftChild = new binaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        // cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            binaryTreeNode<int> *rightChild = new binaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printLevelWise(binaryTreeNode<int> *root)
{
    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        else
        {
            cout << "L:-1,";
        }
        if (front->right != NULL)
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << "R:-1";
        }
        cout << endl;
    }
}

void printElementsInRange(binaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }

    if (k1 <= root->data && k2 >= root->data)
    {
        printElementsInRange(root->left, k1, k2);
        cout << root->data << " ";
        printElementsInRange(root->right, k1, k2);
    }
    else if (k1 > root->data)
    {
        printElementsInRange(root->right, k1, k2);
    }
    else if (k2 < root->data)
    {
        printElementsInRange(root->left, k1, k2);
    }
    
    
}

int main()
{

    // 5 3 7 1 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1
    binaryTreeNode<int> *root = takeInputLevelWise();
    int k1, k2;
    cin >> k1 >> k2;
    printElementsInRange(root, k1, k2);

    return 0;
}
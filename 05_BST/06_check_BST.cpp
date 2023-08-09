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
binaryTreeNode<int> * maxNode(binaryTreeNode<int> * root){
    binaryTreeNode<int> *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int minimum(binaryTreeNode<int> * root){
    if(root == NULL){
        return INT8_MAX;
    }
    return min(root->data , min(minimum(root->left), minimum(root->right)));
}

int maximum(binaryTreeNode<int> * root){
    if(root == NULL){
        return INT8_MIN;
    }
    return max(root->data , max(maximum(root->left), maximum(root->right)));
}

bool checkBST(binaryTreeNode<int> * root){
    
    if(root == NULL){
        return true;
    }

    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);
    bool output = (root->data > leftmax) && (root->data < rightmin) && checkBST(root->left) && checkBST(root->right);
    
    return output;
}
int main()
{

    // 5 3 7 1 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1
    binaryTreeNode<int> *root = takeInputLevelWise();
    // cout<<maximum(root)<<endl;
    // cout<<minimum(root)<<endl;
    cout<<checkBST(root)<<endl;

    return 0;
}
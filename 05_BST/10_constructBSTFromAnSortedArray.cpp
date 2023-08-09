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

void printPreOrderWise(binaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreOrderWise(root->left);
    printPreOrderWise(root->right);
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

binaryTreeNode<int> * constructBST(int arr[], int si,int ei){
    if(si > ei){
        return NULL;
    }
    int targetIndex = (si+ei)/2;
    binaryTreeNode<int> * root = new binaryTreeNode<int>(arr[targetIndex]);
    binaryTreeNode<int> *leftRoot = constructBST(arr,si,targetIndex-1);
    binaryTreeNode<int> * rightRoot = constructBST(arr,targetIndex+1,ei);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}

int main()
{

    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    int n,arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    binaryTreeNode<int> * root = constructBST(arr,0,n-1);
    printPreOrderWise(root);
    
    return 0;
}
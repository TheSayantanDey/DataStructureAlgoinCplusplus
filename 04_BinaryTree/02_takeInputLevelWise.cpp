#include<iostream>
#include <queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int> * takeInputLevelWise(){
    queue<binaryTreeNode<int> *> pendingNodes;
    cout<<"Enter root data"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    binaryTreeNode<int> * root = new binaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        binaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            binaryTreeNode<int> * leftChild = new binaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            binaryTreeNode<int> * rightChild = new binaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;

}
binaryTreeNode<int> * takeInput(){
    int nodeData;
    cin>>nodeData;
    if(nodeData == -1){
        return NULL;
    }
    binaryTreeNode<int> * root = new binaryTreeNode<int>(nodeData);
    binaryTreeNode<int> *leftChild = takeInput();
    binaryTreeNode<int> *rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

void printTree(binaryTreeNode<int> * root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

int main(){

    binaryTreeNode<int> * root = takeInputLevelWise();

    printTree(root);

    delete root;

    return 0;
}
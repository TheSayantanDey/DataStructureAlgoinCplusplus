#include<iostream>
#include "binaryTreeNode.h"
using namespace std;

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

    binaryTreeNode<int> * root = takeInput();

    printTree(root);

    delete root;

    return 0;
}
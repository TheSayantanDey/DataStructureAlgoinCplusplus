#include<iostream>
#include "binaryTreeNode.h"
using namespace std;

int main(){

    binaryTreeNode<int> * root = new binaryTreeNode<int>(1);
    binaryTreeNode<int> * node1 = new binaryTreeNode<int>(2);
    binaryTreeNode<int> * node2 = new binaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;


    return 0;
}
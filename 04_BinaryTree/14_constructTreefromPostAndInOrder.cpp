#include<iostream>
#include <queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int> * takeInputLevelWise(){
    queue<binaryTreeNode<int> *> pendingNodes;
    // cout<<"Enter root data"<<endl;
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
        // cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            binaryTreeNode<int> * leftChild = new binaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        // cout<<"Enter right child of "<<front->data<<endl;
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

void printLevelWise(binaryTreeNode<int> * root){
    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left != NULL){
            cout<<"L:"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }else{
            cout<<"L:-1,";
        }
        if(front->right != NULL){
            cout<<"R:"<<front->right->data;
            pendingNodes.push(front->right);
        }else{
            cout<<"R:-1";
        }
        cout<<endl;
    }
}

binaryTreeNode<int> * constructTree(int *postOrder,int *inOrder,int postS ,int postE,int inS,int inE){
    //BaseCase
    if(inS>inE){
        return NULL;
    }
    //Creating the ROOT
    binaryTreeNode<int> * root = new binaryTreeNode<int>(postOrder[postE]); 

    //Finding out Left sub-Tree's postOrder and inOrder array indexes for Left sub-tree's recursive call
    int LpostS = postS;
    int LinS = inS;
    int inOrderRootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(inOrder[i] == root->data){
            inOrderRootIndex = i;
            break;
        }
    }
    int LinE = inOrderRootIndex-1;
    int LpostE = LinE - LinS + LpostS;

    //Finding out right sub-Tree's postOrder and inOrder array indexes for Right sub-tree's recursive call
    int RpostS = LpostE+1;
    int RpostE = postE-1;
    int RinS = inOrderRootIndex+1;
    int RinE = inE;

    //Making recursive calls for the subTrees
    binaryTreeNode<int> * leftChild = constructTree(postOrder,inOrder,LpostS,LpostE,LinS,LinE);
    binaryTreeNode<int> * rightChild = constructTree(postOrder,inOrder,RpostS,RpostE,RinS,RinE);

    //Connecting the subtrees with the ROOT
    root->left = leftChild;
    root->right = rightChild;
    
    //Returing the ROOT
    return root;
}

int main(){
/*
9
1 2 4 5 3 6 8 9 7
4 2 5 1 8 6 9 3 7
*/
    int n;
    cin>>n;
    int *postOrder = new int[n];
    int *inOrder = new int[n];

    for(int i=0;i<n;i++){
        cin>>postOrder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inOrder[i];
    }

    binaryTreeNode<int> * root = constructTree(postOrder,inOrder,0,n-1,0,n-1);
    printLevelWise(root);
    
    delete [] postOrder;
    delete [] inOrder;
    delete root;

    return 0;
}
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

binaryTreeNode<int> * constructTree(int *preOrder,int *inOrder,int preS ,int preE,int inS,int inE){
    //BaseCase
    if(inS>inE){
        return NULL;
    }
    //Creating the ROOT
    binaryTreeNode<int> * root = new binaryTreeNode<int>(preOrder[preS]); 

    //Finding out Left sub-Tree's preOrder and inOrder array indexes for Left sub-tree's recursive call
    int LpreS = preS+1;
    int LinS = inS;
    int inOrderRootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(inOrder[i] == root->data){
            inOrderRootIndex = i;
            break;
        }
    }
    int LinE = inOrderRootIndex-1;
    int LpreE = LinE - LinS + LpreS;

    //Finding out right sub-Tree's preOrder and inOrder array indexes for Right sub-tree's recursive call
    int RpreS = LpreE+1;
    int RpreE = preE;
    int RinS = inOrderRootIndex+1;
    int RinE = inE;

    //Making recursive calls for the subTrees
    binaryTreeNode<int> * leftChild = constructTree(preOrder,inOrder,LpreS,LpreE,LinS,LinE);
    binaryTreeNode<int> * rightChild = constructTree(preOrder,inOrder,RpreS,RpreE,RinS,RinE);

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
    int *preOrder = new int[n];
    int *inOrder = new int[n];

    for(int i=0;i<n;i++){
        cin>>preOrder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inOrder[i];
    }

    binaryTreeNode<int> * root = constructTree(preOrder,inOrder,0,n-1,0,n-1);
    printLevelWise(root);
    
    delete [] preOrder;
    delete [] inOrder;
    delete root;

    return 0;
}
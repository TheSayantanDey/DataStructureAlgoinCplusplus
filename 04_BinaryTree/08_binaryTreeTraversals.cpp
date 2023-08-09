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

void preOrder(binaryTreeNode<int>  * root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(binaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(binaryTreeNode<int> * root){
    if(root == NULL){
        return ;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void levelOrder(binaryTreeNode<int> * root){
    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" ";
        if(front->left != NULL){
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            pendingNodes.push(front->right);
        }
    }
}

int main(){
    //1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    binaryTreeNode<int> * root = takeInputLevelWise();
    // preOrder(root);
    // postOrder(root);
    // inOrder(root);
    levelOrder(root);
    delete root;
    return 0;
}
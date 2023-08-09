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
int height(binaryTreeNode<int> * root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(leftHeight>rightHeight){
        return 1+leftHeight;
    }else{
        return 1+rightHeight;
    }
}
bool balenced(binaryTreeNode<int> * root){
    if(root == NULL){
        return true;
    }
    if(height(root->left)-height(root->right) <= 1 && height(root->left)-height(root->right) >= -1){
        bool isLeftBalenced = balenced(root->left);
        bool isRightBalenced = balenced(root->right);
        if(isLeftBalenced && isRightBalenced){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
pair<bool,int> balencedBetter(binaryTreeNode<int> * root){
    if(root == NULL){
        pair<bool,int> ans;
        ans.first = true;
        ans.second = 0;
        return ans;
    }
    
    pair<bool,int> leftChild = balencedBetter(root->left);
    pair<bool,int> rightChild = balencedBetter(root->right);

    if(leftChild.second - rightChild.second <= 1 && leftChild.second - rightChild.second >= -1){
        if(leftChild.first && rightChild.first){
            pair<bool,int> ans;
            ans.first = true;
            ans.second = 1+max(leftChild.second,rightChild.second);
            return ans;
        }else{
            pair<bool,int> ans;
            ans.first = false;
            ans.second = 1+max(leftChild.second,rightChild.second);
            return ans;
        }
    }else{
        pair<bool,int> ans;
        ans.first = false;
        ans.second = 1+max(leftChild.second,rightChild.second);
        return ans;
    }
}

int main(){
    //1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    binaryTreeNode<int> * root = takeInputLevelWise();
    cout<<balencedBetter(root).first<<endl;

    delete root;
    return 0;
}
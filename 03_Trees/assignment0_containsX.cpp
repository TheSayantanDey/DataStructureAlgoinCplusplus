#include<iostream>
#include <queue>
#include "02_TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise(){
    int rootData;
    // cout<<"Enter Data"<<endl;
    cin>>rootData; //Taking the Root Input
    TreeNode<int> * root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes; 
    pendingNodes.push(root); //Puting the root in the queue

    while(!pendingNodes.empty()){
        TreeNode<int> * front = pendingNodes.front(); //Taking out the front element of the queue
        pendingNodes.pop(); //Deletion of front
        // cout<<"Enter number of children of "<<front->data<<endl;
        int numChild; 
        cin>>numChild; //Taking input of the number of children of the front node
        for(int i=0;i<numChild;i++){
            int childData;
            // cout<<"Enter "<<i<<"th data of "<<front->data<<endl;
            cin>>childData; //Taking input of the data of children of the front node
            TreeNode<int> * child = new TreeNode<int>(childData);
            front->children.push_back(child); //Connecting the child node which front(Parent Node)
            pendingNodes.push(child); //Inserting the child node in the queue for further operations
        }
    }
    return root;
}


void printTreeLevelWise(TreeNode<int> *root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root); //Pushing root to the queue
    while(pendingNodes.size() != 0){
        TreeNode<int> * front = pendingNodes.front(); //Taking out the front element of the queue
        pendingNodes.pop(); //Deletion of front
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            pendingNodes.push(front->children[i]); //Inserting the child node in the queue for further operations
        }
        cout<<endl;
    }
}

bool containsX(TreeNode<int> * root,int x){
    if(x == root->data){
        return true;
    }else{
        for(int i=0;i<root->children.size();i++){
            if(containsX(root->children[i],x)){
                return true;
            }
        }
    }
    return false;
}

int main(){

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> * root = takeInputLevelWise();
    int x;
    cin>>x;

    if(containsX(root,x)){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
    delete root;
    return 0;
}
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

int getHeight(TreeNode<int> * root){
    if(root == NULL){
        return 0;
    }
    int maxHeight = 0;
    for(int i=0;i<root->children.size();i++){
        int smallOutput = getHeight(root->children[i]);
        if(maxHeight < smallOutput){
            maxHeight = smallOutput;
        }
    }
    return maxHeight+1;
}

int main(){

    TreeNode<int> * root = takeInputLevelWise();
    cout<<getHeight(root)<<endl;
    
    return 0;
}
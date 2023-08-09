#include<iostream>
#include <queue>
#include "02_TreeNode.h"

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

bool isStructurallyIdentical(TreeNode<int> * root1 ,TreeNode<int> * root2){
    bool condition1,condition2,condition3=true;
    if(root1->data != root2->data){
        return false;
    }else{
        condition1 = true;
    }

    if(root1->children.size() != root2->children.size()){
        return false;
    }else{
        condition2 = true;
    }

    for(int i=0;i<root1->children.size();i++){
        bool condition4;
        if(isStructurallyIdentical(root1->children[i],root2->children[i])){
            condition4 = true;
        }else{
            condition4 = false;
        }

        if(condition3 == true && condition4 == true){
            condition3 = true;
        }else{
            condition3 = false;
        }
    }

    if(condition1 == true && condition2 == true && condition3 == true){
        return true;
    }else{
        return false;
    }
    
    
    
}

int main(){

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> * root1 = takeInputLevelWise();
    TreeNode<int> * root2 = takeInputLevelWise();
    cout<<isStructurallyIdentical(root1,root2);
    
    return 0;
}
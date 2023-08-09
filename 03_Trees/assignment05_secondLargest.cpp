#include<iostream>
#include <queue>
#include "02_TreeNode.h"

class Pair{
    public:

    int maxElem;
    int secondMaxElem;

    Pair(int maxElem,int secondMaxElem){
        this->maxElem = maxElem;
        this->secondMaxElem = secondMaxElem;
    }
};

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
//DONE
Pair * getSecondMaxElem(TreeNode<int> * root){
    Pair * ans = new Pair(root->data,0);
    // cout<<root->data<<" "<<ans->maxElem<<" "<<ans->secondMaxElem<<endl;

    for(int i=0;i<root->children.size();i++){
        Pair * temp = getSecondMaxElem(root->children[i]);
        // cout<<"test"<<endl;
        if(ans->secondMaxElem == 0 && temp->secondMaxElem == 0){
            if(ans->maxElem > temp->maxElem){
                ans->secondMaxElem = temp->maxElem;
                // cout<<"Test2"<<endl;
            }else{
                int x = ans->maxElem;
                ans->maxElem = temp->maxElem;
                ans->secondMaxElem = x;
            }
        }
        else if(ans->secondMaxElem == 0){
            if(ans->maxElem > temp->maxElem){
                ans->secondMaxElem = temp->maxElem;
            }else{
                int x = ans->maxElem;
                ans->maxElem = temp->maxElem;
                if(x>temp->secondMaxElem){
                    ans->secondMaxElem = x;
                }else{
                    ans->secondMaxElem = temp->secondMaxElem;
                }
            }
        }
        else if(temp->secondMaxElem == 0){
            if(ans->maxElem > temp->maxElem){
                if(temp->maxElem > ans->secondMaxElem){
                    ans->secondMaxElem = temp->maxElem;
                }
                // cout<<"test3"<<endl;
            }else{
                int x = ans->maxElem;
                ans->maxElem = temp->maxElem;
                ans->secondMaxElem = x;
            }
        }
        else{
            if(ans->maxElem > temp->maxElem){
                if(temp->maxElem > ans->secondMaxElem){
                    ans->secondMaxElem = temp->maxElem;
                }
            }else{
                int x = ans->maxElem;
                ans->maxElem = temp->maxElem;
                ans->secondMaxElem = x;
            }
        }
    }
    return ans;
}

int getSecondMaxElementHelper(TreeNode<int> *root){
    Pair * ans = getSecondMaxElem(root);
    return ans->secondMaxElem;
}
int main(){

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> * root = takeInputLevelWise();
    cout<<getSecondMaxElementHelper(root)<<endl;
    
    return 0;
}
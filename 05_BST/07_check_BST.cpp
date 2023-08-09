#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

binaryTreeNode<int> *takeInputLevelWise()
{
    queue<binaryTreeNode<int> *> pendingNodes;
    // cout<<"Enter root data"<<endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            binaryTreeNode<int> *leftChild = new binaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        // cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            binaryTreeNode<int> *rightChild = new binaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printLevelWise(binaryTreeNode<int> *root)
{
    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        else
        {
            cout << "L:-1,";
        }
        if (front->right != NULL)
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << "R:-1";
        }
        cout << endl;
    }
}
binaryTreeNode<int> * maxNode(binaryTreeNode<int> * root){
    binaryTreeNode<int> *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

pair<pair<int,int>,bool> checkBST_better(binaryTreeNode<int> * root){ 
    //Assuming first int is max and second is min
    if(root == NULL){
        pair<pair<int,int>,bool> ans ;
        ans.first.first = INT32_MIN;
        ans.first.second = INT32_MAX;
        ans.second = true;
        return ans;
    }

    pair<pair<int,int>,bool> leftAns = checkBST_better(root->left);
    pair<pair<int,int>,bool> rightAns = checkBST_better(root->right);
    int minimum = min(root->data , min(leftAns.first.second,rightAns.first.second));
    int maximum = max(root->data , max(leftAns.first.first,rightAns.first.first));
    pair<pair<int,int>,bool> finalAns;
    finalAns.first.first = maximum;
    finalAns.first.second = minimum;
    
    if(root->data > leftAns.first.first && root->data < rightAns.first.second && leftAns.second == true && rightAns.second == true){
        finalAns.second = true;
    }else{
        finalAns.second = false;
    }

    return finalAns;

}

bool checkBST_better_helper(binaryTreeNode<int> * root){
    pair<pair<int,int>,bool> finalans = checkBST_better(root);
    return finalans.second;
}

int main()
{

    // 15 3 7 1 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1
    binaryTreeNode<int> *root = takeInputLevelWise();

    cout<<checkBST_better(root).first.first<<endl;
    cout<<checkBST_better(root).first.second<<endl;
    cout<<checkBST_better_helper(root)<<endl;

    return 0;
}
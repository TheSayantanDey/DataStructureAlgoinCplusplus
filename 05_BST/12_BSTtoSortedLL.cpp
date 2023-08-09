#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node * next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

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

Node<int> * BSTtoLL(binaryTreeNode<int> * root){
    if(root == NULL){
        return NULL;
    }

    Node<int> * leftLLHead = BSTtoLL(root->left);
    Node<int> * rightLLHead = BSTtoLL(root->right);
    Node<int> * midNode = new Node<int>(root->data);

    Node<int> * head = NULL;
    if(leftLLHead == NULL){
        head = midNode;
    }else{
        head = leftLLHead;
    }

    Node<int> * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = midNode;
    midNode->next = rightLLHead;

    return head;
}

pair<Node<int> *,Node<int> *> BSTtoLL_better(binaryTreeNode<int> * root){
    if(root == NULL){
        pair<Node<int> *,Node<int> *> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }

    pair<Node<int> *,Node<int> *> leftLL = BSTtoLL_better(root->left);
    pair<Node<int> *,Node<int> *> rightLL = BSTtoLL_better(root->right);
    Node<int> * midNode = new Node<int>(root->data);

    Node<int> * head = NULL;

    if(leftLL.second != NULL){
        leftLL.second = midNode;
        head = leftLL.first;
    }else{
        head = midNode;
    }

    midNode->next = rightLL.first;

    pair<Node<int> *,Node<int> *> finalAns;
    finalAns.first = head;

    if(rightLL.first == NULL){
        finalAns.second = midNode;
    }else{
        finalAns.second = rightLL.second;
    }
    return finalAns;
}

void printLL(Node<int> * head){
    Node<int> * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{

    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    binaryTreeNode<int> * root = takeInputLevelWise();
    Node<int> * head = BSTtoLL(root);
    printLL(head);
    
    return 0;
}
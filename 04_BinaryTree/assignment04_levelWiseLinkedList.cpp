#include<iostream>
#include <vector>
#include <queue>
#include "binaryTreeNode.h"
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node * next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};
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
void printLL(Node<int> * head){
    Node<int> * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
vector<Node<int> *> * levelWiseLinkedList(binaryTreeNode<int> * root){
    vector<Node<int>*> * v = new vector<Node<int>*>;
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node<int> * head = NULL;
    Node<int> * tail = NULL;
    while(pendingNodes.size() != 0){
        binaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL){
            if(pendingNodes.size()==0){
                break;
            }
            head = NULL;
            tail = NULL;
            pendingNodes.push(NULL);
        }
        else{
            Node<int> * newNode = new Node<int>(front->data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                v->push_back(head);
            }else{
                tail->next = newNode;
                tail = tail->next;
            }

            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right != NULL){
                pendingNodes.push(front->right);
            }
        }
    }
    return v;
}

int main(){
    //1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    binaryTreeNode<int> * root = takeInputLevelWise();
    vector<Node<int> *> * v = levelWiseLinkedList(root);
    for(int i=0;i<v->size();i++){
        printLL(v->at(i));
    }

    delete root;
    return 0;
}
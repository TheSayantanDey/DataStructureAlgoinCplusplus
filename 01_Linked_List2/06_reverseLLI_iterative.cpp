#include "node.cpp"
#include<iostream>
using namespace std;

class Pair{
    public:

    Node *head;
    Node *tail;
};

Node * reverseLL_4(Node *head){
    Node *current = head;
    Node *nextNode = head->next;
    Node *prev = nullptr;
    while(1){
        current->next = prev;
        prev = current;
        current = nextNode;
        if(nextNode == nullptr){
            break;
        }
        nextNode = nextNode->next;
    }
    return prev;
}
Node * takeinput_better(){
    int data;
    cin>>data;
    Node *head = nullptr;
    Node *tail = nullptr;
    while(data != -1){
        Node *n = new Node(data);
        if(head == nullptr){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    Node *temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node *head = takeinput_better();
    head = reverseLL_4(head);
    print(head);

    return 0;
}
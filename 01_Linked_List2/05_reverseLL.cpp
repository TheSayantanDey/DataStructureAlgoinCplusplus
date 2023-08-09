#include "node.cpp"
#include<iostream>
using namespace std;

class Pair{
    public:

    Node *head;
    Node *tail;
};

Node * reverseLL_3(Node *head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node *smallAns = reverseLL_3(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = nullptr;
    return smallAns;
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
    head = reverseLL_3(head);
    print(head);

    return 0;
}
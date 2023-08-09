#include "node.cpp"
#include<iostream>
using namespace std;
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
Node * reverseLL(Node *head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node *smallAns = reverseLL(head->next);
    Node *temp = smallAns;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head;
    head->next = nullptr;
    return smallAns;
}
int main(){

    Node *head = takeinput_better();
    Node *head = reverseLL(head);
    print(head);

    return 0;
}
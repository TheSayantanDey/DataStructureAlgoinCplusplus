#include "node.cpp"
#include<iostream>
using namespace std;

Node * evenAfterOdd(Node *head){
    Node *temp = head;
    Node *oddHead = nullptr;
    Node *evenHead = nullptr;
    Node *oddTail = nullptr;
    Node *evenTail = nullptr;

    while(temp != nullptr){
        if(temp->data % 2 == 0){
            if(evenHead == nullptr){
                evenHead = temp;
                evenTail = temp;
            }else{
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }else{
            if(oddHead == nullptr){
                oddHead = temp;
                oddTail = temp;
            }else{
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
    }
    if(evenTail != nullptr){
        evenTail->next = nullptr;
    }
    if(oddTail != nullptr){
        oddTail->next = nullptr;
    }
    if(oddTail != nullptr){
        oddTail->next = evenHead;
        return oddHead;
    }else{
        return evenHead;
    }
    // evenHead = oddHead;
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
    if(temp == nullptr){
        return;
    }
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int main(){

    Node *head = takeinput_better();
    head = evenAfterOdd(head);
    print(head);

    return 0;
}
#include<iostream>
using namespace std;
//Doubly LL should have both prev and a next pointer
class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
//Class for returning both head and tail pointer
class Pair{
    public:
    Node *head;
    Node *tail;
};
//Taking input and returning both head and tail 
Pair takeinput_better(){
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
            n->prev = tail; //Connecting with the prev pointer
            tail = tail->next;

        }
        cin>>data;
    }
    Pair finalLL;
    finalLL.head = head;
    finalLL.tail = tail;

    return finalLL;
}

void print(Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reversePrint(Node* tail){
    Node *temp = tail;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}


int main(){

/*
    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);

    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    Node *tail = &n5;
    n5.prev = &n4;
    n4.prev = &n3;
    n3.prev = &n2;
    n2.prev = &n1;

    print(head);
    reversePrint(tail);
*/
    Pair finalLL = takeinput_better();
    print(finalLL.head);
    reversePrint(finalLL.tail);
    

    return 0;
}
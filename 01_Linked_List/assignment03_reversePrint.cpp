#include<iostream>
using namespace std;
#include "node.cpp"

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

    void reversePrint(Node *head){
        Node *temp = head;
        if(temp == nullptr){
            return;
        }
        reversePrint(temp->next);
        cout<<temp->data<<" ";
        return;
    }
int main(){

    Node *head = takeinput_better();
    reversePrint(head);

    return 0;
}
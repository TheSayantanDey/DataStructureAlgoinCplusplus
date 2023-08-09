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

Node * deleteNode(Node *head , int i){
    Node *temp = head;
    if(temp == nullptr){
        return head;
    }
    if(i==0){
        temp = temp->next;
        return temp;
    }
    Node *smallLLHead = deleteNode(temp->next,i-1);
    temp->next = smallLLHead;
    return temp;
    
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
    int i;
    cin>>i;
    head = deleteNode(head,i);
    print(head);

    return 0;
}
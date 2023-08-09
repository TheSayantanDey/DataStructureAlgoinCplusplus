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

Node * insertNode(Node *head , int i,int data){
    
    Node *temp = head;
    if(temp == nullptr){
        return temp;
    }
    if(i==0){
        Node*n = new Node(data);
        n->next = temp;
        temp = n;
        return temp;
    }
    Node *smallListHead = insertNode(temp->next,i-1,data);
    temp->next = smallListHead;
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
    int i,data;
    cin>>i>>data;
    head = insertNode(head,i,data);
    print(head);

    return 0;
}
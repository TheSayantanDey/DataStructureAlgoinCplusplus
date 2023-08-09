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

    void print(Node *head){
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    Node *insertNode(Node *head , int i , int data){
        Node *newNode = new Node(data);
        int count =0;
        Node *temp = head;
        if(i==0){
            newNode->next = head;
            head = newNode;
            return head;
        }
        while(temp != nullptr && count < i-1){
            temp = temp->next;
            count++;
        }
        if(temp != nullptr){
            newNode->next = temp->next;
            temp->next = newNode;
        }
        return head;
    }

int main(){
    cout<<"Enter the elements of desired Linked List : ";
    Node *head = takeinput_better();
    cout<<"The Linked List is : ";
    print(head);
    int data,i;
    cout<<"Enter new data : ";
    cin>>data;
    cout<<"Enter position : ";
    cin>>i;
    head = insertNode(head , i , data);
    print(head);
    return 0;
}
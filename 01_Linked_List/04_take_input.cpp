#include<iostream>
using namespace std;
#include "node.cpp"

    Node * takeinput(){
        int data;
        cin>>data;
        Node *head = nullptr;
        while(data != -1){
            Node *n = new Node(data);
            if(head == nullptr){
                head = n;
            }else{
                Node *temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = n;
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

    Node *head = takeinput();
    print(head);

    return 0;
}
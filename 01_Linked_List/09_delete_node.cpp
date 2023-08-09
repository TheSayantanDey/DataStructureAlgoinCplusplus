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

    Node *deleteNode(Node *head , int i){
        int count = 0;
        Node *temp = head;

        if(i==0){
            head = head->next;
            return head;
        }

        while(count < i-1){
            if(temp!=nullptr){
                return head;
            }
            temp = head->next;
            count++;
        }
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
        return head;
    }

int main(){
    cout<<"Enter the elements of desired Linked List : ";
    Node *head = takeinput_better();
    cout<<"The Linked List is : ";
    print(head);
    int i;
    cout<<"Enter the index of the element for deletion : ";
    cin>>i;
    head = deleteNode(head,i);
    print(head);
    return 0;
}
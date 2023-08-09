#include<iostream>
#include "node.cpp"
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

    void removeDublicates(Node *head){
        Node *t1 = head;
        Node *t2 = head->next;
        while(t2 != nullptr){
            if(t1->data == t2->data){
                Node *dub = t2;
                t2 = t2->next;
                t1->next = t2;
                delete dub;
            }
            else{
                t1 = t2;
                t2 = t2->next;
            }
        }
        return;
    }
int main(){

    Node *head = takeinput_better();
    removeDublicates(head);
    print(head);

    return 0;
}
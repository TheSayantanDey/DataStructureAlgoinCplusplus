#include<iostream>
using namespace std;
#include "node.cpp"

    void print(Node *head){
        // while(head!=nullptr){
        //     cout<<head->data<<" ";
        //     head = head->next;
        // }
        //If we use the method , the head will be lost , so we will

        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

int main(){

    //Statically
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);

    //Dynamically
    Node *node1 = new Node(10);
    Node *head1 = node1;
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    print(head1);


    return 0;
}
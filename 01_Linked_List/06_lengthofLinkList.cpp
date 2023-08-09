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

    int lenghtLL(Node *head){
        Node *temp = head;
        int length = 0;

        while(temp != nullptr){
            length++;
            temp = temp->next;
        }
        return length;
    }

int main(){

    int t;
    cin>>t;
    while(t--){
        Node *head = takeinput_better();
        cout<<lenghtLL(head)<<endl;
    }

    return 0;
}
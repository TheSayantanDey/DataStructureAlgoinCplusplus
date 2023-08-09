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

    int findIndex(Node* head , int val){
        Node *temp = head;
        int index = 0;
        for(;temp != nullptr;){
            if(temp->data == val){
                return index;
            }
            index++;
            temp = temp->next;
        }
        return -1;
    }

int main(){

    int t;
    cin>>t;
    while(t--){
        Node *head = takeinput_better();
        int val;
        cin>>val;
        cout<<findIndex(head,val)<<endl;
    }
    return 0;
}
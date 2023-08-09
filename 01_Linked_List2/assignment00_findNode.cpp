#include "node.cpp"
#include<iostream>
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

int findNode(Node *head , int val){
    if(head == nullptr){
        return -1;
    }
    if(head->data == val){
        return 0;
    }
    int smallOutput = findNode(head->next,val);
    if(smallOutput == -1){
        return -1;
    }
    return smallOutput+1;

}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        Node *head = takeinput_better();
        int val;
        cin>>val;
        cout<<findNode(head,val)<<endl;
    }

    return 0;
}
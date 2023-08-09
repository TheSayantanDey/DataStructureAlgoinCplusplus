#include "node.cpp"
#include<iostream>
using namespace std;

Node * swapNodes(Node *head,int m,int n){
    Node *prev1 = head;
    Node *prev2 = head;
    Node *current1 = head;
    Node *current2 = head;

    for(int i=0;i<m-1;i++){
        prev1 = prev1->next;
    }
    current1 = prev1->next;
    for(int i=0;i<n-1;i++){
        prev2 = prev2->next;
    }
    current2 = prev2->next;

    if(current1 == prev1 && current1 == prev2){
        // prev1->next = current2;
        // prev2->next = current1;
        current1->next = current2->next;
        // current2->next = prev2; 
        current2->next = current1;
        head = current2;
    }
    else if(current1 == prev1){
        Node *temp = current1->next;
        // prev1->next = current2;
        prev1->next = current2->next;
        // current1->next = current2->next;
        prev2->next = current1;
        // current2->next = prev2;
        current2->next = temp;
        head = current2;
    }
    else if(prev2 == current1){
        prev1->next = current2;
        // prev2->next = current1;
        current1->next = current2->next;
        current2->next = prev2;
    }
    else{
        prev1->next = current2;
        prev2->next = current1;
        current1->next = current2->next;
        current2->next = prev2;
    }
    
    
    return head;
}

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
    if(temp == nullptr){
        return;
    }
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int main(){

    Node *head = takeinput_better();
    int m,n;
    cin>>m>>n;
    head = swapNodes(head,m,n);
    print(head);

    return 0;
}
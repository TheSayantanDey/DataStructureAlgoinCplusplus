#include "node.cpp"
#include<iostream>
using namespace std;

Node* deleteEveryN(Node *head,int m,int n){
    Node *count1 = head;
    Node *count2 = head;
    while(count1 != nullptr){
        for(int i=0;i<m-1;i++){
            if(count1 == nullptr){
                break;
            }
            count1 = count1->next;
            count2 = count1->next;
        }
        for(int i=0;i<n;i++){
            if(count2 == nullptr){
                break;
            }
            Node *temp = count2;
            count2 = count2->next;
            delete temp;
        }
        count1->next = count2;
        count1 = count2;
    }
    // count1->next = nullptr;
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
    head = deleteEveryN(head,m,n);
    print(head);

    return 0;
}
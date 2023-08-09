#include "node.cpp"
#include<iostream>
using namespace std;

class Pair{
    public:

    Node *head;
    Node *tail;
};

Pair reverseLL_2(Node* head){
    if(head == nullptr || head->next == nullptr){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverseLL_2(head->next);
    smallAns.tail->next = head;
    head->next = nullptr;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}
Node* reverseLL_better(Node *head){
    return reverseLL_2(head).head;
}

Node * reverseLL(Node *head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node *smallAns = reverseLL(head->next);
    Node *temp = smallAns;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head;
    head->next = nullptr;
    return smallAns;
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
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node *head = takeinput_better();
    head = reverseLL_better(head);
    print(head);

    return 0;
}
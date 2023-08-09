//USING SLOW-FAST POINTER
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

    int midElement(Node* head){
        Node *slow = head;
        Node *fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

int main(){

    Node *head = takeinput_better();
    cout<<midElement(head)<<endl;

    return 0;
}
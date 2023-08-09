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

    Node * appendLastN(Node *head , int n){
        //Separating LL with last N elem
        Node *current = head;
        int len = lenghtLL(head);
        for(int i=0;i<len-n-1;i++){
            current = current->next;
        }
        Node *head2 = current->next;
        current->next = nullptr;

        //Appending
        Node *temp = head2;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = head;
        return head2;

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

    int t;
    cin>>t;
    while(t--){
        Node *head = takeinput_better();
        int n;
        cin>>n;
        head = appendLastN(head,n);
        print(head);
    }

    return 0;
}
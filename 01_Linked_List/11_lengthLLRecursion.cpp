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

    int lengthLLRecursive(Node*head){
        Node *temp =head;
        if(temp == nullptr){
            return 0;
        }
        int smallOutput = lengthLLRecursive(temp->next);

        return smallOutput+1;
    }

int main(){

    Node *head = takeinput_better();
    cout<<lengthLLRecursive(head)<<endl;

    return 0;
}
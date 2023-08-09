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

    void ithdata(Node*head ,int i){
        Node *temp = head;
        for(int j=1;j<=i;j++){
            temp = temp->next;
            if(temp == nullptr){
                return;
            }
        }
        cout<<temp->data<<endl;
        return;
    }

int main(){

    int tc;
    cin>>tc;
    while(tc--){
        Node *head = takeinput_better();
        int i;
        cin>>i;
        ithdata(head,i);
    }

    return 0;
}
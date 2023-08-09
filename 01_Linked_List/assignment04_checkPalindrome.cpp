#include<iostream>
#include "node.cpp"
using namespace std;

int lengthLLRecursive(Node*head){
        Node *temp =head;
        if(temp == nullptr){
            return 0;
        }
        int smallOutput = lengthLLRecursive(temp->next);

        return smallOutput+1;
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

    bool checkPalindrome(Node *head){
        //Breaking the LL in two parts
        Node *temp = head;
        if(temp == nullptr){
            return true;
        }
        int len = lengthLLRecursive(head);
        for(int i=0;i<len/2 -1;i++){
            temp = temp->next;
        }
        Node *head2 = temp->next;
        temp->next = nullptr;
        // print(head);
        // print(head2);
        //Reversing the 2nd half of the LL
        Node* temp2 = head2;
        Node *head3 = nullptr;
        while(temp2 != nullptr){
            Node *n = new Node(temp2->data);
            if(head3 == nullptr){
                head3 = n;
            }
            else{
                n->next = head3;
                head3 = n;
            }
            temp2 = temp2->next;
        }
        // print(head3);
        //Comparing 1st half with reversed 2nd half
        temp = head;
        temp2 = head3;
        while(temp != nullptr && temp2 != nullptr){
            if(temp->data != temp2->data){
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
        

    }

int main(){
    int t;
    cin>>t;
    while(t--){
        Node *head = takeinput_better();
        if(checkPalindrome(head)){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}
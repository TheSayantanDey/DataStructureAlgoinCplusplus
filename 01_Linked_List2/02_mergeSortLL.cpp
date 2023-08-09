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
    Node * midNode(Node* head){
        Node *slow = head;
        Node *fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* mergeTwoLL(Node *head1 , Node *head2){
        Node *temp1 = head1;
        Node *temp2 = head2;
        Node *finalHead = nullptr;
        Node *finalTail = nullptr;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->data < temp2->data){
                if(finalHead == nullptr){
                    Node *n = new Node(temp1->data);
                    finalHead = n;
                    finalTail = n;
                }else{
                    Node *n = new Node(temp1->data);
                    finalTail->next = n;
                    finalTail = finalTail->next;
                }
                temp1 = temp1->next;
            }else{
                if(finalHead == nullptr){
                    Node *n = new Node(temp2->data);
                    finalHead = n;
                    finalTail = n;
                }else{
                    Node *n = new Node(temp2->data);
                    finalTail->next = n;
                    finalTail = finalTail->next;
                }
                temp2 = temp2->next;
            }
        }
        while(temp1 != nullptr){
                if(finalHead == nullptr){
                    Node *n = new Node(temp1->data);
                    finalHead = n;
                    finalTail = n;
                }else{
                    Node *n = new Node(temp1->data);
                    finalTail->next = n;
                    finalTail = finalTail->next;
                }
                temp1 = temp1->next;
        }
        while(temp2 != nullptr){
                if(finalHead == nullptr){
                    Node *n = new Node(temp2->data);
                    finalHead = n;
                    finalTail = n;
                }else{
                    Node *n = new Node(temp2->data);
                    finalTail->next = n;
                    finalTail = finalTail->next;
                }
                temp2 = temp2->next;
        }
        return finalHead;
    }
    void print(Node *head){
        if(head == nullptr){
            return;
        }
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    Node * mergeSort(Node *head){
        if(head == nullptr){
            return head;
        }
        Node *temp = head;
        if(temp->next == nullptr){
            return temp;
        }
        Node *head2 = midNode(head)->next;
        midNode(head)->next = nullptr;
        head = mergeSort(head);
        head2 = mergeSort(head2);
        Node* finalHead = mergeTwoLL(head,head2);
        return finalHead;
    }
    
int main(){

    Node *head = takeinput_better();
    head = mergeSort(head);
    print(head);

    return 0;
}
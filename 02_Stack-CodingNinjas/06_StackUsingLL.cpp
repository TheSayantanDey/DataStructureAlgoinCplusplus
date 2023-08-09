#include <climits>
template <typename T>
class Node{
    public: 
    
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{

    Node<T> *head;
    int size;

    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        
        newNode->next = head;
        head = newNode;
        size++;
    }
    T pop(){
        if(head==NULL){
            // cout<<"Stack is empty"<<endl;
            return 0;
        }
        Node<T> *temp = head->next;
        T ans = head->data;
        delete head;
        head = temp;
        size--;
        return ans;
    }
    T top(){
        if(head==NULL){
            // cout<<"Stack is empty"<<endl;
            return 0;
        }
        return head->data;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return head==NULL;
    }

};
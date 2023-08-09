template <typename T>
class Node{
    public:
    T data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(T element){
        Node<T> *n = new Node<T>(element); 
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = tail->next;
        }
        size++;
    }

    T dequeue(){
        if(head == NULL){
            cout<<"QUEUE EMPTY !"<<endl;
            return 0;
        }
        Node<T> *temp = head->next;
        T ans = head->data;
        delete head;
        head = temp;
        size--;
        return ans;
    }

    T front(){
        if(head == NULL){
            cout<<"QUEUE EMPTY !"<<endl;
            return 0;
        }
        return head->data;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }
};
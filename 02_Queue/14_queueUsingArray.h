template <typename T>
class Queue{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

    public:
    //Constructor
    Queue(int totalsize){
        data = new T[totalsize];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = totalsize;
    }

    //Functions
    void enqueue(T element){
        if(size == capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size ++;
    }
    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;        
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size == 0){
            nextIndex = 0;
            firstIndex = -1;
        }
        return ans;
    }
    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
};
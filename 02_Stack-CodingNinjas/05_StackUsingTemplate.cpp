#include <climits>

template <typename Type>
class Stack{
    Type *data;
    int nextIndex;
    int capacity;

    public:

    Stack(){
        data = new Type[4];
        nextIndex = 0;
        capacity = 4;
    }

    //Returns the size of my stack
    int size(){
        return nextIndex;
    }

    //Returns true if the stack is empty
    bool isEmpty(){
        // if(nextIndex == 0){
        //     return true;
        // }
        // return false;

        return nextIndex == 0; //Return true if nextIndex is 0
    }

    //Insert element
    void push(Type element){
        if(nextIndex == capacity){
            // cout<<"Stack is full"<<endl;
            // return;
            Type *temp = new Type[capacity*2];
            for(int i=0;i<capacity;i++){
                temp[i] = data[i];
            }
            delete [] data;
            data = temp;
            capacity = capacity*2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    //Delete element
    Type pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //Access topmost element
    Type top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};
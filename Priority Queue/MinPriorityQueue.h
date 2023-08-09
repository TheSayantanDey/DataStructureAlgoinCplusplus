#include<vector>

class MinPriorityQueue{

    vector<int> pq;

    public:

    //Constructor
    MinPriorityQueue(){

    }

    //Is empty
    bool isEmpty(){
        return pq.size() == 0 ;
    }

    //Get size
    int getSize(){
        return pq.size();
    }

    //Get the minimum 
    int getMin(){
        if(pq.size() == 0){
            return 0; //Priority is Empty
        }
        return pq[0];
    }

    //Insert an element
    void insert(int element){
        pq.push_back(element);
        //Up-Heapify
        int childIndex = pq.size() - 1;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        if(isEmpty()){
            return 0;       //Priority Queue is Empty
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        //Down-Heapify
        int parentIndex = 0;
        int leftChildIndex = parentIndex*2 + 1;
        int rightChildIndex = parentIndex*2 + 2;
        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex]){
                minIndex = rightChildIndex;
            }
            if(parentIndex == minIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = parentIndex*2 + 1;
            rightChildIndex = parentIndex*2 + 2;
        }
        return ans;
    }
    
};
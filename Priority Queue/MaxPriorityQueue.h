#include<vector>

class MaxPriorityQueue{

    vector<int> pq;

    public:

    //Constructor
    MaxPriorityQueue(){

    }

    //Is empty
    bool isEmpty(){
        return pq.size() == 0 ;
    }

    //Get size
    int getSize(){
        return pq.size();
    }

    //Get the max element
    int getMax(){
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
            if(pq[childIndex] > pq[parentIndex]){
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

    int removeMax(){
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
            int maxIndex = parentIndex;
            if(pq[maxIndex] < pq[leftChildIndex]){
                maxIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex]){
                maxIndex = rightChildIndex;
            }
            if(parentIndex == maxIndex){
                break;
            }
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = parentIndex*2 + 1;
            rightChildIndex = parentIndex*2 + 2;
        }
        return ans;
    }
    
};
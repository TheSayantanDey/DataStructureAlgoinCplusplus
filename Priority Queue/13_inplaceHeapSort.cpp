#include<iostream>
using namespace std;

void heapSort(int arr[], int n){
    //Make the min heap
    for(int i=1;i<n;i++){
        int childIndex = i;
        while(childIndex>0){
            int parentIndex = (childIndex-1)/2;
            if(arr[parentIndex] > arr[childIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    //Sort the array 
    for(int i=n-1;i>0;i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        int parentIndex = 0;
        int leftChildIndex = parentIndex*2 +1;
        int rightChildIndex = parentIndex*2 +2;
        while(leftChildIndex < i){
            int minIndex = parentIndex;
            if(arr[leftChildIndex] < arr[minIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < i && arr[rightChildIndex] < arr[minIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] =  arr[parentIndex]; 
            arr[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = parentIndex*2 + 1;
            rightChildIndex = parentIndex*2 + 2;
        }
    }
}

int main(){

    int arr[100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
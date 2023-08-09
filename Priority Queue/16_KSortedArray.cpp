#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int arr[],int n,int k){
    priority_queue<int> elements;
    for(int i=0;i<k;i++){
        elements.push(arr[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        arr[j] = elements.top();
        elements.pop();
        elements.push(arr[i]);
        j++;
    }
    for(;j<n;j++){
        arr[j] = elements.top();
        elements.pop();
    }
}

int main(){

    int arr[100],n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    kSortedArray(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
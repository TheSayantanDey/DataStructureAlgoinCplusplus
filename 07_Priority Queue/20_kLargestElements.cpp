#include<iostream>
#include<queue>
using namespace std;

int * kLargestElement(int arr[],int n,int k){
    int * output = new int[k];
    priority_queue<int , vector<int> , greater<int>> p;
    for(int i=0;i<k;i++){
        p.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i] > p.top()){
            p.pop();
            p.push(arr[i]);
        }
    }
    for(int i=0;i<k;i++){
        output[i] = p.top();
        p.pop();
    }
    return output;
}

int main(){

    int arr[100],n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    int * output = kLargestElement(arr,n,k);
    for(int i=0;i<k;i++){
        cout<<output[i]<<endl;
    }
    delete [] output;

    return 0;
}
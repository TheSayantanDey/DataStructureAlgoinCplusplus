#include<iostream>
#include<unordered_map>
using namespace std;

int maxFrequencyElem(int arr[],int n){
    int maxElement , maxFrequency=0;
    unordered_map<int,int> freqeuncy;
    for(int i=0;i<n;i++){
        if(freqeuncy.count(arr[i]) > 0){
            freqeuncy[arr[i]]++;
        }else{
            freqeuncy[arr[i]] = 1;
        }
        
        if(freqeuncy[arr[i]] > maxFrequency){
            maxFrequency = freqeuncy[arr[i]];
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main(){

    int arr[100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxFrequencyElem(arr,n)<<endl;

    return 0;
}
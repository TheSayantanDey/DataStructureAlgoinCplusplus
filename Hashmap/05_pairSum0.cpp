#include<iostream>
#include<unordered_map>
using namespace std;

int totalPairSum0(int arr[],int n){
    //Brute force
    // int count = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(i==j){
    //             continue;
    //         }
    //         if(arr[i]+arr[j] == 0){
    //             count++;
    //         }
    //     }
    // }
    // return count/2;

    //Using Hashmap
    int count=0;
    unordered_map<int,int> ourmap;
    for(int i=0;i<n;i++){
        if(ourmap.count(i) > 0){
            ourmap[i]++;
        }else{
            ourmap[i] = 1;
        }
    }
    for(int i=0;i<n;i++){
        count = count + ourmap[0-arr[i]];
        
    }
    return count/2;
}

int main(){

    //2 1 -2 2 3
    int arr[100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<totalPairSum0(arr,n);

    return 0;
}
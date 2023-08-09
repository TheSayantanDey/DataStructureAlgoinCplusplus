#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDublicates(int arr[],int n){
    vector<int> output ;
    unordered_map<int,bool> seen;
    for(int i=0;i<n;i++){
        if(seen.count(arr[i]) > 0){
            continue;
        }
        //else
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main(){

    int n,arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> output = removeDublicates(arr,n);

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }


    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> intersection(int arr1[],int m,int arr2[],int n){
    vector<int> output;
    unordered_map<int,int> intersectionMap;
    for(int i=0;i<m;i++){
        if(intersectionMap.count(arr1[i]) > 0){
            intersectionMap[arr1[i]]++;
        }else{
            intersectionMap[arr1[i]] = 1; 
        }
    }
    for(int i=0;i<n;i++){
        if(intersectionMap.count(arr2[i]) > 0){
            output.push_back(arr2[i]);
            if(intersectionMap[arr2[i]] == 1){
                intersectionMap.erase(arr2[i]);
            }else{
                intersectionMap[arr2[i]]--;
            }
        }
    }
    return output;
}

int main(){

    int n;
    cin>>n;
    while(n--){
        int arr1[100],arr2[100], m , n;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>arr1[i];
        }
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        vector<int> output = intersection(arr1,m,arr2,n);
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
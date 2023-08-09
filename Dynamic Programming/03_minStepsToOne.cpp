#include<iostream>
using namespace std;

//Brute Force Recursive
int minStepsToOne1(int n){
    if(n==1){
        return 0;
    }
    int x=INT32_MAX,y=INT32_MAX,z=INT32_MAX;
    if(n%3==0){
        x = minStepsToOne1(n/3);
    }
    if(n%2==0){
        y = minStepsToOne1(n/2);
    }
    z = minStepsToOne1(n-1);

    int minStepNo = min(x,min(y,z));

    return 1+minStepNo;
}

//Memorization recursive
int minStepsToOne2_helper(int n,int *arr){
    if(n==1){
        return 0;
    }

    if(arr[n]!=-1){
        return arr[n];
    }

    int x=INT32_MAX,y=INT32_MAX,z=INT32_MAX;
    if(n%3==0){
        x = minStepsToOne2_helper(n/3,arr);
    }
    if(n%2==0){
        y = minStepsToOne2_helper(n/2,arr);
    }
    z = minStepsToOne2_helper(n-1,arr);

    int minStepNo = min(x,min(y,z));

    arr[n] = 1+minStepNo;

    return arr[n];

}
int minStepsToOne2(int n){
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i] = -1;
    }
    return minStepsToOne2_helper(n,arr);
}

//Dynamic Programming
int minStepsToOne3(int n){
    int *arr = new int[n+1];
    arr[1] = 0;
    for(int i=2;i<=n;i++){
        int x=INT32_MAX,y=INT32_MAX,z=INT32_MAX;
        if(i%3==0){
            x = arr[i/3]+1;
        }
        if(i%2==0){
            y = arr[i/2]+1;
        }
        z = arr[i-1]+1;

        int minStepNo = min(x,min(y,z));

        arr[i] = minStepNo;

    }
    return arr[n];
}

int main(){

    int num;
    cin>>num;
    cout<<minStepsToOne1(num)<<endl;
    cout<<minStepsToOne2(num)<<endl;
    cout<<minStepsToOne3(num)<<endl;

    return 0;
}
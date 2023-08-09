#include<iostream>
using namespace std;

//Brute Force recursive
int totalPossibleWays1(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    int x,y,z;
    x = totalPossibleWays1(n-1);
    y = totalPossibleWays1(n-2);
    z = totalPossibleWays1(n-3);
    return x+y+z;
}

//Memorization
int totalPossibleWays2_helper(int n,int *arr){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    if(arr[n]!=-1){
        return arr[n];
    }

    int x,y,z;
    x = totalPossibleWays2_helper(n-1,arr);
    y = totalPossibleWays2_helper(n-2,arr);
    z = totalPossibleWays2_helper(n-3,arr);
    arr[n] = x+y+z;
    return arr[n];
}
int totalPossibleWays2(int n){
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    return totalPossibleWays2_helper(n,arr);
}

//Dynamic Programming
int totalPossibleWays3(int n){
    int *arr = new int[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
}

int main(){

    int num;
    cin>>num;
    cout<<totalPossibleWays1(num)<<endl;
    cout<<totalPossibleWays2(num)<<endl;
    cout<<totalPossibleWays3(num)<<endl;

    return 0;
}
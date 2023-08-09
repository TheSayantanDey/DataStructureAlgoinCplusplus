#include <iostream>
using namespace std;

int fibonacci2(int n){

    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int main()
{

    int num;
    cin >> num;
    cout << fibonacci2(num) << endl;

    return 0;
}
#include <iostream>
using namespace std;

int fibonacci_helper(int n,int *arr)
{
    //Base case
    if (n <= 1){
        arr[0] = arr[1] = 1;
        return n;
    }
    
    //Check if answer already present
    if (arr[n] != -1){
        return arr[n];
    }
    
    //As it's not present , do the calculation
    int a = fibonacci_helper(n-1,arr);
    int b = fibonacci_helper(n-2,arr);

    arr[n] = a+b; // Save the calculated answer in its's correct place

    return arr[n];


}
int fibonacci(int n){
    int *arr = new int[n+1];
    for (int i = 0; i <= n; i++){
        arr[i] = -1;
    }
    return fibonacci_helper(n,arr);
}
int main()
{

    int num;
    cin >> num;
    cout << fibonacci(num) << endl;

    return 0;
}
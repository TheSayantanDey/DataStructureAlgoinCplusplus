#include<iostream>
using namespace std;
#include "01_StackUsingArray.cpp"

int main(){

    StackUsingArray s1(4);

    cout<< s1.pop() <<endl; //Stack is empty , Prints INT_MIN

    s1.push(10); //Pushes 10
    s1.push(20); //Pushes 20
    s1.push(30); //Pushes 30
    s1.push(40); //Pushes 40
    s1.push(50); //Stack is full 

    cout<< s1.size() <<endl; //Prints 4

    cout<< s1.top() <<endl; //Prints 40

    cout<< s1.pop() <<endl; //Prints 40 , deletes 40

    cout<< s1.size() <<endl; //Prints 3
    cout<< s1.pop() <<endl; //Prints 30 , deletes 30
    cout<< s1.pop() <<endl; //Prints 20 , deletes 20
    
    cout<< s1.isEmpty() <<endl; //Prints 0 as false

    cout<< s1.pop() <<endl; //Prints 10 , deletes 10

    cout<< s1.isEmpty() <<endl; //Prints 1 as true



    return 0;
}
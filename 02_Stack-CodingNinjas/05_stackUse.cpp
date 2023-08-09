#include<iostream>
using namespace std;
#include "05_StackUsingTemplate.cpp"

int main(){

    Stack<char> s;
    s.push('a');
    cout<<s.pop()<<endl;

    return 0;
}
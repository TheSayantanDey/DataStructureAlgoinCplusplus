#include<iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s1;
    s1.push(10);
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.empty()<<endl;
    s1.pop();
    // s1.pop();
    cout<<s1.empty()<<endl;


    return 0;
}
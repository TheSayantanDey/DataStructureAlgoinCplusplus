#include<iostream>
#include <stack>
using namespace std;

stack<int> reverseStack(stack<int> s1, stack<int> s2){
    if(s1.size()==0 || s1.size()==1){
        return s1;
    }
    int x = s1.top();
    s1.pop();
    s1 = reverseStack(s1,s2);
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return s1;
}

int main(){

    stack<int>s1,s2;
    int n;
    cin>>n;
    while(n--){
        int data;
        cin>>data;
        s1.push(data);
    }
    s1 = reverseStack(s1,s2);
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    

    return 0;
}
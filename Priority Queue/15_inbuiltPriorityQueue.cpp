#include<iostream>
using namespace std;
#include<queue>

int main(){

    priority_queue<int> p;
    p.push(10);
    p.push(1);
    p.push(20);
    p.push(110);
    p.push(0);
    p.push(11);

    cout<<"isEmpty : "<<p.empty()<<endl;
    cout<<"Size : "<<p.size()<<endl;
    cout<<"Top : "<<p.top()<<endl;
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }

    return 0;
}
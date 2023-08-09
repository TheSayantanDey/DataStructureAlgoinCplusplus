#include<iostream>
#include <queue>
using namespace std;

int main(){

    queue<char> q;
    q.push('s'); //Same as enqueue()
    q.push('a');
    q.push('y');
    q.push('a');
    q.push('n');

    cout<<q.front()<<endl;

    q.pop(); //Same as dequeue()

    cout<<q.empty()<<endl; //Same as isEmpty()

    cout<<q.size()<<endl;

    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }


    return 0;
}
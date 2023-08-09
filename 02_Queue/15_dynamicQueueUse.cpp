#include<iostream>
using namespace std;
#include "15_dynamicQueue.h"

int main(){

    Queue<int> q;
    
    q.enqueue(1);
    q.enqueue(2);

    q.enqueue(10);
    q.enqueue(20);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    q.enqueue(30);
    q.enqueue(40);

    q.enqueue(50);
    q.enqueue(60);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}
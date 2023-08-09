#include<iostream>
using namespace std;
#include "MaxPriorityQueue.h"

int main(){

    MaxPriorityQueue p;

    p.insert(10);
    p.insert(1);
    p.insert(6);
    p.insert(100);
    p.insert(11);
    p.insert(70);
    p.insert(25);
    p.insert(69);

    cout<<"Size is "<<p.getSize()<<endl;
    cout<<p.getMax()<<endl;
    while(!p.isEmpty()){
        cout<<p.removeMax()<<" ";
    }
    cout<<endl;

    cout<<"Size is "<<p.getSize()<<endl;

    return 0;
}
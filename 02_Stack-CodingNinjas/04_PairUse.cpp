#include<iostream>
using namespace std;
#include "04_Pair.cpp"

int main(){
/*
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);
    cout<<p1.getX()<<endl;
    cout<<p1.getY()<<endl;

    Pair<double> p2;
    p2.setX(100.58);
    p2.setY(20.23);
    cout<<p2.getX()<<endl;
    cout<<p2.getY()<<endl;
*/
/*
    Pair<int,double> p1;
    p1.setX(10);
    p1.setY(20.45);
    cout<<p1.getX()<<endl;
    cout<<p1.getY()<<endl;
*/

    Pair<Pair<int,int>,int> p2;
    p2.setY(10);
    Pair<int,int> p3;
    p3.setX(15);
    p3.setY(20);
    p2.setX(p3);

    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;

    return 0;
}
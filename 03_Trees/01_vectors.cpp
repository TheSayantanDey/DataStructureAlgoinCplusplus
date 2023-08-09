#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v;
    for(int i=0;i<50;i++){
        cout<<"cap:"<<v.capacity()<<endl;
        cout<<"size:"<<v.size()<<endl;
        v.push_back(i+1);
    }
/*
    v.push_back(10); // Insertion at the back
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    v[0] = 100; // Updation

    // Error -- Dont use [] for insertion
    //  v[5] = 50; //Attempt for insertion
    //  v[6] = 60;

    v.push_back(70);
    v.push_back(80);

    v.pop_back(); //Deletes last element

    
        cout<<v[0]<<endl; //Accessing data
        cout<<v[1]<<endl;
        cout<<v[2]<<endl;
        cout<<v[3]<<endl;
        cout<<v[4]<<endl;
        cout<<v[5]<<endl;
        // cout<<v[6]<<endl; //Prints garbage
        // cout<<v[7]<<endl; //Prints garbage

        cout<<"Size : "<<v.size()<<endl;

        cout<< v.at(0) <<endl; //Accessing data
        cout<< v.at(8) <<endl; //Accessing data //Error cause out of index //safer to use

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
*/


    return 0;
}
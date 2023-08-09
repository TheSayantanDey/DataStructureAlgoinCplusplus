#include<iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){

    unordered_map<string,int> ourMap;


    //Insert
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    ourMap["def"] = 2; //We can insert like this too


    //Access or find
    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("abc")<<endl;

    // cout<<ourMap.at("ghi")<<endl; //Throws error
    // cout<<ourMap["ghi"]<<endl; //Doesn't throws error, instead inserts a new key with the default value 0


    //Check if present or not
    if(ourMap.count("ghi")>0){
        cout<<"ghi key is present"<<endl;
    }else{
        cout<<"ghi isn't present"<<endl;
    }


    //Returns size
    cout<<"Size : "<<ourMap.size()<<endl;


    //Erase element
    ourMap.erase("abc");

    cout<<"Size : "<<ourMap.size()<<endl;

    return 0;
}
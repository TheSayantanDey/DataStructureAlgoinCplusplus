#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main(){

    //Iterator incase of Map

    unordered_map<string,int> ourMap;
    ourMap["abc"] = 0;
    ourMap["abc1"] = 1;
    ourMap["abc2"] = 2;
    ourMap["abc3"] = 3;
    ourMap["abc4"] = 4;
    ourMap["abc5"] = 5;

    unordered_map<string,int>::iterator it = ourMap.begin();
    while(it != ourMap.end()){
        cout<<"Key : "<<it->first<<", Value : "<<it->second<<endl;
        it++;
    }

    //Iterator in case of vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int>::iterator it1 = v.begin();
    while(it1 != v.end()){
        cout<<*it1<<endl;
        it1++;
    }
    return 0;
}
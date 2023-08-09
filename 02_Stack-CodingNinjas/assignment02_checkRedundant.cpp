#include<iostream>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string input){
    stack<char> s;
    for(int i = 0;input[i]!='\0';i++){
        int count = 0;
        if(input[i] == ')'){
            while(s.top()!='('){
                s.pop();
                count++;
            }
            if(count <= 1){
                return true;
            }
        }else{
            s.push(input[i]);
        } 
    }
    return false;
}

int main(){

    string input;
    cin>>input;
    if(checkRedundantBrackets(input)){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }

    return 0;
}
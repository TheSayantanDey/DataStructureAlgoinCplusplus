#include<iostream>
#include "stackUsingLL.h"
using namespace std;

bool checkBalencedParenthesis(Stack<char> s,string input){
    for(int i=0;input[i]!='\0';i++){
        if(input[i]=='(' || input[i] == '{' || input[i] == '['){
            s.push(input[i]);
        }
        else if(input[i]==')'){
            if(s.top()=='('){
                s.pop();
            }else{
                return false;
            }
        }else if(input[i] == '}'){
            if(s.top()=='('){
                s.pop();
            }else{
                return false;
            }
        }
        else if(input[i] == ']'){
            if(s.top()=='('){
                s.pop();
            }else{
                return false;
            }
        }
    }
    if(s.isEmpty()){
        return true;
    }
    return false;
}

int main(){

    Stack<char> s;
    string input;
    cin>>input;
    if(checkBalencedParenthesis(s,input)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    return 0;
}
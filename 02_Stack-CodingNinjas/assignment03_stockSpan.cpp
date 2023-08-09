#include<iostream>
#include <stack>
using namespace std;

//Optimised
void stockSpan(int input[],int output[],int n){
    stack<int> s;
    s.push(input[0]);
    output[0] = 1;
    for(int i=1;i<n;i++){
        if(input[i]>input[s.top()]){
            while(input[i]>input[s.top()]){
                s.pop();
                if(s.empty()){
                    s.push(i);
                    output[i] = i+1;
                    break;
                }
            }
            if(!s.empty()){
                output[i] = i - s.top();
            }
            
        }else{
            output[i] = 1;
            s.push(i);
        }
    }
}
//Brute force technique -- O(n^2)
// void stockSpan(int input[],int output[],int n){
//     for(int i=0;i<n;i++){
//         stack<int> s;
//         s.push(input[i]);
//         for(int j=i;j>0;j--){
//             if(input[i]>input[j-1]){
//                 s.push(input[j-1]);
//             }else{
//                 break;
//             }
//         }
//         output[i] = s.size();
//     }
// }

int main(){

    int n;
    cin>>n;
    int *input = new int[n];
    int *output = new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    stockSpan(input,output,n);
    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }

    return 0;
}
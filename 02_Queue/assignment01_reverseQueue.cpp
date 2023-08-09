#include<iostream>
#include <queue>
using namespace std;

queue<int> reverseQueue(queue<int> q){
    if(q.size()==0 || q.size()==1){
        return q;
    }
    int x = q.front();
    q.pop();

    q = reverseQueue(q);

    q.push(x);
    return q;
}

int main(){

    queue<int> q;
    int n;
    cin>>n;
    while(n--){
        int  data;
        cin>>data;
        q.push(data);
    }
    q = reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
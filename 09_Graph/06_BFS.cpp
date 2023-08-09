#include<iostream>
#include<queue>
using namespace std;

void printBFS(int **edges, int n, int sv,bool * visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(pendingVertices.size() != 0){
        int front = pendingVertices.front();
        cout<<front<<" ";
        pendingVertices.pop();
        for(int i=0;i<n;i++){
            if(edges[front][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
            
        }
    }
}

int main(){

    int n,e;
    cin>>n>>e;
    int **edges = new int*[e];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    printBFS(edges,n,0,visited);

    //Delete the memory
    delete [] visited;
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}
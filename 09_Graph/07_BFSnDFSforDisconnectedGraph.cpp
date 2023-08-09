#include<iostream>
#include<queue>
using namespace std;

void printDFS(int **edges, int n, int sv,bool * visited){
    cout<<sv<<" ";
    visited[sv] = true; //Marking the visited vertices as visited
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i] == true){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}
void DFS(int **edges, int n){
    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}


void printBFS(int **edges, int n,int sv,bool *visited){
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
void BFS(int ** edges,int n){
    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}

int main(){
    //10 10 0 4 4 5 1 2 2 7 2 8 7 8 8 1 3 9 9 6 6 3
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

    cout<<"DFS :";
    DFS(edges,n);
    
    cout<<"BFS :";
    BFS(edges,n);

    //Delete the memory
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}
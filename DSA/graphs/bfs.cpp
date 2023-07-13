#include <iostream>
#include <queue>
using namespace std;

void bfs(int vertex, int a[][8], int n){
    queue<int> q;
    int visited[8]={0};
    cout<<vertex<<", ";
    q.push(vertex);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=1; v<=n; v++){
            if(a[u][v]==1 && visited[v]==0){
                cout<<v<<", ";
                visited[v]=1;
                q.push(v);
            }
        }
    }
    cout<<endl;
}

int main(){
    int a[8][8]={{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 1, 1, 1, 0, 0, 0},
                 {0, 1, 0, 1, 0, 0, 0, 0},{0, 1, 1, 0, 1, 1, 0, 0},
                 {0, 1, 0, 1, 0, 1, 0, 0},{0, 0, 0, 1, 1, 0, 1, 1},
                 {0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 0, 1, 0, 0}
                };
    cout<<"vertex: 1 -> ";
    bfs(1, a, 8);
}
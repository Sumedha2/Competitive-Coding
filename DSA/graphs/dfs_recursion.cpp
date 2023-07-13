#include <iostream>
using namespace std;

void dfs(int u, int a[][8], int n){
    static int visited[8]={0};
    if(visited[u]==0){
        cout<<u<<", ";
        visited[u]=1;
        for(int v=1; v<n; v++){
            if(a[u][v]==1 && visited[v]==0){
                dfs(v, a, n);
            }
        }
    }
}

int main(){
    int a[8][8]={{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 1, 1, 1, 0, 0, 0},
                 {0, 1, 0, 1, 0, 0, 0, 0},{0, 1, 1, 0, 1, 1, 0, 0},
                 {0, 1, 0, 1, 0, 1, 0, 0},{0, 0, 0, 1, 1, 0, 1, 1},
                 {0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 0, 1, 0, 0}
                };
    cout<<"vertex: 1 -> ";
    dfs(1, a, 8);
}
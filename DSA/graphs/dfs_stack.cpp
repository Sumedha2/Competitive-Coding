#include <iostream>
#include <stack>
using namespace std;

void dfs(int u, int a[][8], int n){
    int visited[8]={0};
    stack<int> stk;
    stk.push(u);
    while(!stk.empty()){
        u=stk.top();
        stk.pop();
        if(visited[u]!=1){
            cout<<u<<", ";
            visited[u]=1;
            for(int v=n-1; v>=0; v--){
                if(a[u][v]==1 && visited[v]==0){
                    stk.push(v);
                }
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
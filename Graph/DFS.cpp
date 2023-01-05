#include <bits/stdc++.h>
using namespace std;

const int N =1e5;
int visited[N];
vector<int>adj_list[N];

void DFS(int Node){
    cout<<Node<<endl;
    visited[Node]=1;
    for(int adj_node:adj_list[Node]){
        if(visited[adj_node]==0){
            DFS(adj_node);
        }
    }
}
int main()
{
    int v,e,source=0;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    DFS(source);
    return 0;
}
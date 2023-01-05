#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int> adj_list[N];
void BFS(int node){
    queue<int>q;
    visited[node]=1;
    q.push(node);
    while(!q.empty()){
        int head=q.front();
        q.pop();
        cout<<head<<" ";
        for(int adj_node:adj_list[head]){
            if(visited[adj_node]==0){
                visited[adj_node]=1;
                q.push(adj_node);
                
            }
            
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
    BFS(source);


    return 0;
}

/*
6 6
0 1
2 3
1 5
2 4
5 4
1 2
*/


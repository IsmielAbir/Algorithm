#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
int visited[N];
int level[N];
vector<int> adj_list[N];

void bfs(int node){
    queue<int>q;
    visited[node]=1;
    level[node]=0;
    q.push(node);
    while(!q.empty()){
        int head=q.front();
        q.pop();
        cout<<head<<endl;
        for(int adj_node:adj_list[head]){
            if(visited[adj_node]==0){
                visited[adj_node]=1;
                level[adj_node]=level[head]+1;
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
    bfs(source);
    
    for(int i=0;i<v;i++){
        cout<<"node "<<i<<" -> level: "<<level[i]<<endl;
    }

    return 0;
}



/*

0-------1------2------3
        |      |
        |      |
        5------4



6 6
0 1
2 3
1 5
1 2
2 4
5 4


*/







#include <iostream>
#include <vector>
#include <queue>
#include <climits> 

using namespace std;

struct Edge {
    int dest;
    int weight;

    Edge(int d, int w) : dest(d), weight(w) {}
};

void addEdge(vector<vector<Edge>>& graph, int src, int dest, int weight) {
    graph[src].emplace_back(dest, weight);
    graph[dest].emplace_back(src, weight);
}

// Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int startVertex) {
    int V = graph.size(); 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> visited(V, false); 
    vector<int> key(V, INT_MAX); 
    vector<int> parent(V, -1); 
    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            if (!visited[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    cout << "Edges in the MST:" << endl;
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << endl;
}

int main() {
    int V = 5; 
    vector<vector<Edge>> graph(V); 
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    int startVertex = 0; 

    primMST(graph, startVertex);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

void addEdge(vector<Edge>& graph, int src, int dest, int weight) {
    graph.emplace_back(src, dest, weight);
}

void kruskalMST(vector<Edge>& graph, int V) {
    sort(graph.begin(), graph.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<Edge> result; 

    DisjointSet ds(V); 

    for (const auto& edge : graph) {
        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);

        if (srcRoot != destRoot) {
            result.push_back(edge);
            ds.unionSets(srcRoot, destRoot);
        }
    }

    cout << "Edges in the MST:" << endl;
    for (const auto& edge : result)
        cout << edge.src << " - " << edge.dest << " (" << edge.weight << ")" << endl;
}

int main() {
    int V = 6; 
    vector<Edge> graph; 

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 6);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 1, 5, 4);

    kruskalMST(graph, V);

    return 0;
}

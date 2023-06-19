#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 3;
vector<vector<pair<int, int>>> g(N);
int cost = 0;

vector<pair<int, int>> dist(N), parent(N);
vector<bool> vis(N);
const int INF = 1e9;

void primsMST(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = {INF, i};
        parent[i] = {-1, -1};
    }
    set<pair<int, int>> s;
    dist[source].first = 0;
    s.insert({0, source});
    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        vis[x.second] = true;
        int u = x.second;
        int v = parent[x.second].second;
        int w = x.first;
        cout << u << " " << v << " " << w << "\n";
        for (auto it : g[x.second]) {
            if (vis[it.first])
                continue;
            if (dist[it.first].first > it.second) {
                s.erase({dist[it.first].first, it.first});
                dist[it.first].first = it.second;
                s.insert({dist[it.first].first, it.first});
                parent[it.first] = {x.second, it.second};
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsMST(0);
    for (int i = 0; i < n; i++) {
        cost += dist[i].first;
    }
    cout << cost;

    return 0;
}

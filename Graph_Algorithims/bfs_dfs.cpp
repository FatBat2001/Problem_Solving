#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
// adjacencey list
vector<int> adj[N];
// visted array to keep track of  visited nodes so we don't visit any node twice 
bool vis[N];

// for finding the shortest path using bfs 
int dist[N];
int n, m, u, v;

void dfs(int node) {
    if (!vis[node]) {
        vis[node] = true;
        cout << node << " ";
        for (auto child : adj[node]) {
            dfs(child);
        }
    }
}

void bfs(int node) {
    queue<int> q;
    vis[node] = true;
    dist[node] = 0;
    q.push(node);
    while (!q.empty()) {
        auto parent = q.front();
        q.pop();
        cout << parent << ' ';
        for (auto child : adj[parent]) {
            if (!vis[child]) {
                vis[child] = true;
                dist[child] = dist[parent] + 1;
                q.push(child);
            }
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        cin >> u >> v;
        // undirected graph
        adj[u].push_back(v), adj[v].push_back(u);
    }
    dfs(1);
    memset(vis, 0, sizeof vis);
    cout << '\n';
    bfs(1);
    system("pause");
}

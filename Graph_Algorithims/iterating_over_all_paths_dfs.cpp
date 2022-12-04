#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5;
vector<int> currentPath;
vector<int> adj[N];
bool vis[N];
void dfs(int node) {
    vis[node] = true;
    currentPath.push_back(node);
    if (adj[node].size() == 1) {
        for (auto it : currentPath) {
            cout << it << ' ';
        }
        cout << '\n';
    }
    for (auto child : adj[node]) {
        if (!vis[child]) dfs(child);
    }
    currentPath.pop_back();
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

}

/**

9 8
1 2
1 7
7 8
8 9
2 3
2 4
4 5
4 6



*/

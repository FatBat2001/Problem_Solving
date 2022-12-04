#include <bits/stdc++.h>

void fast_io();

using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
/// 0 1 2 3
/// D U L R
vector<int> adj[N];
bool vis[N];
bool currPath[N];

int n, m;

bool found_a_cycle = false;

void dfs(int node, int parent = 0) {
    vis[node] = true;
    currPath[node] = true;
    for (int i = 0; i < adj[node].size(); i ++ ){
        if (vis[adj[node][i]] && currPath[adj[node][i]]) {
            found_a_cycle = true;
        }
        if (!vis[adj[node][i]]) {
            dfs(adj[node][i], node);
        }
    }
    currPath[node] = false;

}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i ++ ){
        if (!vis[i]) {
            dfs(i);
        }
    }
    if (found_a_cycle) {
        cout << "There is a Cycle\n";
    } else {
        cout << "No Cycle\n";
    }
}

int main()
{
    fast_io();
    int tt = 1;
    //cin >> tt;
    while (tt -- ) {
        solve();
    }

}

void fast_io(){
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
}

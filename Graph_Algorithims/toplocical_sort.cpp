#include <iostream>
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
vector<int> order;
bool flag = true;



// the idea behined topological sort is to visit every branch until there is no more childs
// then add the childs backwards while backtracking 

void dfs(int node) {
    vis[node] = true;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
    order.push_back(node);
}
void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) {
        flag = false;
        return;
    }
    for (int i= 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]) 
            dfs(i);
    }
    reverse(order.begin(), order.end());
    for (auto x : order)
        cout << x << " ";
    order.clear();
}

int main()
{
    int tt = 1;
    // cin > tt;
    while (flag)
        solve();
    system("pause");
}
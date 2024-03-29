#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 5, M = 1003, MOD = 1e9 + 7;

// kusarajos 
vector<int> g[N], rg[N]; 
vector<int> vis(N), order(N), col(N); 
void dfs1(int u) { 
    vis[u] = true; 
    for (auto v : g[u]) { 
        if (!vis[v]) { 
            dfs1(v); 
        }
    }
    order.push_back(u); 
}
void dfs2(int u, int comp) {
    vis[u] = true; 
    col[u] = comp; 
    for (auto v : rg[u]) { 
        if (!vis[v]) 
            dfs2(v, comp); 
    }
}
int32_t main() {
    int n, m; 
    cin >> n >> m; 
    for (int i = 0; i < m; i ++) { 
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v); 
        rg[v].push_back(u); 
    }
    for (int i = 1; i <= n; i ++) { 
        if (!vis[i]) { 
            dfs1(i); 
        }
    }
    reverse(order.begin(), order.end()); 
    vis = vector<int>(n + 1);
    int comp = 0;  
    for (auto x : order)  { 
        if (!vis[x]) 
            dfs2(x, comp++); 
    }
    for (int i = 1; i <= n; i ++) cout << col[i] << ' '; 
    cout << '\n'; 
    cout << "Total strongly components = " << comp - 1 << endl; 
}   





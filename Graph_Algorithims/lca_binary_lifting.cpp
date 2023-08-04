// problem link : https://cses.fi/problemset/task/1688 
#include<bits/stdc++.h>

#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);

using namespace std;
using ll = long long;


void read_Write();

const int N = 1e6 + 5, M = 105, MOD = 1e9 + 7, oo = 1e8;
using namespace std;
const int LOG = 22;
int depth[N];
int up[N][LOG];
vector<int> adj[N];

void dfs(int node)  {
    for (auto child : adj[node]) {
        depth[child] = depth[node] + 1;
        up[child][0] = node;
        for (int j = 1; j < LOG; j += 1) {
            up[child][j] = up[ up[child][j - 1] ][j - 1];
        }
        dfs(child);
    }
}
int get_lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];

    for (int j = LOG - 1; j >= 0; j --) {
        if ((k >> j) & 1)
            a = up[a][j];
    }

    if (a == b) return a;

    for (int j = LOG - 1; j >= 0; j --) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int u = 2; u <= n; u ++) {
        int v;
        cin >> v;
        adj[v].push_back(u);
    }
    dfs(1);
    while (q --) {
        int a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << endl;
    }

}

int32_t main() {
    read_Write();
    int tt = 1;
//    cin >> tt;
    while (tt--) {
        solve();
    }

}


void read_Write() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    read("input.txt")
    write("output.txt")
#else

#  endif
}
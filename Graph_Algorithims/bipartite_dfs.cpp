#include<bits/stdc++.h>


#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define all(X) (X).begin(),(X).end()
using namespace std;
using ll = long long;
using ld = long double;
void read_Write();

const int N = 5e5 + 5 + 4, M = 1003, MOD = 1e9 + 7;
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
/// 0 1 2 3
/// D U L R

ll mul(ll a, ll b, ll m) {
    return ((a % m) * (b % m)) % m;
}

// globals 
int vis[N];
vector<int> adj[N];
bool is_bipartite  = true;
int n, m;
// algorithm function
void dfs(int node, int color) {
    if (!is_bipartite) return;
    vis[node] = color;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, color == 1 ? 2 : 1);
            
            
        }  else if (vis[child] == vis[node]) { // if the color of the child coincide to be as the parent 
                                              // then the graph isn't bipartite 
            is_bipartite = false;
            return;
        }
    }
}
void solve() {
    // input 
    cin >> n;
    m = n - 1;
    for (int i = 1; i <= m; i ++ ){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++ ) {
        if (!vis[i]) {
            dfs(i, 1);
        }
    }
    if (is_bipartite) {
        cout << "BICOLOURABLE.";
    }else {
        cout << "NOT BICOLOURABLE.";
    }
    cout << '\n';
}


int32_t main() {
    read_Write();
    int tt = 1;
//    cin >> tt;
    while (tt --)
        solve();
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
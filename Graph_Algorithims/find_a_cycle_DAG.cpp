#include<bits/stdc++.h>


#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define all(X) (X).begin(),(X).end()
using namespace std;
using ll = long long;
using ld = long double;
void read_Write();

const int N = 1e5 + 5 + 4, M = 1003, MOD = 1e9 + 7;
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
/// 0 1 2 3
/// D U L R

ll mul(ll a, ll b, ll m) {
    return ((a % m) * (b % m)) % m;
}
vector<int> adj[N];
bool vis[N];
bool current_path[N];

int n, m, u, v;
bool is_cyclic = false;
int cycle_key = false;
stack<int> order;
bool until = true;

void dfs(int node) {
    if (!until) return;
    vis[node] = true;
    current_path[node] = true;
    for (auto child : adj[node]) {
        if (vis[child] && current_path[child] && !cycle_key) {
            is_cyclic = true;
            cycle_key = child;

            // the first node in the cycle is the parent
            // then we backtrack throw all previous nodes in the path
            order.push(node);
            return;
        } else if(!vis[child] && !is_cyclic){
            dfs(child);
        }
    }
    if (is_cyclic && until) {
        order.push(node);
        if (cycle_key == node) {
            until = false;
            return;
        }
    }
    else {
        current_path[node] = false;
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i =1 ; i <= n; i ++ ) {
        if (!vis[i] && !is_cyclic) {
            dfs(i);
        }
    }
    if (is_cyclic) {
        cout << "YES" << endl;
        while (!order.empty()) {
            cout << order.top() << ' ', order.pop();
        }
    } else {
        cout << "NO" <<endl;
    }

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
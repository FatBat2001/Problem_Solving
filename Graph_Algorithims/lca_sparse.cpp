// problem link : https://www.spoj.com/status/ns=31627873
#include <iostream>
#include<vector>
#include <cmath>

using namespace std;
using ll = long long ;
const int MAXN = 2e5 + 5, LOG = 21;

struct RMQ{
    int n;
    vector<int> a;
    vector<vector<int>> sparse_table;
    RMQ(vector<int> &v) {
        a = v;
        n = a.size();
        sparse_table = vector<vector<int>>(n , vector<int>(LOG));
        for (int i = 0; i < n; i ++) {
            sparse_table[i][0] = i;
        }

        for (int j = 1; (1 << j) <= n; j ++) {
            for (int i = 0; i + (1 << j) - 1 < n; i ++) {
                if (a[sparse_table[i][j - 1]] < a[sparse_table[i + (1 << (j - 1))][j - 1]]) {
                    sparse_table[i][j] = sparse_table[i][j - 1];
                } else {
                    sparse_table[i][j] = sparse_table[i + (1 << (j - 1))][j - 1];
                }

            }
        }
    }
    int query(int l, int r) {
        int k = floor(log2((r - l + 1)));
        if (a[sparse_table[l][k]] <= a[sparse_table[r - (1 << k) + 1][k]]) return sparse_table[l][k];
        else return sparse_table[r - (1 << k) + 1][k];

    }
};

vector<int> adj[MAXN];
int L[2 * MAXN], H[2 * MAXN], E[2 * MAXN];
int idx = 0;
RMQ *rmq;
void dfs(int node, int depth = 0) {
    E[idx] = node;
    H[node] = idx;
    L[idx] = depth;
    idx++;
    for (auto child : adj[node]) {
        dfs(child, depth + 1);
        E[idx] = node;
        L[idx] = depth;
        idx++;
    }
}

int lca(int a, int b) {
    a = H[a], b = H[b];
    return E[rmq->query(min(a, b), max(a, b))];
}

void pre() {
    vector<int> t(2 * MAXN);
    for (int i = 0; i < 2 * MAXN; i ++) t[i] = L[i];
     rmq = new RMQ(t);
}


int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int n,m, q;
    cin >> n;
    for (int u = 0; u < n; u ++) {
        cin >> m;
        for (int j = 0; j < m; j ++) {
            int v; cin >> v;
            adj[u].push_back(v);
        }
    }
    dfs(0);
    pre();
    cin >> q;
    while (q --) {
        int a, b; cin >> a >>b;
        cout << lca(a, b) << '\n';
    }

}
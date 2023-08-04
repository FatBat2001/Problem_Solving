#include<bits/stdc++.h>
// problem link : https://cses.fi/problemset/task/1687 

#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);

using namespace std;
using ll = long long;


void read_Write();

const int N = 1e6 + 5, M = 105, MOD = 1e9 + 7, oo = 1e8;
using namespace std;
int parent[N];
int up[N][20];

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i ++) {
        cin >> parent[i];
    }
    parent[1] = 0;
    for (int v = 1; v <= n; v ++){
        up[v][0] = parent[v];
        for (int j = 1; j < 20; j ++) {
            up[v][j] = up[ up[v][j - 1] ][j - 1];
        }
    }
    auto query = [&](int x, int k) {
        for (int j = 20; j >= 0;j --) {
            if ((k >> j) & 1)
                x = up[x][j];
            if (!(x)) return -1;
        }
        return x;
    };

    while (q --) {
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << endl;
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
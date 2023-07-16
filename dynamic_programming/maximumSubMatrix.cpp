#include<bits/stdc++.h>

#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);

using namespace std;
using ll = long long;


void read_Write();
const int N = 2e5 + 5, M = 105, MOD = 1e9 + 7, oo = 1e8;
using namespace std;

ll pref[M][M];
ll calc(ll k, ll l, ll i, ll j) {
    return pref[k][l] - pref[i - 1][l] - pref[k][j - 1] + pref[i - 1][j - 1];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) cin >> pref[i][j];
    }
    for (int i = 1; i < M; i ++) {
        for (int j = 1; j < M; j ++) {
            pref[i][j] += pref[i][j - 1];
        }
    }
    for (int j = 1; j < M; j ++){
        for (int i = 1; i < M; i ++) {
            pref[i][j] += pref[i - 1][j];
        }
    }
    ll res= -1e18;
    for (int r_sz = 1; r_sz <= n; r_sz ++) {
        for (int c_sz = 1; c_sz <= n; c_sz ++) {
            for (int i = r_sz; i <= n; i ++) {
                for (int j = c_sz; j <= n; j ++) {
                    res = max(res, calc(i, j, r_sz, c_sz));
                }
            }
        }
    }
    cout << res << endl;
}

int32_t main() {
    read_Write();
    int tt = 1;
//    cin >> tt;
    while (tt --) {
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
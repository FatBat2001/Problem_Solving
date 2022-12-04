#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define all(X) (X).begin(),(X).end()
#define MAX 1e18

using namespace __gnu_pbds;
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
#define int long long
int adjMat[M][M];
int dist[M][M];
int n, m;
void pre_floyd( ){
    for (int i = 1; i < M; i ++ ) {
        for (int j = 1; j < M; j ++ ){
            if (i == j) dist[i][j] = 0;
            else if (adjMat[i][j]){
                dist[i][j] = dist[j][i] = adjMat[i][j];
            }
            else {
                dist[i][j] = MAX;
            }

        }
    }
}
void floyd( ){
    pre_floyd();
    for (int k = 1; k <= n; k ++ ) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1;  j <= n; j ++ ) {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
void solve() {

    // question link : https://cses.fi/problemset/task/1672
    
    int q;
    cin >> n >> m;
    cin >> q;
    for (int i = 0; i < m; i ++ ) {
        int u, v, c;
        cin >> u >> v >> c;
        int last_dist = adjMat[u][v];
        adjMat[u][v] = c;
        adjMat[v][u] = c;
        
        // to check if there is a multiple edges on  the same pair of nodes 
        // we just keep the minimum of them 
        if (last_dist == 0) continue;
        adjMat[u][v] = min(adjMat[u][v], last_dist);
        adjMat[v][u] = min(adjMat[u][v], last_dist);
    }
    floyd();
    while (q -- ) {
        int u, v;
        cin >> u >> v;
        cout << (dist[u][v] == MAX ? -1 : dist[u][v]) << '\n';
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
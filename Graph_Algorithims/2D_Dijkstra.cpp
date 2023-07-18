#include<bits/stdc++.h>

#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);

using namespace std;
using ll = long long;

// problem link : https://codeforces.com/gym/101801/attachments 
void read_Write();

const int N = 1e6 + 5, M = 105, MOD = 1e9 + 7, oo = 1e8;
using namespace std;
#define MAXN 1000005

// stores smallest prime factor for every number
int spf[MAXN];
int bests[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }

}
map<int, int> get_fac(int x)
{
    map<int, int> ret;
    while (x != 1) {
        ret[spf[x]] ++;
        x = x / spf[x];
    }
    return ret;
}
int get_best(int x) {
    map<int, int> mp = get_fac(x);
    auto calc = [&x] (int div){
        return x / div + 2 * div;
    };

    int ans = x;
    for (auto &[div, count] : mp) {
        ans = min(ans, calc(div));
    }
    return ans;
}



ll dist[101][10004];
vector<pair<int, int>> adj[N];
int n, m, k, SOURCE, DESTINATION;
void pre() {
    sieve();
    for (int i = 1; i < N; i ++) {
        bests[i] = get_best(i);
    }
}

ll dijkstra(int src, int dest, int stones) {
    for (int i = 0; i <= n; i ++) for (int j = 0; j <= k; j ++) dist[j][i] = LONG_LONG_MAX;
    set<pair<int, pair<int, int>>> pq;
    dist[k][src] = 0;
    pq.insert({dist[k][src], {stones, src}});
    while (!pq.empty()){
        auto par = *pq.begin();
        pq.erase(par);
        int d = par.first, st = par.second.first, u = par.second.second;
        for (auto [v, c] : adj[u]) {
            // normal dijkstra exploration
            if (dist[st][v] > dist[st][u] + c) {
                dist[st][v] = dist[st][u] + c;
                pq.insert({dist[st][v], {st, v}});
            }
            if (st) {
                if (dist[st - 1][v] > dist[st][u] + bests[c]) {
                    dist[st - 1][v] = dist[st][u] + bests[c];
                    pq.insert({dist[st- 1][v], {st - 1, v}});
                }
            }
        }
    }
    ll mn = LONG_LONG_MAX;
    for (int i = 0; i <= k; i ++) mn = min(mn, dist[i][dest]);
    return mn;
}


void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) adj[i].clear();
    for (int i = 0; i < m; i ++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    cin >> SOURCE >> DESTINATION;
    ll ans = dijkstra(DESTINATION, SOURCE, k);
    if (ans == LONG_LONG_MAX) ans = -1;
    cout << ans << endl;
}

int32_t main() {
    read_Write();
    pre();
    int tt = 1;
    cin >> tt;
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
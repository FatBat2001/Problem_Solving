#include<bits/stdc++.h>

#define int long long

using ll = long long ;
using namespace std;



#define MAX 1e18
const int N = 1e6 + 5, M = 1003, MOD = 1e9 + 7;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
/// 0 1 2 3
/// D U L R

ll mul(ll a, ll b, ll m) {
    return ((a % m) * (b % m)) % m;
}

int n, m, u, v, c;
vector<pair<int, int>> adj[N];
bool processed[N];
ll dist[N];
ll dijkstra(int src, int dest)
{
    // initialize the distance array with infinity for relaxing later
    for (int i = 0; i < N; i ++ ){
        dist[i] = MAX;
    }

    // initialize the priority queue with the source
    priority_queue<pair<ll, int>> pq;
    dist[src] = 0;
    pq.push({0, src});

    // the priority queue solves itself
    while (!pq.empty()) {
        int to_relax_with = pq.top().second;
        pq.pop();
        if (processed[to_relax_with]) continue;
        processed[to_relax_with] = true;
        for (auto neighbor : adj[to_relax_with]) {
            int a = neighbor.first, b = neighbor.second;

            // if any neighbor is relaxed with the current node
            // then it's possible for that node to relax more nodes
            // So it should be pushed to the priority queue
            if (dist[to_relax_with] + b < dist[a]) {
                dist[a] = dist[to_relax_with] + (ll)b;
                pq.push({-dist[a], a});
            }

        }
    }
    return dist[dest];
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ){
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }
    int src, dest;
    cin >> src >> dest;
    ll shortest_distance = dijkstra(src, dest);
    cout << shortest_distance << '\n';
}


int32_t main() {
    int tt = 1;
    cin>>tt;
    while (tt--)
        solve();
    system("pause");
}



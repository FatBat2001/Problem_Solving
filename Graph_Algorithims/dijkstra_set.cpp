#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
using ld = long double;

using namespace std;

const int N = 1e6 + 5, MOD = 1e9 + 7, M = 100 + 3;
vector<pair<int, int>> adj[N];
vector<ll> dist(N, 1e18);

void dijkstra(int src) {
  dist[src] = 0;
  set<pair<int, int>> pq;
  pq.insert({dist[src], src});
  while (!pq.empty()) {
    auto [d, u] = *pq.begin();
    pq.erase(*pq.begin());
    for (auto &[v, c] : adj[u]) {
      if (dist[v] <= dist[u] + c) continue;
      dist[v] = dist[u] + c;
      pq.emplace(dist[v], v);
    }
  }
  
}


int32_t main() {

}

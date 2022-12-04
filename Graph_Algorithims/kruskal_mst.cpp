#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
// you can answer queries ONLINE which means whenever you update the graph you can answer according 
// to the new updates unlike the graph traversals 


struct DSU {
    int parent[N];
    int sz[N];
    // you can add another attribute to keep track of the number of groups 
    // EX : int numGroups = n >> where n is the number of nodes 
    // whenever you connect to unconnected components decrease it by one 


    DSU() {
        for (int i = 0; i < N; i ++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    
    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    bool sameGroup(int x, int y) {
        x = findParent(x);
        y = findParent(y);
        return x == y;
    }

    void join(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        
        if (sz[u] > sz[v]) {
            swap(u, v);
        }

        parent[u] = v;
        sz[v] += sz[u];
        sz[u] = 0;
    }
    int getSize(int x) {
        x = findParent(x);
        return sz[x];
    }
    int getMaxGroup(){
        return *max_element(sz, sz +N);
    }
};
// sort the costs ascendingly then we take the minimum edge that connect two unconnected components 

int n, m, u, v, c;
priority_queue<pair<int , pair<int ,int >> ,vector<pair<int , pair<int ,int >>>, greater<>    > pq;
long long  kruskals() {
    long long  res = 0;
    DSU ds;
    while (!pq.empty()) {
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        int c = pq.top().first;
        pq.pop();
        if (!(ds.sameGroup(u, v))) {

            ds.join(u, v);
            res += c;
        }
    
    }
    return res;

}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> u >> v >> c;
        pq.push({c, {u, v}});
    }

    cout << kruskals() << endl;
    
}
int main () {
    // freopen("C:\\Users\\adham\\Dropbox\\PC\\Documents\\PST\\input.txt","r", stdin);
    // freopen("C:\\Users\\adham\\Dropbox\\PC\\Documents\\PST\\output.txt","w", stdout);
    int tt  = 1;
    // cin >> tt;
    while (tt --) 
        solve();
    
    // system("pause");
}   
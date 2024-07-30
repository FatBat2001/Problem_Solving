#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
// you can answer queries ONLINE which means whenever you update the graph you can answer according 
// to the new updates unlike the graph traversals 
struct node{ 
   long long parent; 
   long long sz;  
}; 

struct DSU { 
    vector<node> a;  
    DSU(int _n) { 
        a.resize(_n + 1); 
        for (int i = 0; i < _n + 1; i ++) { 
            a[i].parent = i;
            a[i].sz = 1;  
        }
    }
    int find(int u) { 
        if (u == a[u].parent) return u; 
        return a[u].parent = find(a[u].parent); 
    }
    void join(int u, int v) { 
        u = find(u); 
        v = find(v); 
        if (u == v) return; 
        if (a[u].sz > a[v].sz) swap(u, v); 
        a[u].sz += a[v].sz; 
        a[v].parent = u; 
        a[v].sz = 0; 
    }
};

int main () {
    // freopen("C:\\Users\\adham\\Dropbox\\PC\\Documents\\PST\\input.txt","r", stdin);
    // freopen("C:\\Users\\adham\\Dropbox\\PC\\Documents\\PST\\output.txt","w", stdout);
    int tt;
    cin >> tt;
    while (tt -- ) {
        
        int n, m;
        cin >> n >> m;
        DSU ds(n);
        for (int i = 0; i < m; i ++) {
            int u, v;
            cin >> u >> v;
            ds.join(u, v);
        }
    }
}   
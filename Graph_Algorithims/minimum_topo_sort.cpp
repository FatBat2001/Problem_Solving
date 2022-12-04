#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();


/*

    the idea behined to topological sort using bfs 
    is just inversion the edges between each pair of nodes 
    so the node that was required for anohter node 
    is now the parent 
    so we can just start the bfs from nodes with in degrees equal to zeros 

*/

const int N = 1e5 + 5;
bool vis[N];
int inDegree[N];
vector<int> adj[N];
int n, m, u, v;
queue<int> order;
void topo_sort_bfs() {
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 1; i<=n; i ++ ){
        if (inDegree[i] == 0){
            q.push(i);
        }
    } 
    while (!q.empty()) {
        int parent = q.top();
        order.push(parent);
        q.pop();
        for (auto child : adj[parent]){
            if (!(--inDegree[child])) {
                q.push(child);
            }
        }
    }

}
bool currentPath[N];
bool cyclic = false;
void isCyclic(int node ){
    vis[node] = true;
    currentPath[node] = true;
    for (auto child : adj[node]){
        if (vis[child] && currentPath[child]) {
            cyclic = true;
        }
        if(!vis[child]){
            isCyclic(child);
        }
    }
    currentPath[node] = false;
}
int main () {
    read_write();
    printf("");
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ){
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v] ++;
    }    
    for (int i = 1; i <= n; i ++ ){
        if (!vis[i]){
            isCyclic(i);
        }
    }
    if (cyclic) {
        return cout << "Sandro fails.", 0;
    }
    topo_sort_bfs();
    while (!order.empty()) {
        cout << order.front ()<< " " ;
        order.pop();
    }
}



void read_write() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE        
    freopen("C:\\Users\\adham\\Documents\\PST\\input.txt", "r", stdin);
    freopen("C:\\Users\\adham\\Documents\\PST\\output.txt", "w", stdout);
    
#   endif    
}
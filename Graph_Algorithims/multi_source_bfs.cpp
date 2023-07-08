#include<bits/stdc++.h>

using ll = long long;
using ld = long double;

using namespace std;

const int N = 1e6 + 5, MOD = 1e9 + 7, M = 100 + 3;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
/// 0 1 2 3
/// D U L R

void read_write();

/*
    problem link : https://codeforces.com/gym/100947/problem/H
*/
int n, m;

int dist1[M][M], dist2[M][M];

bool vis[M][M];
bool valid (int x, int y, vector<string> &grid) {
        return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
};

bool dfs(int x, int y, pair<int, int> &target, vector<string> &grid) {
    if (x == target.first && y == target.second) return 1;
    bool ret= false;
    vis[x][y] = true;
    for(int i = 0; i < 4; i ++){
        int new_x = dx[i] + x, new_y = dy[i] + y;
        if (valid(new_x, new_y, grid) && dist2[new_x][new_y] < dist1[new_x][new_y] && !vis[new_x][new_y]) {
            ret |= dfs(new_x, new_y, target, grid);
        }
    }
    return ret;
}
void solve() {
    
    cin >> n >> m;
    vector<string> grid(n);
    vector<pair<int, int>> sources;
    pair<int, int> sally, slipper;

    
    for (int i = 0; i < n; i ++) {
        cin >> grid[i];
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '*') {
                dist1[i][j] = 0, sources.push_back({i, j});
            } else  {
                dist1[i][j] = INT_MAX;
            }
            if (grid[i][j] == 'S') {
                dist2[i][j] = 0, sally = {i, j};
            } else dist2[i][j] = INT_MAX;
            if (grid[i][j] == 'X') slipper = {i, j};
            vis[i][j] = false;
        }
    }
    
    
    
    queue<pair<int, int>> q;
    for (auto it : sources) q.push(it);
    while (!q.empty()) {
        auto par = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int new_x = dx[i] + par.first, new_y = dy[i] + par.second;
            if (valid(new_x, new_y, grid) && dist1[new_x][new_y] > dist1[par.first][par.second] + 1) {
                dist1[new_x][new_y] = dist1[par.first][par.second] + 1;
                q.push({new_x, new_y});
            }
        }        
    }
    q.push(sally);
    while (!q.empty()) {
        auto par = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int new_x = dx[i] + par.first, new_y = dy[i] + par.second;
            if (valid(new_x, new_y, grid) && dist2[new_x][new_y] > dist2[par.first][par.second] + 1
            ) {
                dist2[new_x][new_y] = dist2[par.first][par.second] + 1;
                q.push({new_x, new_y});
            }
        }
    }
    
    
    if (dfs(sally.first, sally.second, slipper, grid)) {
        cout <<"yes\n";
    } else cout << "no\n";
}
   


int32_t main() {
    read_write();   
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}

void read_write() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#else
 
#  endif
}

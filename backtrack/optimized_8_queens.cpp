#include<bits/stdc++.h>

#define read(FILE) freopen(FILE, "r",stdin);
#define write(FILE) freopen(FILE, "w",stdout);


using namespace std;
using ll = long long;
using ld = long double;

void read_Write();

const int M = 100;

// right diagonal constant -> subtract
// left diagonal constant -> addition
const int MAX = 8;

bool vis[M];
int grid[M];
int left_diag[M], right_diag[M];


vector<int> current_formation;
vector<vector<int>> all_queens;


bool valid(int i, int j) {
    return !vis[j] && !right_diag[i - j +MAX] && !left_diag[i + j];
}

void Do(int i, int j) {
    vis[j] = true;
    current_formation.push_back(j);
    right_diag[i - j + MAX] = left_diag[i + j] = true;
}

void Undo(int i, int j) {
    vis[j] = false;
    current_formation.pop_back();
    right_diag[i - j + MAX] = left_diag[i + j] = false;
}


void eight_queens(int i){
    if (i == 8) {
        all_queens.push_back(current_formation);
        return;
    }

    for (int j = 0; j < 8; j ++) {
        if (valid(i, j)) {
            Do(i, j);
            eight_queens(i + 1);
            Undo(i, j);
        }
    }
}

void solve() {
    eight_queens(0);
    for (int i = 0; i < (int)all_queens.size(); i ++ ){
        for (int j = 0; j < (int)all_queens[i].size(); j ++) {
            cout << all_queens[i][j] << ' ';
        }
        cout << endl;
    }    

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
    freopen("C:\\Users\\adham\\Documents\\PST\\input.txt", "r", stdin);
    freopen("C:\\Users\\adham\\Documents\\PST\\output.txt", "w", stdout);
    
#else

#  endif
}
#include<bits/stdc++.h>

#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define all(X) (X).begin(),(X).end()

using namespace std;
using ll = long long;
using ld = long double;

void read_Write();

const int N = 2e5 + 5, M = 1003, MOD = 1e9 + 7;
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
/// 0 1 2 3
/// D U L R

ll mult(ll  a, ll b) { return (1LL * a * b) % MOD; }

ll mult(ll a, ll b, ll mm) { return (1LL * a * b) % mm; }

ll modSum(ll a, ll b) {
    a = (a % MOD + MOD) % MOD, b = (b % MOD + MOD) % MOD;
    return (a + b) % MOD;
}

ll modSub(ll a, ll b) { return modSum(a, -b); }


/*_____________________________________________________________________________________________________*/



vector<vector<int>> matrixMultiplication(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> c;

    int w, x, y, z;
    w = a.size();
    x = a[0].size();
    y = b.size();
    z = b[0].size();
    
    // when the dimensions of the matrices doesn't fit 
    // we return an empty matrix denoting we couldn't multiply 
    if (x != y) return c;


    c = vector<vector<int>>(w, vector<int>(z));

    for (int cRow = 0; cRow < w; cRow ++ ) {
        for (int cCol = 0; cCol < z; cCol ++ ) {
            for (int k = 0; k < x; k ++ ) {
                c[cRow][cCol] += a[cRow][k] * b[k][cCol];
            }
        }
    }
    return c;

}

void solve() {
    vector<vector<int>> a = {
        {3, 4, -5}
    };

    vector<vector<int>> b = {
        {2}, {5}, {6}
    };


    vector<vector<int>> c = matrixMultiplication(a, b);
    for (auto row : c) {
        for (auto val : row) {
            cout << val << ' ';
        }
        cout << endl;
    }

}


int32_t main() {
    read_Write();
    int tt = 1;
//    cin >> tt;
    while (tt--)
        solve();
}


void read_Write() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    read("input.in")
    write("output.out")
#else

#  endif
}


include <iostream>
#include<vector>
#include <cmath>

using namespace std;
using ll = long long ;
const int MAXN = 2e5 + 5, LOG = 21;

struct RMQ{
    int n;
    vector<int> a;
    vector<vector<int>> sparse_table;
    RMQ(vector<int> &v) {
        a = v;
        n = a.size();
        sparse_table = vector<vector<int>>(n , vector<int>(LOG));
        for (int i = 0; i < n; i ++) {
            sparse_table[i][0] = i;
        }

        for (int j = 1; (1 << j) <= n; j ++) {
            for (int i = 0; i + (1 << j) - 1 < n; i ++) {
                if (a[sparse_table[i][j - 1]] < a[sparse_table[i + (1 << (j - 1))][j - 1]]) {
                    sparse_table[i][j] = sparse_table[i][j - 1];
                } else {
                    sparse_table[i][j] = sparse_table[i + (1 << (j - 1))][j - 1];
                }

            }
        }
    }
    int query(int l, int r) {
        int k = floor(log2((r - l + 1)));
        if (a[sparse_table[l][k]] <= a[sparse_table[r - (1 << k) + 1][k]]) return sparse_table[l][k];
        else return sparse_table[r - (1 << k) + 1][k];

    }
};

int main() {
    int n; cin >> n;
    vector<int>v(n);
    for (int &i : v)cin >> i;
    RMQ* rmq = new RMQ(v);
    
}
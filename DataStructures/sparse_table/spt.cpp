#include <bits/stdc++.h>
#include<vector>
#include <cmath>

using namespace std;
using ll = long long ;
const int MAXN = 2e5 + 5, LOG = 21;

struct SPARSE_TABLE{
    int n;
    vector<int> a;
    vector<vector<pair<int, int>>> sparse_table;
    SPARSE_TABLE(){}
    SPARSE_TABLE(vector<int> &v) {
        a = v;
        n = a.size();
        sparse_table = vector<vector<pair<int,int>>>(n , vector<pair<int, int>>(LOG));
        for (int i = 0; i < n; i ++) {
            sparse_table[i][0].first = sparse_table[i][0].second = i;
        }
        for (int j = 1; (1 << j) <= n; j ++) {
            for (int i = 0; i + (1 << j) - 1 < n; i ++) {
                if (a[sparse_table[i][j - 1].first] < a[sparse_table[i + (1 << (j - 1))][j - 1].first]) {
                    sparse_table[i][j].first = sparse_table[i][j - 1].first;
                } else {
                    sparse_table[i][j].first = sparse_table[i + (1 << (j - 1))][j - 1].first;
                }
                if (a[sparse_table[i][j - 1].second] > a[sparse_table[i + (1 << (j - 1))][j - 1].second]) {
                    sparse_table[i][j].second = sparse_table[i][j - 1].second;
                } else {
                    sparse_table[i][j].second = sparse_table[i + (1 << (j - 1))][j - 1].second;
                }
            }
        }
    }
    int query_min(int l, int r) {
        int k = floor(log2((r - l + 1)));
        if (a[sparse_table[l][k].first] <= a[sparse_table[r - (1 << k) + 1][k].first]) return sparse_table[l][k].first;
        else return sparse_table[r - (1 << k) + 1][k].first ;

    }
    int query_max(int l, int r) {
        int k = floor(log2((r - l + 1)));
        if (a[sparse_table[l][k].second] >= a[sparse_table[r - (1 << k) + 1][k].second]) return sparse_table[l][k].second;
        else return sparse_table[r - (1 << k) + 1][k].second ;
    }
    int get_max(int l, int r) {
        return a[query_max(l, r)];
    }
    int get_min(int l, int r) {
        return a[query_min(l, r)];
    }

};


int main() {
    int n; cin >> n;
    vector<int>v(n);
    for (int &i : v)cin >> i;
    SPARSE_TABLE(v);
    
}
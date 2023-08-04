#include<bits/stdc++.h>
#include <ostream>
using namespace std;
using ll = long long;
/*
    In MO's algorithm we divide the queries into several blocks 
    the left handside of the query decides which block it should be in 
    q -> (l, r)
    goes to block -> l / sqrt(sizeof(array)) 
    for the elements in the same block 
    we sort them by the Ri < Rj 

    Mo algorithm can be used if you have multiple queries on how many distinct elements in some array 
*/
// problem link : https://www.spoj.com/problems/DQUERY/ 

const int N = 1e6 + 6;

int freq[N];

struct query{
    int left = -1;
    int right = -1;
    int block_index = -1;
    int query_index = -1;
    query(){}
    query(int _left, int _right, int _query_index, int square):
            left(_left), right(_right), block_index(_left/square), query_index(_query_index) {}
    bool operator <(const query &q) const {
        if (block_index == q.block_index) return right < q.right;
        return block_index < q.block_index;
    }

};

void add(int i, vector<int> &a, ll &res){ freq[a[i]] ++; if (freq[a[i]] == 1) res += 1;}
void remove(int i, vector<int> &a, ll &res) { freq[a[i]] --; if (freq[a[i]] == 0) res -= 1;}

vector<ll> MO(vector<int> &a, vector<query> &queries) {
    vector<ll> ans(queries.size());
    sort(queries.begin(), queries.end());
    int l = 1, r = 0;
    ll curr_ans = 0;
    for (auto q : queries) {
        while (l > q.left) add(--l, a, curr_ans);
        while (l < q.left) remove(l++, a, curr_ans);
        while (r > q.right) remove(r--, a, curr_ans);
        while (r < q.right) add(++r, a, curr_ans);
        ans[q.query_index] = curr_ans;
    }
    return ans;
}

int32_t main() {
    int n, q;
    cin >> n;
    vector<int>  a(n);
    vector<query> queries;
    for (int &i : a) cin >> i;
    int root = (int)sqrt(n), idx = 0;
    cin >> q;
    queries = vector<query>(q);
    while (q --) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        query Q(l, r, idx, root);
        queries[idx++] = Q;
    }
    vector<ll> v= MO(a, queries);
    for (auto it : v) cout << it <<
    '\n';

}

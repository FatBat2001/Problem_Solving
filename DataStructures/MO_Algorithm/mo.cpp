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

*/

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

void add(int i, vector<int> &a, ll &sum){ sum += a[i];}
void remove(int i, vector<int> &a, ll &sum) { sum -= a[i];}

vector<ll> MO(vector<int> &a, vector<query> &queries) {
    vector<ll> ans(queries.size());
    sort(queries.begin(), queries.end());
    int l = 0, r = 1;
    ll curr_sum = a[l] + a[r];
    for (auto q : queries) {
        while (l > q.left) add(--l, a, curr_sum);
        while (l < q.left) remove(l++, a, curr_sum);
        while (r > q.right) remove(r--, a, curr_sum);
        while (r < q.right) add(++r, a, curr_sum);
        ans[q.query_index] = curr_sum;
    }
    return ans;
}

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int>  a(n);
    vector<query> queries(q);
    for (int &i : a) cin >> i;
    int root = sqrt(n), idx = 0;
    while (q --) {
        int l, r; 
        cin >> l >> r;    
        l--, r--;
        query q(l, r,idx, root);
        queries[idx++] = q;
    }
    vector<ll> v= MO(a, queries);
    for (auto it : v) cout << it << '\n';

}

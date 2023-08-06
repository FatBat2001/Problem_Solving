#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Fenwick {
    vector<ll> bit;
    Fenwick() {}
    Fenwick(vector<int> &A) {
        bit = vector<ll>(A.size() + 1);
        for (int i = 0; i < (int)A.size(); i ++) { // fenwick tree is one based so we update from i + 1 instead of i 
            update(i + 1, 0, A[i]);    
        }
    }
    void update(int index, int old_value, int new_value) {
        for (int i = index; i < (int)bit.size(); i += (i & -i)) {
            bit[i] -= old_value; // undo operation 
            bit[i] += new_value; // do operation;
        }
    }
    ll get(int index) {
        ll res = 0;
        for (int i = index; i >= 1; i -= (i & -i)) {
            res += bit[i];
        }
        return res;
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    Fenwick T(v);
    while (q --) {
       int type;
       cin >> type;
       if (type == 1) {
           int index, val; cin >>index >> val;
           T.update(index, v[index -1 ],   val);
           v[index - 1] = val;
       } else {
           int l, r; cin >> l >> r;
           cout << T.get(l, r) << endl;
       }
    }
}
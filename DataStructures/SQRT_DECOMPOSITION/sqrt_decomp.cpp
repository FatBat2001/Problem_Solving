#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

vector<int> a;
vector<ll> blocks;
ll get(int l, int r) {
    ll res = 0;
    int root = blocks.size();
    for (int i = l; i <= r; ) {
        if (i % root == 0 && i + root - 1 <= r) res += blocks[i / root], i += root; // take the whole block 
        else res += a[i++]; // take a sgement of sqrt sized block in linear time 
    } 
    return res;
}

void update(int index, int val) {
    int root = blocks.size();
    blocks[index/root] -= a[index]; // Undo
    a[index] = val; // update 
    blocks[index/root] += a[index]; // Do 
}

int32_t main() {
    int n, q;
    cin >> n >> q;
    a = vector<int>(n);
    int root = ceil(sqrt(n));
    blocks = vector<ll>(root);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        blocks[i/root] += a[i];
    }
    while (q --) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, val;
            cin >> index >> val;
            update(index-1,  val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get(l- 1, r - 1) << endl;
        }
    }
}

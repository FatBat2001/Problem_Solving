#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define all(X) (X).begin(),(X).end()
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ld = long double;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type,
        less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set_pair;

void read_Write();

const int N = 1e6 + 5, M = 1003, MOD = 1e9 + 7, oo = 1e8;
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
/// 0 1 2 3
/// D U L R

ll mult(ll a, ll b) { return (1LL * a * b) % MOD; }

ll mult(ll a, ll b, ll mm) { return (1LL * a * b) % mm; }

ll modSum(ll a, ll b) {
    a = (a % MOD + MOD) % MOD, b = (b % MOD + MOD) % MOD;
    return (a + b) % MOD;

}

ll modSum(ll a, ll b, int mod) {
    a = (a % mod + mod) % mod, b = (b % mod + mod) % mod;
    return (a + b) % mod;
}

ll modSub(ll a, ll b) { return modSum(a, -b); }

ll modSub(ll a, ll b, int mod) { return modSum(a, -b, mod); }


/*_________________________________________________________________________________________________________*/

ll Tree[4 * N], lazy[4 * N], arr[N];
int n, m;

void propagate(int node, int l, int r) {
    if (lazy[node] == 0)
        return;
    Tree[node] += lazy[node];
    if (l != r) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int l, int r, int st, int en, ll val) {
    propagate(node, l, r);
    if (st > en || st > r || en < l)
        return;
    if (l >= st && r <= en) {
        lazy[node] += val;
        propagate(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, st, en, val);
    update(node * 2 + 1, mid + 1, r, st, en, val);
    Tree[node] = min(Tree[node * 2], Tree[node * 2 + 1]);
}

ll query(int node, int l, int r, int st, int en) {
    propagate(node, l, r);
    if (st > en || st > r || en < l)
        return 1e18;
    if (l >= st && r <= en)
        return Tree[node];
    int mid = (l + r) / 2;
    return min(query(node * 2, l, mid, st, en), query(node * 2 + 1, mid + 1, r, st, en));
}
void update(int l, int r,int val){
    return update(1, 0, n-1,l,r,val);
}
ll query(int l, int r) {
    return query(1,0,n-1,l,r);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        update(i, i, val);
    }
    cin >> m;
    while (m --) {
        int a, b, c;
        cin >> a >> b;
        if (cin.peek() != '\n') {
            cin >> c;
            if (a <= b) {
                update(a, b, c);
            } else {
                update(a, n - 1, c);
                update(0, b, c);
            }
        } else {
            if (a <= b) {
                cout << query(a, b) << '\n';
            } else {
                cout << min(query(a, n - 1), query(0, b)) << '\n';
            }
        }
    }
}


int32_t main() {
    read_Write();
    int tt = 1;
//    cin >> tt;
    while (tt--) {
        solve();
    }
}


void read_Write() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    read("input.txt")
    write("output.txt")
#else

#  endif
}
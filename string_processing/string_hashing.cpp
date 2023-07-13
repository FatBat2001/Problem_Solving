// prooblem link : https://www.spoj.com/problems/NHAY/ 

#include<bits/stdc++.h>

using ll = long long;
using ld = long double;

using namespace std;

const int N = 1e7 + 5, MOD = 1e9 + 7;

void read_write();
/*
    The hash function used in rabin karp is as follows 
                      i=n-1                      
    h(str) = summation       (c * x ^ L - i -  1) % p;
                      i=0  


    Here I used a single hash function 
    the correct implementation takes the values of 2 hash functions to 
    make the probability of error relatively small 

*/


ll mult(ll a, ll b, ll mm) { return (1LL * a * b) % mm; }

int fastPower(int base, int power , int mod) {
    int res =1 ;
    while (power) {
        if (power & 1)
            res = mult(base, res, mod);
        power /= 2, base = mult(base, base, mod);
    }
    return res;
}

int modInv(int a, int m) {
    return fastPower(a, m - 2, m);
}

ll xpow1[N ], xpow2[N];

int x = 128, p1 = 1e9 + 7, p2 = 1e9 + 9;

ll push_back(ll hash, ll x, ll p, char ch){
    return ((hash * x) % p + ch) % p;
}

ll pop_back(ll hash, ll x, ll p, char ch) {
    return ((((hash - x) % p + p) % p) * modInv(x,p)) % p;
}

ll push_front(ll hash, ll xp, ll p, char ch) { // xp = xpow[oldLen]
    return (hash + (xp * ch) % p) % p;
}

ll pop_front(ll hash, ll xp, ll p, char ch) { // xp = xpow[oldLen - 1]
    return ((hash - (xp * ch) % p) % p + p) % p;
}




void pre()  {
    xpow1[0] = 1;
    xpow2[0] = 1;
    for (int i = 1; i < N; i ++) {
        xpow1[i] = (xpow1[i - 1] * x) % p1;
        xpow2[i] = (xpow2[i - 1] * x) % p2;
    }

}

void solve() {
    int TEST;
    
    while (cin >> TEST) { 
        string a, b;
        cin >> b >> a;
        int n = a.length(), m = b.length();
        ll hash = 0, sub_hash = 0;
        for (int i = 0; i < min(n, m); i ++) {
            hash = push_back(hash, x, p1, b[i]);
            sub_hash = push_back(sub_hash, x, p1, a[i]);
        }
        vector<int> occurrences;
        if (n >= m && hash == sub_hash) occurrences.push_back(0);
        for (int i = m; i < n; i ++) {
            sub_hash = pop_front(sub_hash, xpow1[m - 1],p1, a[i - m]);
            sub_hash = push_back(sub_hash, x, p1, a[i]);
            if (sub_hash == hash) {
                occurrences.push_back(i - m + 1);
            }
        }
        if (!occurrences.empty()) {
            for (auto it : occurrences) cout << it << endl;
        } else cout << endl;
    }


}


int32_t main() {
    read_write();
    pre();
    int tt = 1;
    // cin >> tt;
    while (tt --) {
        solve();
    }
}

void read_write() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../../input.in", "r", stdin);
    freopen("../../output.out", "w", stdout);
#else
 
#  endif
}

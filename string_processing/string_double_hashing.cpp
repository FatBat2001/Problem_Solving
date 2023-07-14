// prooblem link : https://vjudge.net/problem/SPOJ-ADACLEAN 

#include<bits/stdc++.h>

using ll = long long;
using ld = long double;

using namespace std;

const int N = 1e6 + 5, MOD = 1e9 + 7;

void read_write();
/*
    The hash function used in rabin karp is as follows 
                      i=n-1                      
    h(str) = summation       (c * x ^ L - i -  1) % p;
                      i=0  
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
/* 
    using this formula 
    (a, b) = (a * max(b) + b) 
    we can represent the pair a, b without making a pair datastructure 
    
*/
void solve() {
    string str;
    int n, k;
    cin >> n >> k >> str;
    unordered_set<ll> s;
    ll hash1 = 0, hash2 = 0;
    for (int i = 0; i < k; i++) {
        hash1 = push_back(hash1, x, p1, str[i]);
        hash2 = push_back(hash2, x, p2, str[i]);
    
    }

    s.insert((hash1 * p2) + hash2);
    

    for (int i = k; i < n; i ++) {
        hash1 = push_back(hash1, x, p1, str[i]);
        hash1 = pop_front(hash1, xpow1[k], p1, str[i - k]);
        
        hash2 = push_back(hash2, x, p2, str[i]);
        hash2 = pop_front(hash2, xpow2[k], p2, str[i - k]);
    
        s.insert((hash1 * p2) + hash2);
    }

    cout << s.size()<< endl;
}


int32_t main() {
    read_write();
    pre();
    int tt = 1;
    cin >> tt;
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

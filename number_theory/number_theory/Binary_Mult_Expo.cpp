#include <bits/stdc++.h>
#define read(FILE) freopen(FILE,"r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);

using ll = long long;
using namespace std;
void read_write();

ll mult(ll a, ll b, ll mm) { return (1LL * a * b) % mm; }
 
ll modSum(ll a, ll b, int MOD) {
    a = (a % MOD + MOD) % MOD, b = (b % MOD + MOD) % MOD;
    return (a + b) % MOD;
}

ll binary_expo(int base, int power, int mod) {
    ll res = 1;
    while (power) {
        if (power & 1) res = mult(res, base, mod);
        base = mult(base, base, mod);
        power >>= 1;
    }
    return res;
}

ll binary_mult(int a, int b, int mod) {
    ll res = 0;
    while (b) {
        if (b & 1)  {res = modSum(res, a, mod);}
        a = modSum(a, a, mod);
        b >>= 1;
    }
    return res;
}

void solve() {
      
}


int32_t main (){
    read_write();
    solve();

}



void read_write() {
ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE        
    read("C:\\Users\\adham\\Documents\\PST\\input.txt")
    write("C:\\Users\\adham\\Documents\\PST\\output.txt")
#   endif    
}
#include <bits/stdc++.h>
#define read(FILE) freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);

using namespace std;
using ll = long long;

void read_write();

const int N = 1e6 + 5, M = 103, MOD = 2000014033, oo = 1e8;

/*
    this calculates NCR correctly up to 100C100
    line : https://vjudge.net/contest/464603#problem/I
*/
int fac[M], inv[M];

ll mult(ll a, ll b)
{
    return (1LL * a * b) % MOD;
}

int binary_pow(int base, int power)
{
    int res = 1;
    while (power)
    {
        if (power & 1)
        {
            res = mult(res, base);
        }
        power /= 2;
        base = mult(base, base);
    }
    return res;
}

void pre()
{
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < M; i++)
    {
        fac[i] = mult(fac[i - 1], i);
        inv[i] = binary_pow(fac[i], MOD - 2);
    }
}

int ncr(int n, int r)
{
    if (r > n)
        return 0;
    return mult(fac[n], mult(inv[n - r], inv[r]));
}
 

void solve()
{
    int n, r;
    cin >> n >> r;
    cout << ncr(n, r) << endl;
}

int32_t main()
{
    read_write();
    pre();
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
}

void read_write()
{
    ios::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    read("C:\\Users\\adham\\Documents\\PST\\input.txt")
        write("C:\\Users\\adham\\Documents\\PST\\output.txt")
#endif
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mul(ll a, ll b, ll m) {
    return ((a % m) * (b % m)) % m;
}

ll fac(ll n) {
    return n == 0 ? 1 : n * fac(n - 1);
}

ll NCR(int a, int b) {
    return fac(a) / fac(b) * fac(a - b);
}

int lis(const vector<int> &v) {
    vector<int> ans;
    for (int i = 0; i < v.size(); i++) {
        auto idx = lower_bound(ans.begin(), ans.end(), v[i]);
        if (idx == ans.end()) {
            ans.push_back(v[i]);
        } else {
            *idx = v[i];
        }
    }
    return ans.size();
}

int printSubsBitmasks(const vector<int> &v) {
    int ans = 1;
    for (int mask = 0; mask < (1 << v.size()); mask++) {
        int cnt = 0, temp = -1;
        for (int i = 0; i < v.size(); i++) {
            if ((mask >> i) & 1) {
                if (v[i] > temp) {
                    cnt++;
                    temp = v[i];
                } else {
                    break;
                }
            }

        }
        ans = max(ans, cnt);
    }
    return ans;
}

ll fastPower(ll base, ll power) {
    ll res = 1;
    while (power) {
        if (power & 1) {
            res *= base;
        }
        base *= base, power /= 2;
    }
    return res;
}

ll modularExpo(ll base, ll power, ll mod) {
    ll res = 1;
    while (power) {
        if (power & 1) {
            res = (mul(res, base, mod));
        }
        base = mul(base, base, mod), power /= 2;
    }
    return res;
}

vector<int> factors(int n) {
    vector<int> ans;
    ans.push_back(1);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) {
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}

vector<int> primeFactors(int n) {
    vector<int> ans;
    if (n == 1) {
        ans.push_back(1);
        return ans;
    }
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            ans.push_back(i);
        }
    }
    if (n > 1)
        ans.push_back(n);
    return ans;
}

ll gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * (b / __gcd(a, b));
}
int32_t main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
       
} 
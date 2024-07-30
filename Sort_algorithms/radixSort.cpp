#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e6 + 5, M = 5000, bigMod = 2000014033, MOD = 998244353, LOG = 18;
const long long LONG_MN = -1e18;

const int base = 10;
void countSort(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> count(base);
    vector<int> output(n);
    for (int i = 0; i < n; i ++ )
        count[(a[i] / exp) % base] += 1;

    for (int i = 1; i < base; i ++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i -- ) {
        output[count[(a[i] / exp) % base] - 1] = a[i];
        count[(a[i] / exp) % base]--;
    }
    a = output;
}

void radixSort(vector<int> &a) {
    int Max = *max_element(a.begin(), a.end());
    for (int exp = 1; Max / exp; exp *= 10)  {
        countSort(a, exp);
    }
}

void F() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    radixSort(a);
    for (auto it : a) cout << it << ' ';
    cout << endl;
}


int32_t main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr), cout.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) F();
}
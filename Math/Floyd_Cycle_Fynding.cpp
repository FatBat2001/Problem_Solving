// problem link : https://vjudge.net/problem/UVA-350
#include <iostream>
#include<vector>
#include <cmath>

using namespace std;
using ll = long long ;
const int MAXN = 2e5 + 5, LOG = 21;

int test_case = 1;
ll Z, L, I, M;

ll f(ll x) {
    return (Z * x + I) % M;
}

pair<int, int> floyd_cycle_finding(ll x0 = L) {
    ll tortoise, hare;
    tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    int mu = 0, lambda = 0;
    hare = x0;
    while (hare != tortoise) {
        hare = f(hare);
        tortoise = f(tortoise);
        mu += 1;
    }
    hare = f(tortoise);
    while (hare != tortoise) {
        hare = f(hare);
        lambda ++;
    }
    return {mu, lambda};
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    while (cin >> Z >> I >> M >> L) {
        if (!Z && !I && !M && !L) return 0;
        cout << "Case " << test_case++ << ": ";
        cout << floyd_cycle_finding().second + 1 << endl;
    }
}
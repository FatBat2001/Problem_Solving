#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void read_write();





/* 
    *** to solve any recursive problem (minimum, maximum, ...) all kinds of stuff 
    *** We need to define three things 
    
    1- Define your problem in terms of index 
    2- Do all stuff on that index (brute forcing with recursion)
    3- Take the minimum, maximum answer 

    just write the recurrunce then 

    Apply memoization 




*/

/* 
    Frog jump Problem 
*/

int n;
vector<ll> dp;
vector<int> v;
ll fun(int i) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];

    ll left = abs(v[i] - v[i - 1]) + fun(i - 1);
    ll right = 1e18 + 5;
    if (i > 1)
        right = abs(v[i] - v[i - 2]) + fun(i - 2);
    return dp[i] = min(left ,right);
}
int main () {
    read_write();
    int n;
    cin >> n;
    v.resize(n + 1);
    dp = vector<ll>(n + 1, -1);
    for (int i = 0; i < n; i ++ ) {
        cin >> v[i];
    }
    cout << fun(n - 1);
}



void read_write() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE        
    freopen("C:\\Users\\adham\\Documents\\PST\\input.txt", "r", stdin);
    freopen("C:\\Users\\adham\\Documents\\PST\\output.txt", "w", stdout);
    
#   endif    
}
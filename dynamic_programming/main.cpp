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

int n, capacity;
vector<ll> dp;
vector<int> v;
ll solve(int i, int rem) {
    if (i < 0) return 0;
    if (rem < 0) return 0;
    ll left = solve(i - 1, rem);
    ll curr_remainder = rem - v[i];
    ll right = 0;
    if (curr_remainder > 0) {
        right = solve(i - 1, curr_remainder);
    }
    
    return max(left, right);
}
int32_t main () {
    read_write();
    int tt, cnt = 0;
    cin >> tt;
    while (tt --) {
        cin >> capacity >> n;
        v.resize(n);
        dp = vector<ll> (n, -1);
        for (auto &it : v)
            cin >> it;
        cout << "Hey stupid robber, you can get " << solve(n, ) << ".\n";

    }
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
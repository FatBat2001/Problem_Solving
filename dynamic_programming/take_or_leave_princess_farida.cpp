#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using ll = long long;
vector<int> arr;
vector<ll> mem;
int n;
    
ll solve(int i) {
    if (i>=n) return 0;
    if (mem[i] != -1) return mem[i];
    ll op1 = arr[i] + solve(i + 2);
    ll op2 =  solve(i + 1);
    return mem[i] = max(op1, op2);
}
int main() {
    freopen("C:\\Users\\adham\\Documents\\PST\\input.txt", "r", stdin);
    freopen("C:\\Users\\adham\\Documents\\PST\\output.txt", "w", stdout);
    
    cin >> n;
    arr.resize(n);
    mem = vector<ll>(n, -1);
    for (auto &it : arr) 
        cin >> it;
    cout << solve(0) << '\n';

}
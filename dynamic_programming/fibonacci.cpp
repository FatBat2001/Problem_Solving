#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int mem[N];
int solve(int i ) {
    if (i == 0 || i == 1) return i;
    if (mem[i] != -1) return mem[i];
    int option_1 = solve(i - 1);
    int option_2 = solve(i - 2);
    return mem[i] = option_1 + option_2;
}
int main () {
    memset(mem, -1, N);
    int n;
    cin >> n;
    cout << solve(n) << endl;
}
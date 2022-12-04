#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
void read_write();



/*
    Longest Increasing Subsequence 

    also pick and leave approach 

    we are on element (i) we need to find a subsequence in the array 
    where all elements with indexes greater than (i) have greater values 
    than (i) 
    so, we pick or leave on i 
    if we picked i then we go to i + 1, and the other state is index of the last element
    we picked which is i , so all values in this path should be greater than a[i]

    compexity N * N
    O(n ^ 2)
    
    state : (i, j) i -> current element, j -> last element we picked
    

*/
int mem[3003][3003];
int arr[N];
int n;
int solve(int i, int last) {
    if (i == n + 1) return 0;
    if (mem[i][last] != -1) return mem[i][last];
    int take = arr[i] > arr[last] ? solve(i + 1, i) + 1 : 0;
    int leave = solve(i + 1, last);
    return mem[i][last] = max(take, leave);
}
int main () {
    read_write();
    memset(mem, -1, sizeof mem);
    cin >> n;

    arr[0] = 0;
    
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
    cout << solve(1, 0) << endl;
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
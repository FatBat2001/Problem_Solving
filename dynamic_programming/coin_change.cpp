#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();





 // uva coinst change : put the line here adham don't forget 


/*
    You have five types of coins 
    1, 5, 10, 25, 50
    and you have a number that you want to represent,
    using these coins 
    so, what is the number of ways you can represent the number
    using these coins?
*/

ll mem[5][10000];
int coins[] = {1, 5, 10, 25, 50};

ll solve(int i, int rem) {
    if (rem == 0) return 1;
    if (i == 5 || rem < 0) return 0;
    if (mem[i][rem] != -1) return mem[i][rem];
    ll leave = solve(i + 1, rem);
    ll take = rem >= coins[i] ? solve(i, rem - coins[i]) : 0;
    return mem[i][rem] = take + leave;
}

int main () {
    read_write();
    memset(mem, -1, sizeof mem);
    // this problem has multiple test cases 
    // but the solution doesn't change becasue we have the same shit every time 
    // preprocess the first 10000 numbers 
    // then answer directly from the mem array 

    // note : this problem got TLE without fast input, output 
    
    solve(0,10000);
    
    int n;
    while (cin >> n, n) {
        cout << solve(0, n) << '\n';
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
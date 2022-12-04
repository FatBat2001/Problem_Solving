#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();


/*
    Longest Common Subsequence (LCS)
    this problem prompts us to find the longest common subseqeunce 
    in two strings.

    also take and leave approach 

    we hold one character in the first string 
    and increment the counter on the other 
    until we find a match 
    we do so on the second string 
    when we find a match we increment both counters
    and increment the total answer by one 


    ex: 
    acbefg
    arcehnfg
    
    lcs for strings : 5 (acefg)

*/

string a, b;
int n, m;
int mem[3003][3003];

int solve(int i, int j) {
    // if we reached the end of any string that's the base case 
    if (i == n || j == m) return 0;
    
    // checking if we already went this path 
    if (mem[i][j] != -1) return mem[i][j];

    // solving the problem

    // if we found a match we increment the total answer of the current path 
    // and we increment both i, j
    if (a[i] == b[j]) return mem[i][j] = 1 + solve(i + 1, j + 1);
    
    // else we make the recursive solution
    int take_first_leave_second = solve(i , j + 1);
    int take_second_leave_first = solve(i + 1, j);

    // we return the maximum of the current paths 
    return mem[i][j] = max(take_first_leave_second, take_second_leave_first);
}

void print(int i, int j) {
    if (i == n || j == m) return;
    
    if (a[i] == b[j])  {
        cout << a[i];
        print(i + 1, j + 1);
    
    } else {
        int optimal_path = solve(i, j);
        int take_first_leave_second = solve(i , j + 1);
        if (optimal_path == take_first_leave_second) {
            print(i, j + 1);
        } else {
            print(i + 1, j);
        }
    }    
    
    
}

int main () {
    read_write();
    memset(mem, -1, sizeof mem);
    cin >> a >> b;   
    n = a.length();
    m = b.length();
    solve(0, 0);
    print(0, 0);
    
}



void read_write() {
    // ios::sync_with_stdio(false),
    //         cin.tie(nullptr),
    //         cout.tie(nullptr);
#ifndef ONLINE_JUDGE        
    freopen("C:\\Users\\adham\\Documents\\PST\\input.txt", "r", stdin);
    freopen("C:\\Users\\adham\\Documents\\PST\\output.txt", "w", stdout);
    
#   endif    
}
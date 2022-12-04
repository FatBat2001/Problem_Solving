#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();




/*
    creating all subsets 
    and getting the longest increasing subsequence 
*/
vector<int> subset, v;
int n;
int mx = 0;
void solve(int i) {
    if (i == n) {
        bool flag = true;
        for (int i = 0; i < (int)(subset.size() - 1); i ++ ) {
            if (subset[i] >= subset[i + 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            mx = max((int)subset.size(), mx);
        }
        return;
    }
    solve(i + 1);
    subset.push_back(v[i]);
    solve(i + 1);
    subset.pop_back();
}
int main () {
    read_write();
    
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i ++ ) {
        cin >> v[i];
    }
    
    solve(0);
    
    cout << mx << endl;
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
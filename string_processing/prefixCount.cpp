
#include<bits/stdc++.h>
using namespace std;

/*
    Counting the number of occurences of each prefix for a string 
*/

vector<int> kmp(string &str) {
    int n = (int)str.size();
    vector<int> prefix(n);
    int border = 0;
    prefix[0] = border;
    for (int i = 1; i < n; i ++) {
        while (border > 0 && str[i] != str[border]) {border = prefix[border - 1];}
        if (str[i] == str[border]) border++;
        prefix[i] = border;
    }
    return prefix;
}

vector<int> prefixOccourenceCount(string str) { 
    int n = str.size(); 
    vector<int> ans(n + 1); 
    vector<int> pi = kmp(str); 
    for (int i = 0; i < n; i ++) 
        ans[pi[i]] ++; 
    for (int i = n - 1; i > 0; i --)
        ans[pi[i - 1]] += ans[i]; 
    for (int i = 0; i <= n; i ++) 
        ans[i] ++; 
    return ans; 
}

void solve() {
    string str; 
    cin >> str; 
    vector<int> pref = prefixOccourenceCount(str); 
    int q; 
    cin >> q; 
    while (q --) { 
        int x; 
        cin >> x; 
        cout << pref[x] << endl; 
    }
}

int main() {
    int tt = 1;
    // cin >> tt;
    while (tt --) 
        solve();
}
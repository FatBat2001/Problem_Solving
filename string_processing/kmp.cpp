// problem link : https://www.spoj.com/problems/NAJPF/ 
#include<bits/stdc++.h>
using namespace std;
/*
    let's define prefix(i) as the longest substring from the beginning 
    matchig with current substring starting from i 
    , that's just it 
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

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    if (m > n) return cout << "Not Found\n",void();
    s2 = s2 + "$" + s1;
    vector<int> pref = kmp(s2);
    vector<int> ans;
    for (int i = 0; i < (int)pref.size(); i ++) {
        if (pref[i] == m)
            ans.push_back(i - 2 * m + 1);
    }
    if (ans.empty()) {
        cout << "Not Found\n";
    }
    else {
        cout << ans.size() << '\n';
        for (auto it: ans) cout << it << ' ';
        cout << "\n";
    }
    cout << '\n';
}

int main() {
    int tt;
    cin >> tt;
    while (tt --) 
        solve();
}
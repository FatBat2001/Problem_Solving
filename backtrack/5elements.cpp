#include<bits/stdc++.h>
using namespace std;
#define read(FILE) freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
using ll = long long;
const int n = 5;
int arr[10];
// you have five numbers and you have to find if 
// (((a * b) * c) * d) * e = 23
// where the * sign refers to any of the operators {*, +, -}


bool check(int i, int res) {
    if (i == n) {
        return res == 23;
    }
    bool ans = false;
    ans |= check(i + 1, res * arr[i]);
    ans |= check(i + 1, res + arr[i]);
    ans |= check(i + 1, res - arr[i]);
    return ans;
}
void solve () {
    for (int i = 0; i < n; i ++ ) {
        cin >> arr[i];
    }
    sort(arr, arr +n );
    do {
        if (check(1, arr[0])){
            cout << "Possilbe\n";
            return;
        }
    } while (next_permutation(arr, arr +n));
    cout << "Impossible\n";
}
int main ()
{
    read("C:\\Users\\adham\\Dropbox\\PC\\Documents\\PST\\input.txt");
    write("C:\\Users\\adham\\Dropbox\\PC\\Documents\\PST\\output.txt");
    int tt = 1;
    //cin>>tt;
    while (tt --) {
        solve();
    }

}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();




const int N = 101;
int a[N];
int main () {
    read_write();
    while (true) {
        int n;
        cin >> n;
        if (!n) {break;}
        for (int i = 0; i < n; i ++) {
            int val; cin >> val;
            a[val] ++;
        }
        for (int i = 0; i <= N; i ++ ) {
            while (a[i]) {
                cout << i << ' ';
                a[i] --;
            }
        }
        cout << endl;
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
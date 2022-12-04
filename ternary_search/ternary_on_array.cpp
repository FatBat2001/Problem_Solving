#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();

int find_minimum_peak(int arr[], int n) {
    int start = 0, end = n - 1, m1, m2;
    while (start <= end) {
        m1 = start + (end - start) / 3;
        m2 = end - (end - start) / 3;
        if (arr[m1] > arr[m2]) {
            start = m1 + 1;
        } else {
            end = m2 - 1;
        }
    }
    // m2 breaks the loop 
    // makes the end go less than start 


    return m1;
}

int find_maximum_peak(int arr[], int n) {
    int start = 0, end = n - 1, m1, m2;
    while (start <= end) {
        m1 = start + (end - start) / 3;
        m2 = end - (end - start) / 3;
        if (arr[m1] < arr[m2]) {
            start = m1 + 1;
        } else {
            end = m2 - 1;
        }
    }
    return m1;
}

void solve() {
    int a[] {1, 2, 3, 4, 5, 4, 3, 2 ,1};
    int b[] {5, 4 ,3, 2, 1, 2, 3, 4, 5};
    int n = sizeof a / sizeof(int);


    int index = find_maximum_peak(a, n);
    cout << index << ' ' << a[index] << '\n';
    index = find_minimum_peak(b, n);
    cout << index << ' ' << b[index] << '\n';
    
}




int main () {
    read_write();
    int tt = 1;
    while (tt --) {
        solve();
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
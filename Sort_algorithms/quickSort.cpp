#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();
const int N = 2e5 + 5;

/*
    Memory Complexity O(n)
    Time Complexity O(N long(N))
    but it's not guarenteed
    because it has a worst case of sorting a sorted array 
    so the time complexity will be O(n ^ 2);
    but over all it gives a better performance and less memory complexity 
    than merge sort 
    and with few optimizations it can realy reach a good time near O(n log n )
    
*/
int a[N];
int cnt = 0;
int partition(int s, int e) {
    int index = s;
    while (index < e) {
        cnt++;
        if (a[e] < a[s]) {
            cnt ++;
            swap(a[e], a[++index]);
        } else {
            --e;
        }
    }
    swap(a[s], a[index]);
    return index;
}
void quickSort(int s, int e) {
    if (s >= e) return;
    int piviodIndex = partition(s, e);
    quickSort(s, piviodIndex - 1);
    quickSort(piviodIndex + 1, e);
}
int main () {
    read_write();
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    quickSort(0, n - 1);
    cout<<cnt<<endl;
      
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
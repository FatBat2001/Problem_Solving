#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
void read_write();



/*
    Memory Complexity N * 2
    Time Complexity O(N log N)
    
*/

int a[N],tmp[N];
void merge (int begin1, int end1, int begin2, int end2){ 
    // keeping track of the begin of the segment in the real array 
    int ind = 0, beginHolder = begin1;

    // the temp we will merge into 
    vector<int> temp(end2 - begin1 + 5);
    while (begin1 <= end1 && begin2 <= end2) {
        if (a[begin1] > a[begin2]) {
            temp[ind ++] = a[begin2 ++];
        } else {
            temp[ind ++] = a[begin1 ++ ];
        }
    }

    // if the loop is finished and one array still has elements in it 
    while (begin1 <= end1) {temp[ind++] = a[begin1++];}
    while (begin2 <= end2) {temp[ind++] = a[begin2++];}

    // copying sorted elements to the array 
    for (int i = 0; i < ind; i ++ ){
        a[i + beginHolder] = temp[i];
    }

}
void mergeSort(int begin, int end) {
    if (begin >= end) return;
    int mid = (begin + end) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, mid + 1, end);
}
int main () {
    read_write();
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i ++ ){
        cout << a[i] << " ";
    }
    cout << endl;

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
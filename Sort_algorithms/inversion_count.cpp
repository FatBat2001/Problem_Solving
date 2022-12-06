#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
void read_write();



/*
    Inversion Count 
    same mergesort implementation 
    just initialize a variable inv with zero 
    and each time you find an element in the left subarray 
    greater than the element of the right subarray 
    count the total length of the left subarray 
    because the element in the right subarra inverses all elements 
    in the right subarray 
    

*/


// problem link : https://www.spoj.com/problems/INVCNT/
int a[N];
ll inv = 0;
void merge (int begin1, int end1, int begin2, int end2){ 
    int ind = 0, beginHolder = begin1;

    
    vector<int> temp(end2 - begin1 + 5);
    while (begin1 <= end1 && begin2 <= end2) {
        if (a[begin1] > a[begin2]) {
            inv += end1 - begin1 + 1;
            temp[ind ++] = a[begin2 ++];
        } else {
            temp[ind ++] = a[begin1 ++ ];
        }
    }
    while (begin1 <= end1) {temp[ind++] = a[begin1++];}
    while (begin2 <= end2) {temp[ind++] = a[begin2++];}

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
    int t;
    cin >> t;
    while(t--)
    {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ){
        cin >> a[i];
    }

    mergeSort(0, n - 1);
    cout << inv << endl;
    inv = 0;}

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
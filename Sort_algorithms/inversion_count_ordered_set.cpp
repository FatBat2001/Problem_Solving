#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

using namespace std;
using ll = long long;

void read_write();

/*
    !!Ordered set library is in the mingw compiler so it won't open in visual studio code 

    The solution using ordered set is actually very easy if we went to definition of 
    inversion, (elements less than the current element and they come later in the array)
    we can  implement somthing like that using ordered set 
    it can answer how many elements are less some other element in log(n) time 
    so we remove the element and ask where should it be , the answer to that question is 
    the number of elements that come later in the array and inverse the current one 

    we keep deleting every time we ask of an element 


*/


ll inversion = 0;

int main () {
    read_write();
    ordered_set s;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++ ) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    for (int i = 0; i < n; i ++ ){
        s.erase(arr[i]);
        cout << arr[i] << ' ' << s.order_of_key(arr[i])  << "\n";
        inversion += s.order_of_key(arr[i]);

    }
    cout << inversion << '\n';
    
    

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
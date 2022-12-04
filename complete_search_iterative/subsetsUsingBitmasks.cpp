#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool preceed (vector<int> v1, vector<int> v2)
{
    return v1.size() > v2.size();
}
int main () {
    
    int n = 3;
    int arr[n] = {2, 3, 4};
    vector<vector<int>> vv;    
    for (int mask = 0; mask < 1 << n; mask ++ )
    {   // when the mask is zero it will not perform this loop and only going to print endl
        vector<int> v;
        for (int i = 0; i < n; i ++) {
            if (( 1 << i & mask ) != 0) {
                cout << arr[i]  << " ";
                v.push_back(arr[i]);
            }
        }
        
        vv.push_back(v);
        cout << '\n';
    }


    // to print them in a good order 
    sort(vv.begin(), vv.end(), preceed);
    for (int i = vv.size() - 1; i >= 0; i -- ) {
        for (int j = 0; j < vv[i].size(); j ++ ) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    

} 
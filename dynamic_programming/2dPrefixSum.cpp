#include<bits/stdc++.h> 
using namespace std;

const int M =  1003;
using ll = long long ;
ll pref[M][M];

ll calc(ll k, ll l, ll i, ll j) {
    return pref[k][l] - pref[i - 1][l] - pref[k][j - 1] + pref[i][j];
}

int main(){
    int n, q, t;
    cin >> t;
    while (t --) {
        cin >> n >> q;
        memset(pref, 0, sizeof pref);
        for (int i = 0; i < n; i ++){
            int w, h;
            cin >> h >> w;
            pref[h][w] += 1LL * h * w;
        }
        for (int i = 1; i < M; i ++) {
            for (int j = 1; j < M; j ++) {
                pref[i][j] += pref[i][j - 1];
            }
        }
        for (int j = 1; j < M; j ++){
            for (int i = 1; i < M; i ++) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        while (q--) {
            ll hs,ws, hb,wb;
            cin >> hs >> ws >> hb >> wb;
            cout << calc(hb, wb, hs, ws) << endl;
        }
    }
}
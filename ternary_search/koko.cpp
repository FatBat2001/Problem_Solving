#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();

/*

    koko wants to meet with all his friends his friends live in the 2d
    plane world unfortunately his parents prevented him from going to any plce with any point where its y-coordinate = 0.
    so koko will go to a point on the x-axis where the maximum distance between all his friends is minimm as possible 
    given N number of koko's friends and the coordinates of each of his 
    friends home, find the x coordinate where koko will be most near to all his friends 
    -200000 --> 200000


*/



// i don't agree with this solution 
// becuase takign the maximum distance between to points doesn't mean that this point 
// is the optimal to all friends 


/*
    if you don't your friends كل علي حده to walk big distance 
    then the solution is fine 

    if you want to minimize total distance between all of them 
    you need to get the total distances 

    double calc(double x) {
    double tot = 0;
    for (auto it : coordinates) {
        tot +=  sqrt(pow((x - it.first), 2) +  pow(it.second, 2));
    }    
    return tot;
}

*/



vector<pair<int, int>> coordinates;

double calc(double x) {
    double mx = 0;
    for (auto it : coordinates) {
        mx = max(mx, sqrt(pow((x - it.first), 2) +  pow(it.second, 2)));
    }    
    return mx;
}

int main () {
    read_write();
    int n;
    cin >> n;
    coordinates = vector<pair<int, int>> (n);

    for (int i = 0; i < n; i ++ ){
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    
    double start = -200000, end = 200000, m1, m2;
    double eps = 0.0000001;
    while (start + eps <= end) {
        m1 = start + (end - start) / 3.0;
        m2 = end - (end -start) / 3.0;
        double ans1 = calc(m1);
        double ans2 = calc(m2);
        if (ans1 > ans2) {
            start = m1;
        } else {
            end = m2;
        }
    }
    cout << start << endl;

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
#include<bits/stdc++.h>
using namespace std;
void fastIO () {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}
using ll = long long;
int main () {
    fastIO();
    // you are givin n and k and you have to reorder the digits of n to find
    // the smallest number which can be divisble by k if not output -1 
    int n, k;
    cin >> n >> k;
    string str = to_string(n);
    do {
        int x = stoi(str);
        if (x % k == 0 ) {
            cout << x << endl;
            return 0;
        }
    } while (next_permutation(str.begin(), str.end()));
    cout << "not found" << '\n';
    system("pause");

}

#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
void fastIO () {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}
int main() {
	freopen("input.in", "r", stdin);
	fastIO();
    // in this problem you are givin a number and you have to find the next lucky number after the givin one or equal to it 
    // n <= x   

	vector<int> v;
	int n, g1, g2;
	cin >> n;
	g1 = floor(log10(n)) + 1;
	g2 = g1 + 1;
	for (int mask = 0; mask < (1 << g1); mask ++ ) {
		int num = 0;
		for (int i = 0; i < g1; i ++ ) {
			if (1 << i & mask ) {
				num = num * 10 + 7;
			} else {
				num = num * 10 + 4;
			}
		}
		v.push_back(num);
	}
	for (int mask = 0; mask < (1 << g2); mask ++ ) {
			int num = 0;
			for (int i = 0; i < g2; i ++ ) {
				if (1 << i & mask ) {
					num = num * 10 + 7;
				} else {
					num = num * 10 + 4;
				}
			}
			v.push_back(num);
		}
		cout << *lower_bound(v.begin(), v.end(), n) << endl;
}

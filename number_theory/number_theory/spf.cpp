#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 1000005

/*

    prime factorization in log(n) time 
    after preprocessing the sieve function 
    
*/

int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }

}

map<int, int> get_fac(int x)
{
    map<int, int> ret;
    while (x != 1) {
        ret[spf[x]] ++;
        x = x / spf[x];
    }
    return ret;
}



int main() {
    sieve();
    map<int, int> mp = get_fac(24);
    for (auto it : mp) {
        cout << it.first << ' ' << it.second << '\n';
    }

}

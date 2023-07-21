#include<iostream>
#include<vector>
#define ll long long 
#define Ban8aly ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e6+3;


void seive () {
    int sieveArray[N];
    for (int i = 2; i * i <= N; i++) {
        if (sieveArray[i]) continue;
        for (int j = i * i; j <= N;j += i )
            sieveArray[j] = i;
    }
}

bool isPrime (int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i ++ ) {
        if (n % i == 0)
            return false;
    }
    return true;
}
vector<int> primeFactorization (int n) {
    vector<int> p;
    for (int i = 2; i * i <= n; i ++ ){
        while (n % i == 0) {
            p.push_back(i);
            n /= i;
        }
    }
    if (n > 1) p.push_back(n);
    return p;
}
void findingTheKTHprime() {
    bool is_prime[90000001];
    ll maxN = 90000001;
    vector<int> p;
    is_prime[0] = is_prime[1] = true;
    for (int i = 2; i * i <= maxN; i ++ ) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= maxN; j += i)
                is_prime[j] = true;
        }
    }
    for (int i = 2; i <= maxN; i ++ )
        if (!is_prime[i])
            p.push_back(i);
}
vector<int> sievePrimeFactorizatioin () {
    vector<int> p(N, -1);
    p[0] = 0, p[1] = 1;
    for (int i = 2; i < N; i++) {
        if (p[i] == -1){
            for (int j = i; j <= N; j+= i)
                if (p[j] == -1)
                p[j] = i;
        }
    }
    return p;
}
vector<int> getDivisors(ll n) {
    vector<int> p;
    for (int i = 1; i * i <= n; i ++ ) {
        if (n % i == 0) {
            p.push_back(i);
            if (n  / i != i) p.push_back(n / i);
        }
    }
    return p;
}

int main() {
   
    vector<int> v = sievePrimeFactorizatioin();
    for (int i = 0; i <= 50; i ++) {
        if (i % 10 == 0 && i > 1)
            cout << v[i] << endl;
        else cout << v[i] << " "; 
    }
}
#include<iostream>
using namespace std;
#define read(FILE) freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
using ll = long long;
int a[15], n;
char s[15];

ll fac (int n) {
    return n == 0 ? 1 : n * fac(n - 1);
}

void gen(int index, int sum ) {
    
    if (index == n ) {
        cout << sum << '\n';
        return;
    }

    gen(index + 1, sum );
    gen(index + 1, sum + a[index]);
}

void genChars(int i) {
    if (i == n) {
        cout << s << '\n';
        return;
    }
    s[i] = 'a';
    genChars(i + 1);
    s[i] = 'b';
    genChars(i + 1);
    s[i] = 'c';
    genChars(i + 1);
}

int main () {
    read("C:\\Users\\adham\\Dropbox\\PC\\Documents\\PST\\input.txt");
    write("C:\\Users\\adham\\Dropbox\\PC\\Documents\\PST\\output.txt");
    cin >> n;
     genChars(0);
    // generating chars using bitmasks 
    int tt;
    




}
namespace RollingHash {
    ll mult(ll a, ll b, ll mm) { return (1LL * a * b) % mm; }

    int fastPower(int base, int power, int mod) {
        int res = 1;
        while (power) {
            if (power & 1)
                res = mult(base, res, mod);
            power /= 2, base = mult(base, base, mod);
        }
        return res;
    }

    int modInv(int a, int m) {
        return fastPower(a, m - 2, m);
    }

    ll xpow1[N], xpow2[N];

    int x = 128, p1 = 1e9 + 7, p2 = 1e9 + 9;

    ll fixMod(ll a, ll m) {
        return (a + m) % m;
    }

    ll push_back(ll h, ll x, ll p, char ch) {
        return (((h * x) % p) + ch) % p;
    }

    ll push_front(ll h, ll xp, ll p, char ch) { // xp=XP[len]
        return (h + (xp * ch) % p) % p;
    }

    ll pop_back(ll h, ll x, ll p, char ch) {
        return (fixMod(h - ch, p) * modInv(x, p)) % p;
    }

    ll pop_front(ll h, ll xp, ll p, char ch) { // xp=XP[len-1]
        return fixMod(h - ((xp * ch) % p), p);
    }

    void pre() {
        xpow1[0] = 1;
        xpow2[0] = 1;
        for (int i = 1; i < N; i++) {
            xpow1[i] = (xpow1[i - 1] * x) % p1;
            xpow2[i] = (xpow2[i - 1] * x) % p2;
        }

    }
    class Hash {
    private:
        pair<ll, ll> hash;
        int sz;
    public:
        Hash() {
            sz = 0;
        }
        void push_back(char c) {
            hash.first = RollingHash::push_back(hash.first, x, p1, c);
            hash.second = RollingHash::push_back(hash.second, x, p2, c);
            sz ++;
        }
        void pop_back(char c) {
            hash.first = RollingHash::pop_back(hash.first, x, p1, c);
            hash.second = RollingHash::pop_back(hash.second, x, p2, c);
            sz--;
        }
        void push_front(char c) {
            hash.first = RollingHash::push_front(hash.first, xpow1[sz], p1, c);
            hash.second = RollingHash::push_front(hash.second, xpow2[sz], p2, c);
            sz ++;
        }
        void pop_front(char c) {
            hash.first = RollingHash::pop_front(hash.first, xpow1[sz-1], p1, c);
            hash.second = RollingHash::push_front(hash.second, xpow2[sz-1], p2, c);
            sz --;
        }
        ll get_hash() const{
            return hash.first * p1 + p2;
        }
        ll get_size() const{
            return sz;
        }
    };

}
using namespace RollingHash;
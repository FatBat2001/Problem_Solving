namespace RollingHash {
    int b1 = 31, b2 = 69, mod = 1e9 + 7, b1I = 129032259, b2I = 579710149;
    vector<int> Pb1, Pb2, inv1, inv2;
    using pi = pair<int, int>;

    void pre(unsigned maxSize) {
        inv1 = inv2 = Pb1 = Pb2 = vector<int>(maxSize + 1, 1);
        Pb1[1] = b1, Pb2[1] = b2, inv1[1] = b1I, inv2[1] = b2I;
        for (int i = 2; i <= maxSize; i++) {
            Pb1[i] = int(1LL * Pb1[i - 1] * b1 % mod);
            Pb2[i] = int(1LL * Pb2[i - 1] * b2 % mod);
            inv1[i] = int(1LL * inv1[i - 1] * b1I % mod);
            inv2[i] = int(1LL * inv2[i - 1] * b2I % mod);
        }
    }
    class Hash {
    public:
        pi code;
        int size;
        explicit Hash(pi x = {}, int sz = {}) : code(std::move(x)), size(sz) { }

        template<class T>
        Hash(const T s) : size(0) {
            for(const auto x : s) push_front(x);
        }

        void push_back(int x) {
            code.first = int((code.first + 1LL * Pb1[size] * x) % mod);
            code.second = int((code.second + 1LL * Pb2[size++] * x) % mod);
        }
        void push_front(int x) {
            code.first = int((1LL * code.first * b1 + x) % mod);
            code.second = int((1LL * code.second * b2 + x) % mod);
            size++;
        }
        void pop_back(int x) {
            code.first = int((code.first - 1LL * Pb1[--size] * x % mod + mod) % mod);
            code.second = int((code.second - 1LL * Pb2[size] * x % mod + mod) % mod);
        }
        void pop_front(int x) {
            code.first = int((1LL * (code.first - x + mod) * b1I) % mod);
            code.second = int((1LL * (code.second - x + mod) * b2I) % mod);
            size--;
        }
        void clear() {
            code = {}, size = 0;
        }

        Hash operator+(const Hash &o) const {//based on push_front (... 2 1 0) + (... 2 1 0) => "hell" + "o" = "hello"
            return Hash({int((1LL * code.first * Pb1[o.size] + o.code.first) % mod),
                         int((1LL * code.second * Pb2[o.size] + o.code.second) % mod)}
                    , size + o.size);
        }
        Hash operator-(const Hash &o) const {//based on push_front (... 3 2 1 0) - (... 2 1 0) => "hello" - "hell" = "o"
            assert(size >= o.size);
            int m = size - o.size;
            return Hash({int((code.first - 1LL * o.code.first * Pb1[m] % mod + mod) % mod),
                         int((code.second - 1LL * o.code.second * Pb2[m] % mod + mod) % mod)}
                    , m);
        }
        bool operator<(const Hash &o) const {
            if (size == o.size) return code < o.code;
            return size < o.size;
        }
        bool operator==(const Hash &o) const {
            return size == o.size && code == o.code;
        }
        bool operator!=(const Hash &o) const {
            return size != o.size || code != o.code;
        }
    };

    class HashRange {
    public:
        vector<Hash> pre, invPre;

        template<class T>
        HashRange(const T &s) {
            pre.reserve(s.size());
            invPre.reserve(s.size());
            Hash c, c1;
            for(auto &i : s) {
                c.push_front(i);
                c1.push_back(i);
                pre.push_back(c);
                invPre.push_back(c1);
            }
        }
        Hash get(int l, int r) {
            return l == 0? pre[r]: pre[r] - pre[l - 1];
        }
        Hash getInv(int l, int r) {
            return l == 0? invPre[r]: Hash({
                   (invPre[r].code.first - invPre[l - 1].code.first + mod) % mod * 1LL * inv1[invPre[l - 1].size] % mod,
                   (invPre[r].code.second - invPre[l - 1].code.second + mod) % mod * 1LL * inv2[invPre[l - 1].size] % mod
           }, r - l + 1);
        }
    };

    template<typename T>
    Hash getHash(T &s) {
        Hash c;
        for(auto &i : s)
            c.push_front(i);
        return c;
    }
    template<typename T>
    Hash getInvHash(T &s) {
        Hash c;
        for(auto &i : s)
            c.push_back(i);
        return c;
    }
}
//using namespace RollingHash;

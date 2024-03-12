
namespace RollingHash {
    int b1 = 31, b2 = 69, mod = 1e9 + 7, b1I = 129032259, b2I = 579710149;
    vector<int> Pb1, Pb2;
    using pi = pair<int, int>;

    void pre(unsigned maxSize) {
        Pb1 = Pb2 = vector<int>(maxSize + 1, 1);
        for (int i = 1; i <= maxSize; i++) {
            Pb1[i] = int(1LL * Pb1[i - 1] * b1 % mod);
            Pb2[i] = int(1LL * Pb2[i - 1] * b2 % mod);
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
    template<typename T>
    Hash getHash(T &s) {
        Hash c;
        for(auto &i : s)
            c.push_front(i);
        return c;
    }
    template<typename T>
    vector<Hash> getPreHash(T &s) {
        vector<Hash> arr;
        arr.reserve(s.size());
        Hash c;
        for(auto &i : s) {
            c.push_front(i);
            arr.push_back(c);
        }
        return arr;
    }
    Hash getRange(vector<Hash> &pre, int l, int r) {
        return l == 0? pre[r]: pre[r] - pre[l - 1];
    }
}
//using namespace RollingHash;

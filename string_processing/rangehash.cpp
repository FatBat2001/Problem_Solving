int P=31;
ll p[N], invp[N];
ll add(ll a, ll b) {
    return (((a + b) % MOD) + MOD) % MOD;
}
ll mul(ll a, ll b) {
    return (a * b) % MOD;
}
ll fp(ll base, ll pow) {
    if (pow == 0) return 1;
    ll x = fp(base, pow / 2);
    x = mul(x, x);
    if (pow & 1) x = mul(x, base);
    return x;
}
void pre() {
    p[0] = 1;
    invp[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], P);
        invp[i] = fp(p[i], MOD - 2);
    }
}

vector<ll> compute_hash(string x) {
    vector<ll> ret(x.size());
    ll curr = 0;
    for (int i = 0; i < x.size(); i++) {
        int a = x[i] - 'a' + 1;
        curr = add(curr, mul(a, p[i]));
        ret[i] = curr;
    }
    return ret;
}

ll get_hash(vector<ll> &v, int l, int r) {
    ll ret = v[r];
    if (l - 1 >= 0) {
        ret = add(ret, -v[l - 1]);
        ret = mul(ret, invp[l]);
    }
    return ret;
}
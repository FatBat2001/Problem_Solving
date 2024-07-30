// cses : subtree queries 
int tin[N], tout[N];
vector<int> adj[N];
int timer = 1; // on based tour
void euler_tour (int u, int p) {
    tin[u] = timer++;
    for (auto v : adj[u]) {
        if (v != p) {
            euler_tour(v, u);
        }
    }
    tout[u] = timer - 1;
}
struct segmentTree {
    vector<int> st;
    int n;
    void init(int _n) {
        this->n = _n;
        this->st.resize(4 * n, 0);
    }
    void build(int start, int ending, int node, vector<int> &v) {
        if (start == ending) {
            st[node] = v[start];
            return;
        }
        int left = 2 * node + 1, right = 2 * node + 2, mid = (start + ending) / 2;
        build(start, mid, left, v);
        build(mid + 1, ending , right, v);
        st[node] = st[left] + st[right];
    }
    int query(int start, int ending, int l, int r, int node) {
        if (start > r || ending < l) {
           return 0;
        }
        if (start >= l && ending <= r) {
            return st[node];
        }
        int left = 2 * node + 1, right = 2 * node + 2, mid = (start + ending) / 2;
        int leftQuery = query(start, mid, l, r, left);
        int rightQuery = query(mid + 1, ending, l, r, right);
        return rightQuery + leftQuery;
    }
    void update(int start, int ending, int node, int index, int value) {
        if (start == ending) {
            st[node] = value;
            return;
        }
        int mid = (start + ending) / 2;
        if (index <= mid) {
            update(start, mid, 2 * node + 1, index, value);
        } else {
            update(mid + 1, ending, 2 * node + 2, index, value);
        }
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    void build(vector<int> & v) {
        build(0, (int)v.size() - 1, 0 , v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }
    void update(int index, int value) {
        update(0, n - 1, 0, index, value);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    segmentTree tree;
    tree.init(n + 1);
    euler_tour(1, -1);
    for (int i = 1; i <= n; i ++) {
        tree.update(tin[i], a[i]);
    }
    while (q -- ) {
        int type;
        cin >> type;
        if (type == 1) {
            int node, val;
            cin >> node >> val;
            tree.update(tin[node], val);
        } else {
            int node;
            cin >> node;
            cout << tree.query(tin[node], tout[node]) << endl;
        }
    }
}
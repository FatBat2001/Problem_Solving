#include <bits/stdc++.h>
#define read(FILE) freopen(FILE,"r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);




using namespace std;
void read_write();
struct segmentTree {
    vector<int> st;
    int n;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
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


    void build(int start, int ending, int node, vector<int> &v) {
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int left = 2 * node + 1, right = 2 * node + 2, mid = (start + ending) / 2;

        // go left
        build(start, mid, left, v);

        // go right
        build(mid + 1, ending , right, v);

        st[node] = st[left] + st[right];

    }

    int query(int start, int ending, int l, int r, int node) {
        // handling  not overlaping
        if (start > r || ending < l) {

            // value is neural to this sum tree
            return 0;
        }

        // handling complete overlaping
        if (start >= l && ending <= r) {
            return st[node];
        }


        // partial case
        int left = 2 * node + 1, right = 2 * node + 2, mid = (start + ending) / 2;

        // going left
        int leftQuery = query(start, mid, l, r, left);

        // going right
        int rightQuery = query(mid + 1, ending, l, r, right);

        return rightQuery + leftQuery;
    }


    void update(int start, int ending, int node, int index, int value) {
        // reached the leaf node 
        if (start == ending) {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        
        // going left 
        if (index <= mid) {
            update(start, mid, 2 * node + 1, index, value);
        } else { // going right 
            update(mid + 1, ending, 2 * node + 2, index, value);
        }


        st[node] = st[node * 2 + 1] + st[node * 2 + 2]; 
    }
};

int32_t main (){
    read_write();
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    segmentTree tree;

    tree.init((int)v.size());
    tree.build(v);


    cout << tree.query(0, 4) << '\n';
    tree.update(4, 10);
    cout << tree.query(2, 6) << '\n';
    tree.update(2, 20);
    cout << tree.query(0, 4) << '\n';

}



void read_write() {
ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE        
    read("C:\\Users\\adham\\Documents\\PST\\input.txt")
    write("C:\\Users\\adham\\Documents\\PST\\output.txt")
#   endif    
}
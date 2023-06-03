#include<bits/stdc++.h>
#define ana_me4_metzabat_nafsyn ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e6 + 5, M = 1003, MOD = 1e9 + 7, oo = 1e8;

struct node {
    int val;
    node *next;
    node() {
        val = 0;
        next = nullptr;
    }
    node(int val, node* nxt) {
        this->val = val;
        this->next = nxt;
    }

};

void push_back(node** head, int value) {
    if (!(*head)) {
        *head = new node(value, nullptr);
    } else {
        node* curr = *head;
        node* new_node = new node(value, nullptr);
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}
int pop_back(node** head){
    if (!(*head)) {
        exit(123);
    } else {
        node* curr = *head;
        node* erase = curr;
        while (curr->next) {
            erase = curr;
            curr = curr->next;
        }
        if (curr == erase) {
            int ret = curr->val;
            *head = nullptr;
            return ret;
        } else {
            erase->next = nullptr;
            int ret = curr->val;
            free(curr);
            return ret;
        }
    }
}

void reverse(node** head) {
    node* curr = *head;
    node*last = nullptr;
    node* next = curr->next;
    while (next) {
        curr->next = last;
        last = curr;
        curr = next;
        next = curr->next;
    }
    *head = curr;
    curr->next = last;
}

void print_list(node** head) {
    node* curr = *head;
    while (curr) {
        cout << curr->val << ' ';
        curr = curr->next;
    }
    cout << endl;
}



void solve(){
    node* head = nullptr;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);

    print_list(&head);
    reverse(&head);
    print_list(&head);
    reverse(&head);
    print_list(&head);
}

int32_t main() {
    ana_me4_metzabat_nafsyn
    int tt = 1;
//    cin >> tt;
    while (tt -- )
        solve();
}
#include <bits/stdc++.h>
#define read(FILE) freopen(FILE,"r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);




using namespace std;
void read_write();


struct trieNode{
    trieNode *nxt[26];
    int cnt;
    trieNode() {
        for (int i = 0; i < 26; i ++) {
            nxt[i] = nullptr;
        }
        cnt = 0;
    }
} *root = new trieNode();
 
 
void add_string(string &str) {
    trieNode *curr = root;
 
    for (auto c : str) {
        int idx = c - 'a';
        if (curr->nxt[idx] == nullptr) {
            curr->nxt[idx] = new trieNode();
        }
        curr = curr->nxt[idx];
    }
    curr->cnt = curr->cnt + 1;
}
 
int search(string &str) {
    trieNode *curr = root;
    for (auto c : str) {
        int idx = c - 'a';
        if (curr->nxt[idx] == nullptr) return false;
        curr = curr->nxt[idx];
    }
    return curr->cnt;
}



int32_t main (){
    read_write();
    string adham = "adham";
    add_string(adham);
    if (search(adham)){
        cout << "found\n";
    } else {
        cout << "not found\n";
    }
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
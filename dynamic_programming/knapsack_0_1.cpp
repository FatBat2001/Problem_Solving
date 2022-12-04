#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();




/*
    knapsack 0-1 problem 

*/


/*
    You have N bags each bag has certain weight and price  
    And your knapsack has a limited capacity 
    try to maximize the amount of money you can take 
    considering you can only carry as much as your bag can hold 

*/



/*
    naive solution 
    brute force creating all subsets of the bags 
    then choosing the maximum price 

*/
vector<ll> weight, price;
long long  mem[100][100005];
ll mx = -1;



// brute force by creating all subsets of bags 
// taking maximum subset with positive remaining weight
// total complexity O(2 ^ N) 
void knapsack_BF(ll index, ll remaining_weight,ll curr_sum = 0) {
    if (index == -1){
        if (remaining_weight >= 0) mx = max(mx, curr_sum);
        return;
    }
    knapsack_BF(index - 1, remaining_weight, curr_sum);
    knapsack_BF(index - 1, remaining_weight - weight[index], curr_sum + price[index]);
    curr_sum -= price[index];
    remaining_weight += weight[index];
}


// same solution but applying memoization 
// total complexity O (N * M)
ll knapsack(ll index, ll remaining_weight) {
    if (index == -1 ) return 0;
    if (mem[index][remaining_weight] != -1) return mem[index][remaining_weight];
    ll leave = knapsack(index - 1, remaining_weight);
    
    // initializing the take subpath with -1 
    // because it may occur an instance with remaining weight 
    // less than current element so we are forced to leave it 
    ll take = -1;
    if (weight[index] <= remaining_weight) 
        take = price[index] + knapsack(index - 1, remaining_weight - weight[index]);

    // I'm an idiot 
    // always remember to store the answers of the paths 
    return mem[index][remaining_weight] =  max(leave, take);
}

int main () {
    read_write();
    ll tt = 1;
    //cin >> tt;
    while (tt -- ) {
        ll k, n;
        cin >> n >> k;
        weight.resize(n);
        price.resize(n);
        memset(mem, -1, sizeof mem);
        
        for (ll i = 0; i < n;  ++i ) {
            cin >> weight[i] >> price[i];
        }
        
        cout << knapsack(n - 1, k);
    }
}



void read_write() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
#ifndef ONLINE_JUDGE        
    freopen("C:\\Users\\adham\\Documents\\PST\\input.txt", "r", stdin);
    freopen("C:\\Users\\adham\\Documents\\PST\\output.txt", "w", stdout);
    
#   endif    
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void read_write();
/**
    https://www.spoj.com/problems/TOE2/
    searching with bfs like two buttons problem 

    The approach here is to precalculate all the states of valid 
    X-O configurations that may happen 
    total number of states is probably 9!
    which is applicable to precalculation

**/

void fill_grid(char grid[][3], string & str);


bool someone_already_won_or_the_grid_completed(string &str){
    char grid[3][3];
    fill_grid(grid, str);


    bool flag = true;
    // here checking for the grid to be completed 
    for (int i = 0; i < (int) str.size(); i ++ ){
        if (str[i] == '.') flag = false;
    }
    if (flag) return true;

    // checking horizontal win
    if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][0] != '.')
        return true;
    if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]  && grid[1][0] != '.')
        return true;
    if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][0] != '.')
        return true;

    // checking vertical win 
    if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[0][0] != '.')
        return true;
    if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[0][1] != '.')
        return true;
    if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[0][2] != '.')
        return true;

    // checking the diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] != '.')
        return true;

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != '.')
        return true;

    return false;
}

// converts the string represntation of the current game state
// to a grid so I can work on it 
void fill_grid(char grid[][3], string & str) {
    string s;
    for (int i = 0; i < 3; i ++ ){
        s = str.substr(3 * i, 3);
        for (int j = 0; j < 3; j ++ ){
            grid[i][j] = s[j];
        }
    }
}


// This function returns a (set) of all possible board configurations using breadtf-first-search 
// set implementation in c++ i think is a red-black-tree
// so searching for a state is done in long(n) time which is quite good 

set<string> calculate_states(){ 
    set<string> valid_states;
    char turn[] = {'X', 'O'};
    string state = ".........";
    queue<pair<int, string>> states;
    
    states.push({0, state});
    valid_states.insert(state);
    while (!states.empty())  {
        auto current_state = states.front();
        states.pop();

        // if someone in some state already one the game 
        // it's not rational to keep adding x and o to the 
        // current configuration 
        if (someone_already_won_or_the_grid_completed(current_state.second)) {
            continue;
        }
            
        
        for (int i = 0; i < 9; i ++ ){
            pair<int, string> next_state = current_state;
            if (current_state.second[i] == '.') {
                next_state.second[i] = turn[next_state.first];
                if (!valid_states.count(next_state.second)) {
                    states.push(make_pair(1 - current_state.first, next_state.second));
                    valid_states.insert(next_state.second);
                }
            }
        }
    }

    return valid_states;
}



int main () {
    read_write();
    set<string> all_states = calculate_states();    
    string str;
    while (cin >> str, str != "end") {
        if (all_states.count(str) && someone_already_won_or_the_grid_completed(str)) {
            cout << "valid\n";
        } else {
            cout <<"invalid\n";
        }
    }
    for (auto it :all_states)
        cout << it << '\n';
    

    
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

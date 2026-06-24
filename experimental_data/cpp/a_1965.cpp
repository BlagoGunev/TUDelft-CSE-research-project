#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <fstream>
#include <iomanip>
#include <stack>
#include <cmath>
#include <queue>
#include <assert.h>
#include <climits>
#include <functional>
#include <string>
#include <utility>
#include <unordered_set>
#include <numeric>

using namespace std;



typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int MOD = 1e9+7;

int N;

void process(){
    cin >> N;
    set<int> st;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<int> moves;
    for(int i : st) moves.push_back(i);
    N = moves.size();
    for(int i = N-1; i >=1; i--){
        moves[i] -= moves[i-1];
    }
    bool win = true;
    for(int i = N-2; i >= 0; i--){
        if(win){
            if(moves[i] == 1){
                win = false;
            }
        }
        else{
            win = true;
        }
    }
    cout << (win ? "Alice" : "Bob") << endl;
}


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) process();
}
// Problem: D. QED's Favorite Permutation
// Contest: Codeforces - Codeforces Round 979 (Div. 2)
// Created: 2024-10-19 10:14:02
// 
// Powered by CP Editor

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
	    int n, q;
	    cin >> n >> q;
	    vector<int> good(n+1);
	    int mx = 0;
	    for(int i=1; i<=n; i++){
	        int a;
	        cin >> a;
	        mx = max(mx, a);
	        if(mx == i) good[i] = 1; // OK to have LR starting at i
	    }
	    string s;
	    cin >> s;
	    s = " " + s + " ";
	    set<int> bad;
	    auto f = [&](int i){
	        if(s[i] == 'L' && s[i+1] == 'R'){
	            if(!good[i]){
	                bad.insert(i);
	            }
	        }
	        else{
                bad.erase(i);
            }
	    };
	    for(int i=1; i<n; i++){
	        f(i);
	    }
	    while(q--){
	        int i;
	        cin >> i;
	        if(s[i] == 'L') s[i] = 'R';
	        else s[i] = 'L';
	        f(i-1);
	        f(i);
	        cout << (bad.empty() ? "YES" : "NO") << endl;
	    }
	}
}
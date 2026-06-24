// Problem: B. Swap and Reverse
// Contest: Codeforces - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1864/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")

using namespace std;
using namespace __gnu_pbds;

#define lg long long
#define ordered_set	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	fastio;
	lg tc;
    cin >> tc;
    while(tc--)
    {
    	lg n, k;
    	cin >> n >> k;
    	string s;
    	cin >> s;
    	multiset<lg> se[2];
    	for(int i = 0; i < n; i++)
    	{
    		se[i%2].insert(s[i]);
    	}
    	if(k%2 == 0)
    	{
    		sort(s.begin(), s.end());
    		cout << s << '\n';
    	}
    	else{
    		string t[2];
    		for(int i = 0; i < 2; i++)
    		{
    			t[i] = "";
    			for(auto it : se[i])
    			{
    				t[i] += it;
    			}
    		}
    		for(int i = 0; i < n; i++)
    		{
    			cout << t[i%2][i/2];
    		}
    		cout << '\n';
    	}
    }

    return 0;
}
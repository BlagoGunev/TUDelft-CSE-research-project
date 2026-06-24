// Problem: A. Not a Substring
// Contest: Codeforces - Educational Codeforces Round 153 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1860/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms

//  __  __   _  _____ _   _   _____   ______          __
//  \ \/ /  / \|_   _| | | | |  __ \ / __ \ \   /\   / /
//   \  /  / _ \ | | | | | | | |  | | |  | \ \ /  \ / /
//   /  \ / ___ \| | | |_| | | |__| | |__| |\ V /\ V /
//  /_/\_/_/   \_\_|  \___/  |_____/ \___\_\ \_/  \_/ (TM)

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define mii map<int, int>
#define mci map<char, int>
#define msi map<string, int>
#define qi queue<int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define inf 1000000000000000018LL
#define db(a) cout << (#a) << ':' << a << endl
#define ddb(a, b) cout << (#a) << ':' << a << ' ' << (#b) << ':' << b << endl
#define tdb(a, b, c) cout << (#a) << ':' << a << ' ' << (#b) << ':' << b << ' ' << (#c) << ':' << c << endl
#define vidb(a)                           \
    cout << (#a) << ':';                  \
    for (int ii = 0; ii < a.size(); ii++) \
        cout << ' ' << a[ii];             \
    cout << endl
#define yn(x) cout << (x ? "YES\n" : "NO\n")
#define yes cout << "YES\n"
#define no cout << "NO\n"
using namespace std;
void solve()
{
	string s;cin>>s;
	if(s=="()")
	{
		no;
	}
	else
	{
		int n=s.size();
		string a,b;
		while(n--)
		{
			a+="()";
			b="("+b+")";
		}
		if(a.find(s)==-1)
		{
			yes;
			cout<<a<<endl;
		}
		else if(b.find(s)==-1)
		{
			yes;
			cout<<b<<endl;
		}
		else
		{
			no;
		}
	}
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

// Not all efforts result in success, but giving up is sure to result in failure.
// Powered by Vim 9.1 on Linux
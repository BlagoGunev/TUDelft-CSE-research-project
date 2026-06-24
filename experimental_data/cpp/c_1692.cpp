#include<bits/stdc++.h>

using namespace std;

using ll = long long;



#define int			long long

#define ff			first

#define ss			second

#define pob			pop_back

#define pof			pop_front

#define pb			push_back

#define pf			push_front

#define lb			lower_bound

#define ub			upper_bound

#define pii			pair<int,int>

#define sz(x)			(int)(x.size())

#define all(x)			x.begin(),x.end()

#define PI			3.1415926535897932384626

#define precise(i)		cout<<fixed<<setprecision(i)

#define uniq(v)           	(v).erase(unique(all(v)),(v).end())



#ifndef ONLINE_JUDGE

#include "debug.h"

#else

#define deb(x...)

#endif



const int mod = 1e9 + 7;



void solve() {

	vector<vector<char>> v(15, vector<char>(15, '$'));

	for (int i = 1; i <= 8; i++) {

		for (int j = 1; j <= 8; j++) {

			cin >> v[i][j];

		}

	}

	for (int i = 1; i <= 8; i++) {

		for (int j = 1; j <= 8; j++) {

			if (v[i + 1][j + 1] == '#' and v[i - 1][j - 1] == '#' and v[i - 1][j + 1] == '#' and v[i + 1][j - 1] == '#') {

				cout << i << " " << j << "\n";

				return;

			}

		}

	}



}



signed main() {



	ios_base::sync_with_stdio(false);

	cin.tie(NULL); cout.tie(NULL);



	//freopen("input.txt","r",stdin);

	//freopen("output.txt","w",stdout);



	int TESTS = 1;

	cin >> TESTS;

	for (int T = 1; T <= TESTS; T++) {

		solve();

	}



	return 0;

}
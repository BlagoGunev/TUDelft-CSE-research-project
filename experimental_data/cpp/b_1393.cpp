#include <climits>

#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp>

#include <functional>

#include <bits/stdc++.h>

using namespace __gnu_pbds;

using namespace std;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,

             tree_order_statistics_node_update>

    ordered_multiset;

typedef tree<int, null_type, less<int>, rb_tree_tag,

             tree_order_statistics_node_update>

    ordered_set; 

#define ll long long

void solve(){

	ll n;

	cin >> n;

	vector<ll> a(n);

	map<ll,ll> mp, mp_mp;

	for (auto &i : a){

		cin >> i;

		++mp[i];

	}

	for (auto i : mp){

		if (i.second >= 8) ++mp_mp[8];

		else if (i.second >= 6) ++mp_mp[6];

		else if (i.second >= 4) ++mp_mp[4];

		else if (i.second >= 2) ++mp_mp[2];

	}

	ll q;

	cin >> q;

	while (q--){

		char x;

		ll val;

		cin >> x >> val;

		if (x == '+'){

			++mp[val];

			if (mp[val] == 2) ++mp_mp[2];

			if (mp[val] == 4){

				--mp_mp[2];

				++mp_mp[4];

			}

			if (mp[val] == 6){

				--mp_mp[4];

				++mp_mp[6];

			}

			if (mp[val] == 8){

				--mp_mp[6];

				++mp_mp[8];

			}

		}

		else{

			--mp[val];

			if (mp[val] == 7){

				--mp_mp[8];

				++mp_mp[6];

			}

			if (mp[val] == 5){

				--mp_mp[6];

				++mp_mp[4];

			}

			if (mp[val] == 3){

				--mp_mp[4];

				++mp_mp[2];

			}

			if (mp[val] == 1) --mp_mp[2];

		}

		(mp_mp[2] >= 2 and mp_mp[4]) or (mp_mp[2] and mp_mp[6]) or mp_mp[4] >= 2 or (mp_mp[4] and mp_mp[6]) or mp_mp[6] >= 2 or mp_mp[8] ? puts("YES") : puts("NO");	

	}

}

int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	#ifndef ONLINE_JUDGE

		freopen("input.txt", "r", stdin);

		freopen("output.txt", "w", stdout);

		freopen("error.txt", "w", stderr);

	#endif

	ll t = 1;

	// cin >> t;

	while (t--)

		solve();

}
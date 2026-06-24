//#include <bits/stdc++.h>



#include <iostream>

#include <iomanip>

#include <cmath>

#include <cstdlib>

#include <cstdio>   

#include <string>

#include <string.h>

#include <stack>

#include <algorithm>

#include <map>

#include <vector>

#include <set>

#include <queue>

#include <climits>

#include <ctime>



using namespace std;



#define ll long long

#define ull unsigned long long

#define fi first

#define se second

#define pb push_back

#define pb1 pop_back

#define mp make_pair

#define sz(a) a.size()

#define all(v) v.begin(), v.end()

#define bpc(v) __builtin_popcountll(v)

#define db double

#define ld long double

#define fr freopen(".in", "r", stdin); freopen(".out", "w", stdout);

#define men_muni_baribir_koldanbaim ios_base :: sync_with_stdio(false); cin.tie(NULL);

#define sc scanf

#define pr printf



const int N = 1e5 + 5;

const int INF = 1e9 + 1;

const ll Mod = 1e9 + 7;                                                             



int k, w[27], ans, mx = -1;

vector<int> v;

string s;



main()

{

	cin >> s;

	sc("%d", &k);

	for (int i = 0; i < 26; ++i)

		sc("%d", &w[i]), mx = max(mx, w[i]);

	for (int i = 0; i < sz(s); ++i)

		v.pb(w[int(s[i] - 'a')]);

	for (int i = 1; i <= k; ++i)

		v.pb(mx);

	for (int i = 0; i < sz(v); ++i)

		ans += v[i] * (i + 1);

	pr("%d", ans);

	return 0;

}
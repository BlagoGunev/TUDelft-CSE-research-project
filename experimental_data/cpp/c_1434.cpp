#ifdef MY_LOCAL

#include "C://competitive_programming/debug/debug.h"

#define debug(x) cerr << "[" << #x<< "]:"<<x<<"\n"

#else

#define debug(x) 

#endif

#define REP(i, n) for(int i = 0; i < n; i ++)

#define REPL(i,m, n) for(int i = m; i < n; i ++)

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define SORT(arr) sort(arr.begin(), arr.end())

#define LSOne(S) ((S)&-(S))

#define M_PI 3.1415926535897932384

#define INF 1e18

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

typedef long long ll;

#define int ll

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef pair<int, int> ii;

typedef vector<ii> vii;

typedef double ld;

typedef tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

int solve() {

	int a,b,c,d;cin>>a>>b>>c>>d;

	if (a- b*c > 0){

		return -1;

	} 

	int maxtime = a/b;

	if (a%b == 0) {

		maxtime--;

	}

	int curmxX = maxtime/d;

	int mxX2 = a/d;

	if (a%d == 0) {

		mxX2--;

	}

	int mxX = min(curmxX, mxX2);

	debug(curmxX);

	debug(mxX2);

	debug(mxX);

	int totdmg = (mxX+1)*a;

	int totheal = b*(mxX)*(mxX+1)*d/2;

	return totdmg - totheal;



}



signed main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(NULL); cout.tie(NULL);

	int tc;

	cin>>tc;

	REP(i, tc) {

		cout<<solve()<<"\n";

	}



}
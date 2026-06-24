#include <iostream>

#include <string>

#include <sstream>

#include <iomanip> 

#include <math.h>

#include <stdio.h>

#include <string.h>

#include <queue>

#include <stack>

#include <vector>

#include <map>

#include <set>

#include <functional>

#include <algorithm>

#include <unordered_map>

#include <unordered_set>

#include <bitset>

#include <complex>

#include <numeric> 



using namespace std;



//#pragma GCC optimize("Ofast")

//#pragma GCC optimization("unroll-loops, no-stack-protector")

//#pragma GCC target("avx,avx2,fma")





typedef long long LL;

typedef pair<LL, LL> PL;

typedef vector<LL> VL;

typedef vector<PL> VPL;

typedef vector<VL> VVL;



typedef pair<int, int> PI;

typedef vector<int> VI;

typedef vector<PI> VPI;

typedef vector<vector<int>> VVI;

typedef vector<vector<PI>> VVPI;



typedef long double LD;

typedef pair<LD, LD> PLDLD;



typedef complex<double> CD;

typedef vector<CD> VCD;



#define MP make_pair

#define PB push_back

#define F first

#define S second

#define LB lower_bound

#define UB upper_bound



#define SZ(x) ((int)x.size())

#define LEN(x) ((int)x.length())

#define ALL(x) begin(x), end(x)

#define RSZ resize

#define ASS assign

#define REV(x) reverse(x.begin(), x.end());



#define MAX(x) *max_element(ALL(x))

#define MIN(x) *min_element(ALL(x))

#define FOR(i, n) for (int i = 0; i < n; i++) 

#define FOR1(i, n) for (int i = 1; i <= n; i++) 

#define SORT(x) sort(x.begin(), x.end())

#define RSORT(x) sort(x.rbegin(), x.rend())

#define SUM(x) std::accumulate(x.begin(), x.end(), 0LL)





#define IN(x) cin >> x;

#define OUT(x) cout << x << "\n";

#define INV(x, n) FOR(iiii, n) { cin >> x[iiii]; }

#define INV1(x, n) FOR1(iiii, n) { cin >> x[iiii]; }

#define OUTV(x, n) { FOR(iiii, n) { cout << x[iiii] << " "; } cout << "\n"; }

#define OUTV1(x, n) { FOR1(iiii, n) { cout << x[iiii] << " "; } cout << "\n"; }

#define OUTYN(x) { if (x) cout << "YES\n"; else cout << "NO\n"; }

#define OUTyn(x) { if (x) cout << "Yes\n"; else cout << "No\n"; }





const LL INF = 1E18;

const int MAXX = 200005;

const LD PAI = 4 * atan((LD)1);



#define MOD7 1000000007

#define MOD9 1000000009

#define MOD3 998244353









int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);



	LL n, nn, i, j, k, MOD = MOD3, ans, l, r;

	string s;



	cin >> n >> s;

	s = "0" + s;

	nn = (1LL << n) - 1;



	VL dp(nn + 1, 0);

	vector<string> ss(nn + 1);



	for (i = nn; i >= 1; i--) {

		l = i * 2; r = i * 2 + 1;

		if (l > nn) {

			// leaf

			ss[i] = s[i];

			dp[i] = 1;

		}

		else {

			if (ss[l] == ss[r]) dp[i] = (dp[l] * dp[r]) % MOD;

			else dp[i] = (dp[l] * dp[r] * 2) % MOD;

			if (ss[l] > ss[r]) ss[i] = s[i] + ss[r] + ss[l];

			else ss[i] = s[i] + ss[l] + ss[r];

		}

	}



	OUT(dp[1]);





	return 0;

}
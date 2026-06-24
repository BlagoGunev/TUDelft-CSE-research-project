#include<set>

#include<map>

#include<list>

#include<iomanip>

#include<cmath>

#include<string>

#include<vector>

#include<queue>

#include<stack>

#include<complex>

#include<sstream>

#include<iostream>

#include<fstream>

#include<algorithm>

#include<numeric>

#include<utility>

#include<functional>

#include<stdio.h>

#include<assert.h>

#include<memory.h>

#include<bitset>

using namespace std;





#define FilesX





#define rdi(i)          scanf("%d", &i)

#define rdii(i, j)      scanf("%d%d", &i, &j)

#define rep(i, v)       for(int i=0;i<v.size();++i)

#define lp(i, n)        for(int i=0;i<(int)(n);++i)

#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)

#define all(v)          ((v).begin()), ((v).end())

#define clr(v, d)       memset(v, d, sizeof(v))

#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)



typedef long long         ll;

typedef unsigned long long   ull;

const ll OO = 1e8;

const ll OOL = 1e18;

const ll MOD = 1e9 + 7;



const double EPS = (1e-7);

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }



#define pb                  push_back

#define MP                  make_pair

typedef long double       ld;

typedef vector<int>       vi;

typedef vector<double>    vd;

typedef pair<int, int>    pii;

typedef pair<ll, ll>      pll;

typedef vector<pair<int, int> > vii;

typedef vector< vi >      vvi;

typedef vector< vd >      vvd;

typedef vector<string>    vs;

typedef vector<ll>        vl;

typedef vector<vector<ll> >     vvl;

typedef vector<pair<ll, ll> >   vll;



ull gcd(ull a, ull b) { return (b == 0 ? a : gcd(b, a % b)); }

ull lcm(ull a, ull b) { return (a * (b / gcd(a, b))); }

ull power(ull a, ull b){ if (b == 0) return 1; ull ans = power(a, b / 2); ans = ans * ans; if (b % 2 != 0) ans *= a; return ans; }



int n, m;

string s[20];

int memo[1 << 20];

pair<int, int> same[20][20];

int arr[20][20];

int memo2[1 << 20];



int firstbit(int mask){

	int &ret = memo2[mask];

	if (ret != -1) return ret;



	lp(i, n) if (!(mask & (1 << i))) return ret = i;

	return 0;

}



int dp(int mask){

	if (mask == ((1 << n) - 1)) return 0;



	int &ret = memo[mask];

	if (ret != -1) return ret;



	int mini = OO;

	int i = firstbit(mask);

	lp(c, m){

		mini = min(mini, same[i][c].first + dp(mask | same[i][c].second));

		mini = min(mini, arr[i][c] + dp(mask | (1 << i)));

	}

	return ret = mini;

}



int main() {

#ifdef Files

	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);

#endif

	ios::sync_with_stdio(false);

	

	clr(memo, -1);

	clr(memo2, -1);

	cin >> n >> m;

	lp(i, n) cin >> s[i];

	lp(i, n) lp(j, m) cin >> arr[i][j];

	lp(i, n){

		lp(j, m){

			vi v;

			int cnt = 0;

			int mask = 0;

			lp(k, n){

				if (s[i][j] == s[k][j]){

					v.push_back(arr[k][j]);

					cnt += arr[k][j];

					mask |= (1 << k);

				}

			}

			sort(all(v));

			same[i][j] = make_pair(cnt - v.back(), mask);

		}

	}

	cout << dp(0) << endl;



	return 0;

}
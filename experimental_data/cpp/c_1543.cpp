// Problem: C. Need for Pink Slips

// Contest: Codeforces - Codeforces Round #730 (Div. 2)

// URL: https://codeforces.com/contest/1543/problem/C

// Memory Limit: 256 MB

// Time Limit: 1000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include<bits/stdc++.h>

using namespace std;

#define ll long long 

#define pb push_back

#define vi vector<int>

#define pii pair<int,int>

#define psi pair<string,int>

#define fi first

#define se second

#define lson son << 1

#define rson son << 1 | 1

#define all(x) (x).begin(),(x).end()

#define int ll 

const int N = 2e5+10, inf = 9e18, MAXN = 1e6 + 10, mod = 1e9 + 7;



double ans = 0;

double esp = 1e-12;

void dfs(double c1, double m1, double p1, double v1, double res1, double step1){

	if(res1 == 0 || res1 * p1 < esp)return;

	for(int i = 0; i < 3; i ++ ){

		double c = c1, m = m1, p = p1, v = v1, res = res1, step = step1;

		if(i == 0){

			if(c > 0){

				res *= c;

				if(c > v){

					if(m > esp){

						m += v / 2;

						p += v / 2; 

					}

					else {

						p += v;

					}

					c -= v;

				}

				else {

					if(m > esp){

						m += c / 2;

						p += c / 2; 

					}

					else {

						p += c;

					}

					c = 0;

				}

				dfs(c, m, p, v, res, step + 1);

			}

		}

		if(i == 1){

			if(m > 0){

				res *= m;

				if(m > v){

					if(c > esp){

						c += v / 2;

						p += v / 2; 

					}

					else {

						p += v;

					}

					m -= v;

				}

				else {

					if(c > esp){

						c += m / 2;

						p += m / 2; 

					}

					else {

						p += m;

					}

					m = 0;

				}

				dfs(c, m, p, v, res, step + 1);

			}

		}

		if(i == 2){

			res *= p;

			ans += res * step;

			return;

		}

	}

}



void solve(){

	double c, m, p, v;

	cin >> c >> m >> p >> v;

	ans = 0;

	

	double res = 1;

	

	

	dfs(c, m, p, v, res, double(1));

	printf("%.12lf\n", ans);

}

signed main(){

	// ios::sync_with_stdio(false);

	// cin.tie(0);

	int t = 1;

	cin >> t;

	while(t --){

		solve();

	}

	return 0;

}
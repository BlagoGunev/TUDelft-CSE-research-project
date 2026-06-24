#define _CRT_SECURE_NO_WARNINGS

#include <iterator>

#include <set>

#include <queue>

#include <iostream>

#include <sstream>

#include <stack>

#include <deque>

#include <map>

#include <cmath>

#include <memory.h>

#include <cstdlib>

#include <cstdio>

#include <cctype>

#include <algorithm>

#include <utility>

#include <time.h>



using namespace std;



#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)

#define FILL(A,val) memset(A,val,sizeof(A))

#define ITER(it,a) for(__typeof(a.begin()) it=a.begin();it!=a.end();++it)



#define ALL(V) V.begin(),V.end()

#define SZ(V) (int)V.size()

#define PB push_back

#define MP make_pair



typedef long long Int;

typedef unsigned long long UInt;

typedef vector<int> VI;

typedef pair<int, int> PII;



const double PI = acos(-1.0);

const int INF = 1000000000;



const int MOD = 1000000007;

const int LOG = 25;



vector<pair<int, int> > g[100100];



int S[100100];

int S2[100100];

int SA[100100];

int SA2[100100];

int C[100100];

int up[100100][LOG];

int tin[100100];

int tout[100100];

int timer;

int Dup[100100];



int n;



void norm(int& x) {

	if (x >= MOD) x -= MOD;

	if (x < 0) x += MOD;

}



int addS2(int s2, int s, int cnt, int add) {

	long long res = s2 + 2 * add * (long long)s + (((add * (long long)add) % MOD) * (long long)cnt);



	return res % MOD;

}



void dfs(int x, int p, int dup) {

	tin[x] = timer;

	timer++;



	up[x][0] = p;

	FOR(i, 1, LOG) {

		up[x][i] = up[up[x][i - 1]][i - 1];

	}

	S[x] = 0;

	C[x] = 1;



	norm(dup);



	Dup[x] = dup;



	FOR(i, 0, SZ(g[x])) {

		int to = g[x][i].first;

		if (to == p) continue;



		dfs(to, x, dup + g[x][i].second);



		C[x] += C[to];



		S[x] += (g[x][i].second * (long long)C[to]) % MOD;

		norm(S[x]);

		S[x] += S[to];

		norm(S[x]);



		S2[x] += addS2(S2[to], S[to], C[to], g[x][i].second);

		norm(S2[x]);

	}



	tout[x] = timer;

	timer++;

}



void dfs2(int x, int p, int s, int s2) {



	//cout << x << ' ' << p << ' ' << s << ' ' << s2 << endl;



	SA[x] = S[x] + s;

	norm(SA[x]);



	SA2[x] = S2[x] + s2;

	norm(SA2[x]);



	int sum = s + S[x];

	int sum2 = s2 + S2[x];



	norm(sum);

	norm(sum2);

	

	FOR(i, 0, SZ(g[x])) {

		int to = g[x][i].first;

		if (to == p) continue;



		int ns = sum;



		int ns2 = sum2;

				

		int cnt = n - C[to];

		//cout << ns << endl;

		ns -= (g[x][i].second  * (long long) C[to]) % MOD;

		norm(ns);

		ns -= S[to];

		norm(ns);



		//cout << "****" << ns2 <<' '<<ns<< endl;

		ns2 -= addS2(S2[to], S[to], C[to], g[x][i].second);

		//cout << "***" << ns2 << endl;

		norm(ns2);

		ns2 = addS2(ns2, ns, n - C[to], g[x][i].second);

		norm(ns2);

		//cout << "**" << ns2 << endl;



		ns += (cnt * (long long)g[x][i].second) % MOD;

		norm(ns);



	//	cout << "*" << ns2<< endl;

		

		dfs2(to, x, ns, ns2);

	}

}





bool desc(int x, int y) {

	return tin[y] <= tin[x] && tout[y] >= tin[x];

}



int cp(int x, int y) {

	if (desc(x, y)) return y;

	if (desc(y, x)) return x;

	RFOR(i, LOG, 0) {

		if (!desc(y, up[x][i])) x = up[x][i];

	}



	return up[x][0];

}



int getDist(int x, int y) {

	int p = cp(x, y);

//	cout << "==" << x<<' '<<y<<' '<<p << endl; 



	int res = Dup[x] + Dup[y];

	//cout << res << endl;

	norm(res);

	res -= Dup[p];

	norm(res);

	res -= Dup[p];

	norm(res);



	return res;

}



int main()

{

	//freopen("in.txt", "r", stdin);



	scanf("%d", &n);



	FOR(i, 0, n - 1) {

		int x, y, c;

		scanf("%d%d%d", &x, &y, &c);

		x--;

		y--;



		g[x].push_back(MP(y, c));

		g[y].push_back(MP(x, c));

	}



	dfs(0, 0, 0);

	dfs2(0, -1, 0, 0);



/*	FOR(i, 0, n) {

		cout << Dup[i] << ' ';

	}

	cout << endl;*/



/*	FOR(i, 0, n) {

		cout << i + 1 << '\t' << S[i] << '\t' << S2[i] << '\t' << SA[i] << '\t' << SA2[i] << '\t' << C[i] << '\t' << Dup[i] << endl;

	}

	cout <<"===="<< getDist(2, 6) << endl;

	cout << "*";*/

	int m;

	scanf("%d", &m);

	FOR(i, 0, m) {

		int x, y;

		scanf("%d%d", &x, &y);

		x--;

		y--;

	//	cout << endl;



		if (desc(x, y)) {

		//	cout << "1* " << endl;

			int res = SA2[x];



		//	cout << "*" << res << endl;



			int dist = getDist(x, y);

			int diff = SA2[y] - S2[y];

			norm(diff);

			int d = SA[y] - S[y];

			norm(d);

			

			diff = addS2(diff, d, n - C[y], dist);

		//	cout << "**" << diff << endl;



			res -= diff;

			norm(res);

			res -= diff;

			norm(res);

			//printf("%d\n", res);

			cout << res << "\n";

		}

		else {

			//cout << "2* ";

			int res = SA2[x];

		//	cout << "*" << res << endl;



			int dist = getDist(x, y);

		//	cout << dist << endl;

			int diff = addS2(S2[y], S[y], C[y], dist);

		//	cout << "**" << diff << endl;



			res -= diff;

			norm(res);

			res -= diff;

			norm(res);

			res = -res;

			norm(res);

			//printf("%d\n", res);

			cout << res << "\n";

		}

	}



	return 0;

}
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



#define FOR(i, a, b) for(int i=(a);i<(b);i++)

#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)

#define FILL(A,value) memset(A,value,sizeof(A))



#define ALL(V) V.begin(), V.end()

#define SZ(V) (int)V.size()

#define PB push_back

#define MP make_pair

#define y1 ewrgrg

#define INF 1000000000

const double PI = acos(-1.0);



typedef long long ll;

typedef long long LL;

typedef pair<int, int> PII;

typedef vector<int> VI;



pair<long long, int> A[100100];



int ind;

int pos;

long long level;

long long n, m, c1, c2;



int Res[100100];



long long getH(int x) {

	if (x >= pos) return m;



	return A[x].first;

}



long long add(long long s) {

	

	while (true) {

		while (getH(ind) == level) ind++;



		long long diff = getH(ind) - level;



		if (s < diff * ind) {

			long long levels = s / ind;

			level += levels;

			s %= ind;

			return s;

		}



		s -= diff * ind;

		level += diff;

		while (getH(ind) == level) ind++;

	}

}



int main(int argc, char* argv[]) {



	//freopen("in.txt", "r", stdin);

	long long s;



	cin >> n >> m >> c1 >> c2 >> s;

	//n = 100000;

	//m = 1000000000ll;

	//c1 = c2 = 0;

	//s = 10000000000ll;

	long long sum = 0;

	FOR(i, 0, n) {

		int x;

		scanf("%d", &x);

		//x = 100000;

		A[i].first = x;

		sum += A[i].first;

		A[i].second = i;

	}



	if (n * (long long)m - sum <= s) {

		cout << n * c1 + m * c2 << endl;

		FOR(i, 0, n) {

			printf("%d ", m);

		}

		return 0;

	}



	sort(A, A + n);

	pos = n;



	RFOR(i, n, 0) {

		if (m - A[i].first <= s) {

			s -= m - A[i].first;

			pos = i;

		}

		else break;

	}



	FOR(i, 0, n) {

		if (A[i].first == A[0].first) {

			ind = i + 1;

		}

		else break;

	}





	level = A[0].first;





	s = add(s);

	

	long long res = 0;

	int mind = -1;

	int mpos = INF;

	long long mlevel = -1;



	for (; pos < n;) {

		long long c = level * c2 + (n - pos) * c1;



		if (c > res) {

			res = c;

			mind = ind;

			mpos = pos;

			mlevel = level;

		}



		s += m - A[pos].first;

		pos++;

		s = add(s);

	}



	long long c = level * c2;

	if (c > res) {

		res = c;

		mind = ind;

		mpos = pos;

		mlevel = level;

	}



	FOR(i, 0, n) {

		if (i < mind) A[i].first = mlevel;

		if (i >= mpos) A[i].first = m;



		Res[A[i].second] = A[i].first;

	}





	cout << res << endl;

	FOR(i, 0, n) {

		printf("%d ", Res[i]);

	}

	

}
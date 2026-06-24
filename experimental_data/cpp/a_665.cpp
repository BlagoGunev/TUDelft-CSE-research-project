#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#include <unordered_map>

#include <unordered_set>



using namespace std;



#define V vector

#define MP make_pair

#define all(v)  ((v).begin()), ((v).end())

#define allr(v) ((v).rbegin()), ((v).rend())

#define clr(v, d) memset(v, d, sizeof(v))

#define sf(x) scanf("%d", &x)

#define sf2(x, y) scanf("%d %d", &x, &y)

#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)

#define sfll(x) scanf("%I64d", &x)

#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)

#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};

int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

typedef unsigned long long          ull;

typedef long long                   ll;

typedef long double                 LD;

ll suf(ll x) { return (x * (x + 1)) / 2; }

V<V<int > > adj;

const ll mod = 1e9 + 7, size = 1000006, oi = INT_MAX, ol = INT64_MAX;

int n, m, x, y, z;





int main()

{

	int a, ta, b, tb, h, m;

	char ch;

	while (cin >> a >> ta >> b >> tb >> h >> ch >> m){

		int H = 5, M = 0, cnt = 0;

		deque<int>q;



		bool en = 1;

		while ((H < h || M <= m) && H < 24 ){

			if (cnt % b == 0) q.push_back(0);

			if (q.front() == tb) q.pop_front();

			M++;

			if (M == 60) M = 0, H++;

			if (H == 24) en = 0;

			cnt++;

			for (int i = 0; i < q.size(); i++)

				q[i] ++;

		}

		int ans = 0;

		for (int i = 2; i <= ta; i++){

			if (en && cnt % b == 0) q.push_back(0);

			M++;

			if (M == 60) M = 0, H++;

			if (H == 24)

				en = 0;

			cnt++;

			for (int i = 0; i < q.size(); i++)

				q[i] ++;

		}

		for (int i = 0; i < q.size(); i++)

			if (q[i] > 0)

				ans++;

		

		cout << ans << endl;

	}

	return 0;

}
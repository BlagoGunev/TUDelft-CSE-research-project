#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

VI R, G, B;

LL get(VI& a, int l, int r)
{
	int pos1 = lower_bound(ALL(a), l) - a.begin();
	int pos2 = upper_bound(ALL(a), r) - a.begin() - 1;

	if (pos1 > pos2)
	{
		return r - l;
	}

	LL res = 0;
	res = max<LL>(res, a[pos1] - l);
	res = max<LL>(res, r - a[pos2]);

	FOR (i, pos1 + 1, pos2 + 1)
	{
		res = max<LL>(res, a[i] - a[i-1]);
	}
	return res;
}

int mrand()
{
	return abs((rand() << 16) ^ rand());
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	//rand();
	//n = 10;
	FOR (i, 0, n)
	{
		int x;
		scanf("%d", &x);
		//x = mrand() % 1000000000 + 1;
		char c = getchar();
		while(c != 'R' && c != 'G' && c != 'B')
		{
			c = getchar();
		}

	//	char c = "RGB"[rand() % 3];

		if (c == 'R') R.PB(x);
		if (c == 'G') G.PB(x);
		if (c == 'B') B.PB(x);
	}

	sort(ALL(G));
	sort(ALL(R));
	sort(ALL(B));

	if (SZ(G) == 0)
	{
		LL res = 0;
		if (SZ(R)) res += R.back() - R[0];
		if (SZ(B)) res += B.back() - B[0];
		cout<<res<<endl;
		return 0;
	}

	LL res = 0;

	if (SZ(B))
	{
		if (B[0] < G[0]) res += G[0] - B[0];
		if (B.back() > G.back()) res += B.back() - G.back();
	}

	if (SZ(R))
	{
		if (R[0] < G[0]) res += G[0] - R[0];
		if (R.back() > G.back()) res += R.back() - G.back();
	}

	FOR (i, 1, SZ(G))
	{
		LL a = get(B, G[i-1], G[i]);
		LL b = get(R, G[i-1], G[i]);

		LL r1 = (G[i] - G[i-1]) * (LL)2;

		LL r2 = (G[i] - G[i-1]) * (LL)3 - a - b;

	//	cout<<G[i-1]<<' '<<G[i]<<": "<<r1<<' '<<r2<<endl;

		res += min(r1, r2);
	}

	cout<<res<<endl;
}
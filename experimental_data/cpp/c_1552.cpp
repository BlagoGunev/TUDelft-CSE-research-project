#include<bits/stdc++.h>

#include<unordered_map>

#include<unordered_set>

using namespace std;

using LL = long long;

using LD = long double;

using ULL = unsigned long long;

using PII = pair<int, int>;

using TP = tuple<int, int, int>;

#define all(x) x.begin(),x.end()

#define mst(x,v) memset(x,v,sizeof(x))

#define mk make_pair

//#define int LL

//#define double LD

//#define lc p*2

//#define rc p*2+1

#define endl '\n'

#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3f

#pragma warning(disable : 4996)

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const double eps = 1e-10;

const LL MOD = 1000000007;

const LL mod = 998244353;

const int maxn = 220;



int T, N, K, dat[maxn];

bool vis[maxn];



void add(int i,int x)

{

	while (i <= N * 2)

		dat[i] += x, i += i & (-i);

}



int sum(int i)

{

	int ret = 0;

	while (i)

		ret += dat[i], i -= i & (-i);

	return ret;

}



void solve()

{

	vector<PII>chord;

	for (int i = 1; i <= N * 2; i++)

		vis[i] = false, dat[i] = 0;

	int u, v;

	for (int i = 1; i <= K; i++)

	{

		cin >> u >> v, vis[u] = vis[v] = true;

		if (u > v)

			swap(u, v);

		chord.push_back(PII(u, v));

	}

	int cnt = 0, l = 0, r = 0;

	for (int i = 1; i <= N * 2; i++)

	{

		if (!vis[i])

		{

			cnt++;

			if (cnt == 1)

				l = i;

			if (cnt == N - K + 1)

				r = i;

		}

	}

	for (int i = 1; i <= N - K; i++)

	{

		while (vis[l])

			l++;

		while (vis[r])

			r++;

		chord.push_back(PII(l, r)), vis[l] = vis[r] = true;

	}

	int ans = 0;

	sort(all(chord));

	for (auto& [x, y] : chord)

		add(y, 1), ans += sum(y - 1) - sum(x);

	cout << ans << endl;

}



int main()

{

	IOS;

	cin >> T;

	while (T--)

	{

		cin >> N >> K;

		solve();

	}



	return 0;

}
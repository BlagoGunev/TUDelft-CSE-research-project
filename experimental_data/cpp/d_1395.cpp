#include<bits/stdc++.h>

#include<unordered_map>

#include<unordered_set>

using namespace std;

using LL = long long;

using LD = long double;

using ULL = unsigned long long;

using PII = pair<LL, LL>;

using TP = tuple<int, int, int>;

#define all(x) x.begin(),x.end()

#define mst(x,v) memset(x,v,sizeof(x))

#define mul(x,y) (1ll*(x)*(y)%mod)

#define mk make_pair

//#define int LL

//#define double LD

#define lc tr[x].ch[0]

#define rc tr[x].ch[1]

#define endl '\n'

#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3f

#pragma warning(disable : 4996)

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const double eps = 1e-10;

const double pi = acos(-1);

const LL MOD = 1000000007;

const LL mod = 998244353;

const int maxn = 100010;



LL N, D, M, A[maxn];

LL SA[maxn], SB[maxn];



void solve()

{

	LL ans = -INF;

	sort(A + 1, A + N + 1);

	LL tota = 1, totb = 0;

	SA[1] = A[N];

	for (int i = N - 1; i >= 1; i--)

	{

		if (A[i] <= M)

			SA[++tota] = A[i];

		else

			SB[++totb] = A[i];

	}

	for (int i = 1; i <= tota; i++)

		SA[i] = SA[i - 1] + SA[i];

	for (int i = 1; i <= totb; i++)

		SB[i] = SB[i - 1] + SB[i];

	for (LL i = 0; i * (D + 1) <= N; i++)

	{

		if (i > totb)

			break;

		LL tmp = SB[i] + SA[min(tota, N - i * (D + 1))];

		ans = max(ans, tmp);

	}

	cout << ans << endl;

}



int main()

{

	IOS;

	cin >> N >> D >> M;

	for (int i = 1; i <= N; i++)

		cin >> A[i];

	solve();



	return 0;

}
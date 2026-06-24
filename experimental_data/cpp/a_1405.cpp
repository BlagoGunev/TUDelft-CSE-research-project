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

const int maxn = 110;



int T, N, A[maxn];



void solve()

{

	for (int i = N; i >= 1; i--)

		cout << A[i] << ' ';

	cout << endl;

}



int main()

{

	IOS;

	cin >> T;

	while (T--)

	{

		cin >> N;

		for (int i = 1; i <= N; i++)

			cin >> A[i];

		solve();

	}



	return 0;

}
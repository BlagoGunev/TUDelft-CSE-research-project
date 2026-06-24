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

#define mul(x,y) (1ll*(x)*(y)%mod)

#define mk make_pair

//#define int LL

//#define double LD

#define lc p*2

#define rc p*2+1

#define endl '\n'

#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3f

#pragma warning(disable : 4996)

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const double eps = 1e-8;

const double pi = acos(-1);

const LL MOD = 1000000007;

const LL mod = 1004535809;

const int maxn = 1510;



int T, N;



void solve()

{

	if (N == 1)

		cout << 0 << endl;

	else if (N == 2)

		cout << 1 << endl;

	else if (N % 2 == 0 || N == 3)

		cout << 2 << endl;

	else

		cout << 3 << endl;

}



int main()

{

	IOS;

	cin >> T;

	while (T--)

	{

		cin >> N;

		solve();

	}



	return 0;

}
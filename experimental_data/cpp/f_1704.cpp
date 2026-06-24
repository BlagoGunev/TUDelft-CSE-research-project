//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt")

//#pragma GCC optimize("Ofast")

//#pragma GCC optimize("unroll-loops")

#include <set>

#include <map>

#include <deque>

#include <string>

#include <cstdint>

#include <cmath>

#include <queue>

#include <cassert>

#include <random>

#include <bitset>

#include <iomanip>

#include <cstring>

#include <numeric>

#include <time.h>//////////////

#include <ctime>

#include <climits>

#include <cstdio>

#include <vector>

#include <cstdlib>

#include <iostream>

#include <algorithm>

#include <unordered_map>

#include <complex>

#include <chrono>

#include <unordered_set>

using namespace std;



using ll = long long;

using ull = unsigned long long;

using ld = long double;



#define all(a) (a).begin(), (a).end()

#define pbc push_back

#define pob pop_back()

#define vin(a) for (auto& i : a) cin >> i

#define sp system("pause")

#define mp make_pair

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());



template<typename T1, typename T2>

inline void chkmin(T1& x, const T2& y)

{

	if (y < x) x = y;

}



template<typename T1, typename T2>

inline void chkmax(T1& x, const T2& y)

{

	if (x < y) x = y;

}

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

ld asdasdcl;

double getTime() { return (clock() - asdasdcl) / (double)CLOCKS_PER_SEC; }



//#define getchar_unlocked _getchar_nolock

//inline int readInt()

//{

//	char x;

//	while (x = getchar_unlocked())

//	{

//		if (x >= '0' && x <= '9')

//		{

//			int ans = x - '0';

//			while (x = getchar_unlocked())

//			{

//				if (!(x >= '0' && x <= '9')) return ans;

//				ans = ans * 10 + x - '0';

//			}

//		}

//	}

//}

const int inf = 1e9 + 228;

const ld EPS = 1e-7;

const int MAXN = 5e5 + 228;

int dp[MAXN];

signed main()

{

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cout.precision(20), cout.setf(ios::fixed);

	int t;

	cin >> t;

	for (int i = 2; i <= 500; ++i)

	{

		vector<int> keks;

		for (int x = 0; x + 2 <= i; ++x)

		{

			keks.pbc(dp[x] ^ dp[i - 2 - x]);

		}

		sort(all(keks));

		keks.resize(unique(all(keks)) - keks.begin());

		keks.pbc(inf);

		//		dp[i] = -1;

		for (int j = 0; j < keks.size(); ++j)

		{

			if (keks[j] > j)

			{

				dp[i] = j;

				break;

			}

		}

	}

	/*for (int plen = 3;; ++plen)

	{

		for (int fs = 0; fs <= plen*2; ++fs)

		{

			bool ok = 1;



			int st = fs;

			for (int j = st + plen; j <= 500; ++j)

			{

				if (dp[j] != dp[j - plen])

				{

					ok = 0;

				}

			}

			if (ok)

			{

				cout << fs << ' ' << plen << endl;

				sp;

			}

		}

	}*/

	/*for (int i = 53; i <= 500; ++i)

	{

		if (i <= 53 + 34)

		{

			cout << i << ' ' << dp[i] << ' ' << dp[i] << '\n';

		}

		else

		{

			cout << i << ' ';

			int nw = i % 34;

			int go = 68 + nw;

			cout << dp[i] << ' ' << dp[go] << '\n';

		}

	}*/

	while (t--)

	{

		int n;

		cin >> n;

		string s;

		cin >> s;

		if (count(all(s), 'B') > count(all(s), 'R'))

		{

			cout << "Bob\n";

			continue;

		}

		if (count(all(s), 'R') > count(all(s), 'B'))

		{

			cout << "Alice\n";

			continue;

		}

		int cnt = 1;

		vector<int> lens;

		for (int i = 1; i < s.size(); ++i)

		{

			if (s[i] != s[i - 1])

			{

				++cnt;

			}

			else

			{

				lens.pbc(cnt);

				cnt = 1;

			}

		}

		lens.pbc(cnt);

		int res = 0;

		for (int i : lens)

		{

			if (i <= 53 + 34)

			{

				res ^= dp[i];

			}

			else

			{

				res ^= dp[68+i%34];

			}

		}

		if (res) cout << "Alice\n";

		else cout << "Bob\n";

	}

	//sp;

}
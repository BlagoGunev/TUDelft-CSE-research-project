#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

const ld PI = 4*atan((ld)1);
const int MAX = 2e5 + 69;

int N;
int ar[MAX];

inline int gcd(int x, int y)
{
	if (y == 0)
		return x;
	return gcd(y, x%y);
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> ar[i];

	const auto check = [&](int len) -> bool
	{
		int g = 0;
		for (int i = 0; i < len; ++i)
		{
			for (int j = i+len; j < N; j += len)
				g = gcd(g, abs(ar[j] - ar[i]));
		}

		return g != 1;
	};

	int res = 0;
	for (int j = 1; j*j <= N; ++j) if (N % j == 0)
	{
		res += check(j);
		if (j * j < N) res += check(N / j);
	}
	cout << res << '\n';
}

int main()
{
	fastio;

	int TC = 1;
	cin >> TC;

	while (TC--)
		solve();

	return 0;
}
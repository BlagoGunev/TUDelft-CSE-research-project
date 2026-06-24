#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define X first
#define Y second

const LL MOD1 = 1000000007;
const int INF = 1000000007;
const LL LINF = 1LL * INF * INF;
const int MAXN = 1000047;
const LD EPS = 1e-6;
const LD PI = acos(-1.0);

const int P = 47;
const int MOD2 = 1000000009;

string S;
set <int> Se;
pair <LL, LL> PP[MAXN], H[MAXN];
vector <int> ANS;

pair <LL, LL> operator+ (pair <LL, LL> a, pair <LL, LL> b)
{
	return MP((a.first + b.first) % MOD1, (a.second + b.second) % MOD2);
}

pair <LL, LL> operator- (pair <LL, LL> a, pair <LL, LL> b)
{
	return MP(((a.first - b.first) % MOD1 + MOD1) % MOD1, ((a.second - b.second) % MOD2 + MOD2) % MOD2);
}

pair <LL, LL> operator* (LL a, pair <LL, LL> p)
{
	return MP((a * p.first) % MOD1, (a * p.second) % MOD2);
}

pair <LL, LL> operator* (pair <LL, LL> a, pair <LL, LL> b)
{
	return MP((a.first * b.first) % MOD1, (a.second * b.second) % MOD2);
}

bool eq(int l1, int r1, int l2, int r2)
{
	return PP[l2 - l1] * (H[r1] - H[l1 - 1]) == H[r2] - H[l2 - 1];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	int n;
	cin >> n >> S;
	reverse(S.begin(), S.end());
	S.push_back('#');
	reverse(S.begin(), S.end());
	PP[0] = MP(1, 1);
	FOR(i, 1, n + 1)
		PP[i] = P * PP[i - 1];
	FOR(i, 1, n + 1)
		H[i] = H[i - 1] + (S[i] - 'a' + 1) * PP[i];
	for (int k = (n + 1) >> 1; k >= 1; --k)
	{
		while (!Se.empty() && !eq(k, -2 * *Se.begin() - k, n + 1 + k + 2 * *Se.begin(), n + 1 - k))
			Se.erase(Se.begin());
		if (S[k] == S[n + 1 - k] && 2 * k != n + 1)
			Se.insert(-k);
		ANS.push_back(Se.empty() ? -1 : 2 * (-*Se.begin() - k) + 1);
	}
	RFOR(i, SZ(ANS), 0)
		cout << ANS[i] << ' ';
	return 0;
}
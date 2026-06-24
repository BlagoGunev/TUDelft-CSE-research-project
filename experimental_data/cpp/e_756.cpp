#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 300003;
const int MODULE = 1000 * 1000 * 1000 + 7;

int a[MAXN];
int nd[MAXN];

ll f[MAXN];
ll sf[MAXN];
int bb[MAXN];

const int LX = 10002;
int x[LX];
string s;
int l, r;
const ll MVAL = 1000 * 1000 * 100;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n;i++)
	{
		cin >> a[i];
	}
	memset(nd, 0, sizeof(nd));
	for (int i = 1; i <= n; i++) cin >> bb[i];
	a[n] = 1;
	cin >> s;
	memset(x, 0, sizeof(x));
	for (int i = 0; i < s.length(); i++) 
	{
		x[s.length() - 1 - i] = s[i] - '0';
	}
	bool nz = true;
	for (l = 1; (l < n) && nz; l = r)
	{
		ll cm = 1;
		r = l;
		while ((cm < MVAL) && (r < n))
		{
			cm *= a[r++];
		}
		ll cv = 0;
		nz = false;
		for (int i = LX - 1; i >= 0; i--)
		{
			cv = cv * 10 + x[i];
			x[i] = cv / cm;
			cv %= cm;
			if (x[i] > 0) nz = true;
		}
		for (int i = l; i < r; i++)
		{
			nd[i] = cv % a[i];
			cv /= a[i];
		}
	}
	nd[n] = 0;
	for (int i = LX - 1; i >= 0; i--)
	{
		nd[n] = (nd[n] * 10 + x[i]);
		if (nd[n] > MAXN)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	memset(f, 0, sizeof(f));
	f[0] = 1;
	int k = 0;
	for (int j = 1; j <= n; j++)
	{
		int b = bb[j];
		sf[0] = f[0];
		k += b;
		for (int i = 1; i <= k; i++) sf[i] = sf[i - 1] + f[i];
		for (int i = 0; i <= k; i++)
		{
			f[i] = sf[i];
			if (i > b) f[i] -= sf[i - b - 1];
			f[i] %= MODULE;
		}
		int nk = k;
		if (k < nd[j]) 
		{
			cout << 0 << endl;
			return 0;
		}
		k = (k - nd[j]) / a[j];
		for (int i = 0; i <= k; i++)
		{
			int ni = i * a[j] + nd[j];
			if (ni <= nk) f[i] = f[ni];
			else f[i] = 0;
		}
		for (int i = k + 1; i <= nk; i++) f[i] = 0;
	}
	cout << f[0] << endl;
	return 0;
}
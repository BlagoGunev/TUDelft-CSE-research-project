#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int maxn = 5e5+10;

int arr[maxn];
int perm[maxn];
int L[maxn];

#define lc (v<<1)
#define rc (lc|1)

int vals[maxn*4]; // max
int vidx[maxn*4];
inline void upd(int v)
{
	vals[v] = max(vals[lc], vals[rc]);
	if(vals[lc] == vals[v])
		vidx[v] = vidx[lc];
	else
		vidx[v] = vidx[rc];
}
void build(int l, int r, int v)
{
	if(r-l == 1)
	{
		vals[v] = -1;
		vidx[v] = l;
		return;
	}
	int m = (l+r) / 2;
	build(l, m, lc);
	build(m, r, rc);
	upd(v);
}
void ass(int l, int r, int p, int x, int v)
{
	if(r-l == 1)
	{
		vals[v] = x;
		return;
	}
	int m = (l+r) / 2;
	if(p < m)
		ass(l, m, p, x, lc);
	else
		ass(m, r, p, x, rc);
	upd(v);
}
pii get(int l, int r, int s, int e, int v) // smallest max
{
	if(e <= l or r <= s) return pii(-1, -1);
	if(s <= l and r <= e) return pii(vals[v], -vidx[v]);
	int m = (l+r) / 2;
	return max(get(l, m, s, e, lc), get(m, r, s, e, rc));
}

void dbg(int n)
{
	for(int i = 0; i < n; i++)
	{
		pii x = get(0, n, i, i+1, 1);
		cerr << x.first << "," << x.second << " ";
	}
	cerr << endl;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		int n; cin >> n;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		iota(perm, perm+n, 0);
		sort(perm, perm+n, [&](int i, int j){return arr[i] < arr[j] or (arr[i] == arr[j] and i < j) ;});
		for(int i = 0; i < n; i++)
			for(L[i] = i-1; L[i] >= 0 and arr[L[i]] < arr[i]; L[i] = L[L[i]]);
		build(0, n, 1);
		int ans = 2;
		for(int idx = 0; idx < n; idx++)
		{
			int i = perm[idx];
			pii x = get(0, n, 0, i, 1);
			//cerr << i << " " << x.first << " " << -x.second << " ";
			if(x.first == -1)
			{
				//cerr << 1+(L[i]!=-1) << endl;
				ass(0, n, i, 1+(L[i] != -1), 1);
				continue;
			}
			int a = x.first+1;
			int b = -x.second;
			if(L[i] > b)
				a++;
			//cerr << a << endl;
			ass(0, n, i, a, 1);
			//dbg(n);
			ans = max(ans, a);
		}
		cout << ans << endl;
	}
	return 0;
}
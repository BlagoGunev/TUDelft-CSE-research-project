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
	
const int MN = 31;
const int MAXN = 200002;
string tot;
int st[MN];
int id[MAXN];
string s[MN];

int e[MAXN][MN];
string zs;
int z[MAXN];
bool fr[MAXN];
int cn = 0, n = 0;
int tout[MAXN], tc;
int tid[MAXN];
bool stt[MAXN];
vector <int> eo[MAXN];
int lc, rc;

void dfs(int v)
{
	if (!fr[v]) return;
	fr[v] = false;
	for (int i = lc; i < rc; i++)
	{
		if (e[v][i] != -1) dfs(e[v][i]);
	}
	tid[v] = tc;
	tout[tc++] = v;
}

int gr[MAXN];
int gc = 0;

void dfs1(int v)
{
	if (fr[v]) return;
	fr[v] = true;
	gr[gc++] = v;
	for (int i = 0; i < eo[v].size(); i++)
	{
		dfs1(eo[v][i]);
	}
}

bool go(int lg, int rg)
{
	lc = lg, rc = rg;
		memset(fr, 0, sizeof(fr));
	if (rg > n) return false;
	memset(stt, 0, sizeof(stt));
	for (int i = lg; i < rg; i++) stt[st[i]] =  true;
	for (int i = st[lg]; i < st[rg]; i++) fr[i] = true;
	fr[cn] = true;
	stt[cn] = true;
	tc = 0;
	for (int i = 0; i <= cn; i++) eo[i].clear();
	for (int i = 0; i <= cn; i++)
	{
		if (!fr[i]) continue;
		for (int j = lg; j < rg; j++)
		{
			if (e[i][j] != -1) eo[e[i][j]].push_back(i);
		}
	}
	for (int i = 0; i <= cn; i++)
	{
		dfs(i);
	}
	for (int i= tc - 1; i >= 0; i--)
	{
		int v = tout[i];
		if (fr[v]) continue;
		gc = 0;
		for (int j = 0; j < n; j++)
		{
			if ((!stt[v]) && (e[v][j] == v)) 
				return false;
		}
		dfs1(v);
		if (gc > 1)
		{
			for (int j = 0; j < gc; j++)
			{
				if (!stt[gr[j]])
					return false;
			}
		}
	}
	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		st[i] = cn;
		cin >> s[i];
		cn += s[i].length();
		tot += s[i];
	} 
	st[n] = cn;
	for (int i = 0; i <= cn; i++)
	{
		for (int j = 0; j < n; j++) e[i][j] =  -1;
	}
	memset(fr, 0, sizeof(fr));
	for (int i = 0; i < n; i++)
	{
		e[cn][i] = st[i];
		int sil = s[i].length();
		zs = s[i] + tot;
		zs += '#';
		int sl = zs.length(), l, r;
		z[0] = l = r = 0;
		for (int j = 1; j < sl; j++)
		{
			int k = 0;
			if (r > j) k = min(r - j, z[j - l]);
			while (zs[j + k] == zs[k]) k++;
			z[j] = k;
			if (k > r)
			{
				l  = j;
				r = j + k;
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int jj = st[j]; jj < st[j + 1]; jj++)
			{
				e[jj][i] = -1;
				int ln = st[j + 1] - jj;
				if (z[jj + sil] >= min(ln, sil))
				{
					if (ln > sil) e[jj][i] = jj + sil;
					else if (ln == sil) e[jj][i] = cn;
					else e[jj][i] = st[i + 1] - (sil - ln);
				}
			}
		}
	}
	st[n] = tot.length();
	int p = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		while (go(i, p))
			p++;
		ans += p - i - 1;
	}
	cout << ans << endl;
	return 0;
}
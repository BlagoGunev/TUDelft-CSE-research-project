#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

bitset<2005> f[2005];
int n, m, q;
bitset<2005> gr[2005];
map<PII, bool> pct;
set<PII> ok;

bool cont(int a, int b)
{
	return (gr[a] & gr[b]) == gr[b];
}

void erase_r(int cr, int ccnt)
{
	map<PII, bool>::iterator it = pct.find(MP(ccnt, cr));
	if(it->second) ok.erase(MP(it->first.second, next(it)->first.second));
	if(it != pct.begin()) {
		map<PII, bool>::iterator nit = prev(it);
		if(nit->second) ok.erase(MP(nit->first.second, it->first.second));
		nit->second = next(it) == pct.end() ? false : !cont(next(it)->first.second, nit->first.second);
		if(nit->second) ok.insert(MP(nit->first.second, next(it)->first.second));
	}
	pct.erase(it);
}

void insert_r(int cr, int ccnt)
{
	pct.insert(MP(MP(ccnt, cr), false));
	map<PII, bool>::iterator it = pct.find(MP(ccnt, cr));
	it->second = next(it) == pct.end() ? false : !cont(next(it)->first.second, it->first.second);
	if(it->second) ok.insert(MP(it->first.second, next(it)->first.second));
	if(it != pct.begin()) {
		map<PII, bool>::iterator nit = prev(it);
		if(nit->second) ok.erase(MP(nit->first.second, next(it)->first.second));
		nit->second = !cont(it->first.second, nit->first.second);
		if(nit->second) ok.insert(MP(nit->first.second, it->first.second));
	}
}

void gen_ans(int l0, int l1)
{
	int p0 = (gr[l0] & ~gr[l1])._Find_first(), p1 = (~gr[l0] & gr[l1])._Find_first();
	if(l0 > l1) swap(l0, l1);
	if(p0 > p1) swap(p0, p1);
	printf("%d %d %d %d\n", l0 + 1, p0 + 1, l1 + 1, p1 + 1);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i <= m; i ++) rep(j, i) f[i][j] = true;
	
	rep(i, n) pct.insert(MP(MP(0, i), false));
	
	rep(i, q) {
		int a, l, r;
		scanf("%d%d%d", &a, &l, &r);
		a --; l --; r --; 
		int ocnt = gr[a].count();
		gr[a] ^= f[r + 1] ^ f[l];
		int ncnt = gr[a].count();
		
		erase_r(a, ocnt);
		insert_r(a, ncnt);
		if(ok.empty()) printf("-1\n");
		else gen_ans(ok.begin()->first, ok.begin()->second);
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 500010;
const int L = 500000;
pair<int, int> p[maxn];
int gid[maxn], nxt[maxn], f[maxn][21];
int Solve(int l, int r){
	if(f[l][0] >= r) return 1;
	else{
		int k = 0;
		while(f[l][k+1] < r) ++k;
		return Solve(f[l][k], r) + (1 << k);
	}
}
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &p[i].first, &p[i].second);
	sort(p + 1, p + 1 + n);
	int mx = -1, c = 0;
	for(int i = 0, j = 1; i <= L; ++i){
		if(i > mx) ++c;
		while(j <= n && p[j].first <= i){
			if(p[j].second > mx) mx = p[j].second;
			++j;
		}
		if(i > mx) gid[i] = 0;
		else gid[i] = c, nxt[i] = mx;
	}

	for(int i = L; i >= 0; --i)
		if(gid[i]){
			f[i][0] = nxt[i];
			for(int k = 1; k <= 20; ++k)
				f[i][k] = f[f[i][k-1]][k-1];
		}
	/*
	for(int i = 0; i <= L; ++i)
		printf("%d%c", nxt[i], " \n"[i==L]);
	for(int i = 0; i <= L; ++i)
		printf("%d%c", gid[i], " \n"[i==L]);
	for(int k = 1; k <= 4; ++k)
		for(int i = 0; i <= L; ++i)
			printf("%d%c", f[i][k], " \n"[i==L]);
	*/

	for(int i = 1; i <= m; ++i){
		int l, r; scanf("%d%d", &l, &r);
		if(gid[l] == 0 || gid[l] != gid[r]) printf("-1\n");
		else printf("%d\n", Solve(l, r));
	}

	return 0;
}
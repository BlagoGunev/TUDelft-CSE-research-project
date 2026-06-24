#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N=100010;
int n,m,ans,l,r;
int q[N];
int d[N];
int nxt[N];
bool f[N];
bool h[N];
vector<int> v[N];

int Find(int k) {
	if (nxt[k]!=k) nxt[k]=Find(nxt[k]);
	return nxt[k];
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) nxt[i] = i;
	for(int i = 1; i <= m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		int xx = Find(x), yy = Find(y);
		if (xx != yy) nxt[xx] = yy;
		++d[y];
	}
	ans = n;
	for(int i = 1; i <= n; i++) {
		int tmp = Find(i);
		if (!f[tmp]) {
			f[tmp] = true;
			--ans;
		}
	}
	memset(f,0,sizeof(f));
	for(int i = 1; i <= n; i++) 
		if (!d[i]) q[++r] = i;
	for (l = 1; l <= r; ++l) {
		h[q[l]]=true;
		for(int p = 0; p < v[q[l]].size(); p++) {
			--d[v[q[l]][p]];
			if (!d[v[q[l]][p]]) q[++r] = v[q[l]][p];
		}
	}
	for(int i = 1; i <= n; i++) if (!h[i]) {
		int tmp = Find(i);
		if (!f[tmp]) {
			f[tmp] = true;
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
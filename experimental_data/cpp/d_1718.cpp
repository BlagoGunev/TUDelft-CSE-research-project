#include<bits/stdc++.h>

#define rep(i,a,b) for (int i = (a); i <= (b); ++i)

#define drep(i,a,b) for (int i = (a); i >= (b); --i)

#define grep(i,u) for (int i = head[u],v = e[i].v; i; v = e[i = e[i].nxt].v)

#define LL long long 

#define il inline

#define pii pair<int,int>

#define pll pair<LL,LL>

#define mp make_pair

#define fi first

#define se second

using namespace std;

il LL read() {

	LL x = 0,y = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') y = -y; ch = getchar();}

	while (isdigit(ch)) {x = x*10+ch-'0'; ch = getchar();} return x*y;

}

namespace qiqi {

	const int N = 1e6+5,INF = 0x3f3f3f3f; int n,Q,a[N],fa[N],ch[N][2],v[N],m;

	struct Data {

		int l,r;

		il Data (int x = 0,int y = INF) {

			l = x; r = y;

		}

		il bool friend operator < (Data a,Data b) {

			return a.r < b.r;

		}

	} p[N];

	void dfs(int x) {

		rep(i,0,1) if (ch[x][i]) {

			p[ch[x][i]].r = min(p[ch[x][i]].r,p[x].r-1);

			dfs(ch[x][i]); p[x].l = max(p[x].l,p[ch[x][i]].l+1);

		}

	}

	il void imp() {

		while (Q--) {

			read(); puts("NO");

		}

	}

	struct Seg {

		#define ls (x<<1)

		#define rs (ls|1)

		int s[N*4]; pii mx[N*4];

		il void push_up(int x) {

			s[x] = s[ls]+s[rs];

			mx[x] = max(mp(mx[ls].fi+s[rs],mx[ls].se),mx[rs]);

		}

		void build(int x,int l,int r) {

			s[x] = 0; mx[x] = mp(0,l); if (l == r) return;

			int mid = l+((r-l)>>1); build(ls,l,mid); build(rs,mid+1,r);

		}

		void upd(int x,int l,int r,int p,int k) {

			if (l == r) {s[x] += k; mx[x].fi += k; return;} int mid = l+((r-l)>>1);

			p <= mid ? upd(ls,l,mid,p,k) : upd(rs,mid+1,r,p,k); push_up(x);

		}

	} seg;

	void main() {

		n = read(); Q = read(); rep(i,1,n) {

			fa[i] = 0; rep(j,0,1) ch[i][j] = 0;

		}

		rep(i,1,n) {

			a[i] = read();

			int x = i-1,y = 0;

			while (x && a[x] < a[i]) x = fa[y = x];

			if (x) {

				fa[ch[x][1] = i] = x;

			}

			if (y) {

				fa[ch[i][0] = y] = i;

			}

		}

		int x = 0;

		rep(i,1,n) {

			int k = read(); 

			if (k) {

				a[++x] = k; p[i] = Data(k,k);

			}

			else p[i] = Data();

		}

		rep(i,x+1,n-1) a[i] = read(); sort(a+1,a+n);

		x = n; while (fa[x]) x = fa[x]; dfs(x);

		rep(i,1,n) {

			if (p[i].l > p[i].r) {imp(); return;}

		}

		m = 0; rep(i,1,n-1) v[++m] = a[i];

		rep(i,1,n) {

			v[++m] = p[i].l; v[++m] = p[i].r;

		}

		sort(v+1,v+m+1); m = unique(v+1,v+m+1)-v-1;

		rep(i,1,n-1) {

			a[i] = upper_bound(v+1,v+m+1,a[i])-v-1;

		}

		rep(i,1,n) {

			p[i].l = upper_bound(v+1,v+m+1,p[i].l)-v-1;

			p[i].r = upper_bound(v+1,v+m+1,p[i].r)-v-1;

		}

		sort(p+1,p+n+1); Data mn;

		x = 0; seg.build(1,1,m);

		rep(i,1,n) {

			while (x < n-1 && a[x+1] <= p[i].r) {

				++x; seg.upd(1,1,m,a[x],-1);

			}

			seg.upd(1,1,m,p[i].l,1);

			pii k = seg.mx[1];

			if (k.fi > 0) {

				if (k.fi > 1) {

					imp(); return;

				}

				mn = Data(max(mn.l,v[k.se]),min(mn.r,v[p[i].r]));

			}

		}

		while (Q--) {

			int x = read();

			puts(x >= mn.l && x <= mn.r ? "YES" : "NO");

		}

	}

}

int main() {

	int T = read(); while (T--) qiqi::main(); return 0;

}
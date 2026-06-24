#include <bits/stdc++.h>
#define il inline
#define pb push_back
using namespace std;
mt19937 rnd(time(0));
bool A;
const int N = 5e5 + 5,INF = 2e9;
int n,k,q,s[N],siz[N],son[N],top[N],cnt[N],fa[N],pa[N],rt[N],id[N],ls[N],rs[N];
vector <int> v[N];
il int read()
{
	int x = 0,f = 0;
	char ch = getchar();
	while(!isdigit(ch)) (ch == '-' && (f = 1)),ch = getchar();
	while(isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0',ch = getchar();
	return (f ? -x : x);
}
il void write(int x,char t = 0)
{
	if(!x) putchar('0');
	else
	{
		int top = 0,f = 0;
		static char ch[35];
		if(x < 0) x = -x,f = 1;
		while(x) ch[++top] = x % 10 + '0',x /= 10;
		if(f) ch[++top] = '-';
		for(int i = top;i >= 1;i--) putchar(ch[i]);
	}
	if(t) putchar(t);
}
struct FHQ
{
	int tot,top,ls[N],rs[N],p[N],val[N],siz[N],st[N];
	int new_node(int x)
	{
		int ret = (top ? st[top--] : ++tot);
		val[ret] = x,p[ret] = rnd();
		siz[ret] = 1,ls[ret] = rs[ret] = 0;
		return ret;
	}
	void pushup(int x){siz[x] = siz[ls[x]] + siz[rs[x]] + 1;}
	void split(int x,int k,int &a,int &b)
	{
		if(!x)
		{
			a = b = 0;
			return ;
		}
		if(val[x] <= k) a = x,split(rs[x],k,rs[x],b);
		else b = x,split(ls[x],k,a,ls[x]);
		pushup(x);
	}
	int merge(int x,int y)
	{
		if(!x || !y) return x + y;
		int rt;
		if(p[x] > p[y]) rs[x] = merge(rs[x],y),rt = x;
		else ls[y] = merge(x,ls[y]),rt = y;
		pushup(rt);
		return rt;
	}
	void insert(int &x,int k)
	{
		int a,b;
		split(x,k,a,b);
		x = merge(merge(a,new_node(k)),b);
	}
	void erase(int &x,int k)
	{
		int a,b,c;
		split(x,k,a,c);
		split(a,k - 1,a,b);
		st[++top] = b,b = merge(ls[b],rs[b]);
		x = merge(merge(a,b),c);
	}
	int query(int &x,int k)
	{
		int a,b,ret;
		split(x,k,a,b);
		ret = siz[a],x = merge(a,b);
		return ret;
	}
	int find(int x,int k)
	{
		if(!x) return k + 1;
		int ret;
		if(val[x] + 2 * (siz[ls[x]] + 1) > k)
		{
			ret = val[x];
			if(ls[x]) ret = min(ret,find(ls[x],k));
		}
		else
		{
			ret = k - 2 * (siz[ls[x]] + 1) + 1;
			if(rs[x]) ret = min(ret,find(rs[x],k - 2 * (siz[ls[x]] + 1)));
		}
		return ret;
	}
} tr;
struct Func
{
	int k,a,b,c;
	il void init(int x){k = a = b = c = x;}
	il int calc(const int &x) const{return (x > k ? a : (x == k ? b : c));}
} f[N],h[N];
bool B; 
il Func operator + (const Func &x,const Func &y)
{
	Func ret = y;
	ret.a = x.calc(y.a),ret.b = x.calc(y.b),ret.c = x.calc(y.c);
	return ret;
}
void get_f(int x)
{
	int l = -n - 2,r = n + 2,mid;
	while(r - l > 1)
	{
		mid = ((l + r) >> 1);
		if(mid + 2 * tr.query(rt[x],mid) > cnt[x]) r = mid;
		else l = mid;
	}
	int k = r,dt,c,tmp;
	tmp = tr.query(rt[x],k);
	dt = k + 2 * tmp - cnt[x];
	c = tmp - tr.query(rt[x],k - 1);
	f[x].k = k,f[x].a = k + (dt == 1),f[x].b = k,f[x].c = k - (dt - 2 * c > 0);
}
void pushup(int x)
{	
	h[x] = f[x];
	if(rs[x]) h[x] = h[x] + h[rs[x]];
	if(ls[x]) h[x] = h[ls[x]] + h[x];
}
int build(int l,int r,vector <int> &p)
{
	if(l > r) return 0;
	int mid = ((l + r) >> 1),x = p[mid];
	ls[x] = build(l,mid - 1,p),rs[x] = build(mid + 1,r,p);
	if(ls[x]) pa[ls[x]] = x;
	if(rs[x]) pa[rs[x]] = x;
	pushup(x);
	return x;
}
void dfs1(int x,int lst)
{
	fa[x] = lst,siz[x] = 1;
	for(int y : v[x])
	{
		if(y == lst) continue;
		dfs1(y,x),siz[x] += siz[y];
		if(siz[y] > siz[son[x]]) son[x] = y;
		cnt[x]++;
	}
	if(cnt[x]) cnt[x]--;
}
void dfs2(int x)
{
	vector <int> p;
	for(int i = x;i;i = son[i]) p.pb(i);
	for(int i : p)
		for(int j : v[i])
		{
			if(j == fa[i] || j == son[i]) continue;
			dfs2(j);
			tr.insert(rt[i],h[id[j]].calc(0));
			pa[id[j]] = i;
		}
	for(int i : p)
		if(son[i]) get_f(i);
		else if(s[i]) f[i].init(n + 1);
		else f[i].init(-n - 1);
	id[x] = build(0,p.size() - 1,p);
	for(int i : p) top[i] = x;
}
void upd(int x,int y)
{
	if(y) f[x].init(n + 1);
	else f[x].init(-n - 1);
	while(x)
	{
		if(pa[x] && top[pa[x]] != top[x])
		{
			tr.erase(rt[pa[x]],h[x].calc(0));
			pushup(x);
			tr.insert(rt[pa[x]],h[x].calc(0));
			get_f(pa[x]);
		}
		else pushup(x);
		x = pa[x];
	}
}
int qry(int x)
{
	Func tmp = f[x];
	if(rs[x]) tmp = tmp + h[rs[x]];
	while(top[pa[x]] == top[x])
	{
		int t = (x == ls[pa[x]]);
		x = pa[x];
		if(t)
		{
			tmp = tmp + f[x];
			if(rs[x]) tmp = tmp + h[rs[x]];
		}
	}
	return tmp.calc(0);
}
int main()
{
//	cout << (&A - &B) / 1024 / 1024 << endl;
//	freopen("federation.in","r",stdin);
//	freopen("federation.out","w",stdout); 
	n = read(),k = read();
	for(int i = 1,a,b;i < n;i++)
	{
		a = read(),b = read();
		v[a].pb(b),v[b].pb(a); 
	}
	for(int i = 1;i <= n;i++) s[i] = read();
	dfs1(1,0),dfs2(1);
	q = read();
	for(int i = 1,op,x,y;i <= q;i++)
	{
		op = read(),x = read();
		if(op == 1)
		{
			putchar('0' + (k < qry(x)));
			putchar('\n');
		}
		else if(op == 2)
		{
			y = read();
			upd(x,y);
		}
		else k = x;
	}
	return 0; 
}
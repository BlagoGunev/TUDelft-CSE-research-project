#include<bits/stdc++.h>

#define R register

#define x first

#define y second

#define ll long long

#define db double

#define mp make_pair

#define pb push_back

#define pi pair<int,int>

#define lb(x) (x&-x)

#define all(x) x.begin(),x.end()

#define wt(x) write(x),puts("")

#define ot(x) write(x),putchar(' ')

#define rep(i,start,end) for(R int (i)=(start);(i)<=(end);i++)

#define per(i,end,start) for(R int (i)=(start);(i)>=(end);i--)

const int N=2e5+5,M=N<<5,P=998244353;

const ll INF=1e18;

using namespace std;

template<typename T> void read(T &x)

{

	int f=1;

	x=0;

	char c=getchar();

	while(!isdigit(c))

	{

		if(c=='-')

			f=-1;

		c=getchar();

	}

	while(isdigit(c))

	{

		x=(x<<3)+(x<<1)+c-'0';

		c=getchar();

	}

	x*=f;

}

void write(R ll x)

{

	if(x<0)

	{

		x=~x+1;

		putchar('-');

 	}

	if(x>9)

		write(x/10);

	putchar(x%10+'0');

}

int n,s,cur,f[N],vl[N],co[N];

vector<int> e[N];

char op[5];

namespace segment_tree

{

	#define mid (l+r>>1)

	int tot,rt[M],ls[M],rs[M];

	ll mn[M],tag[M];

	void add(int u,ll k)

	{

		tag[u]+=k,mn[u]+=k;

	}

	void pushdown(int u)

	{

		if(tag[u])

		{

			add(ls[u],tag[u]),add(rs[u],tag[u]);

			tag[u]=0;

		}

	}

	void modify(int &u,int l,int r,int p,ll k)

	{

		if(!u)

			u=++tot,mn[u]=INF;

		if(l==r)

			return mn[u]=k,void();

		pushdown(u);

		p<=mid?modify(ls[u],l,mid,p,k):modify(rs[u],mid+1,r,p,k);

		mn[u]=min(mn[ls[u]],mn[rs[u]]);

	}

	ll query(int u,int l,int r,int p)

	{

		if(!u)

			return INF;

		if(l==r)

			return mn[u];

		pushdown(u);

		return p<=mid?query(ls[u],l,mid,p):query(rs[u],mid+1,r,p);

	}

	void merge(int &u,int v,int l,int r)

	{

		if(!u||!v)

			return u+=v,void();

		mn[u]=min(mn[u],mn[v]);

		if(l==r)

			return;

		pushdown(u),pushdown(v);

		merge(ls[u],ls[v],l,mid),merge(rs[u],rs[v],mid+1,r);

	}

	void solve(int u)

	{

		modify(rt[u],0,2e5,vl[u],0);

		for(int v:e[u])

		{

			ll ad;

			if(~co[v])

			{

				add(rt[u],co[v]);

				if(vl[v]==s)

					continue;

				else

					modify(rt[u],0,2e5,vl[v],mn[rt[u]]-co[v]);

			}

			else if((ad=query(rt[u],0,2e5,vl[v]))!=INF)

			{

				solve(v),add(rt[v],ad);

				modify(rt[u],0,2e5,vl[v],query(rt[v],0,2e5,vl[v]));

				merge(rt[u],rt[v],0,2e5);

			}

		}

	}

}

using namespace segment_tree;

int main()

{

	read(n),read(s),mn[0]=INF;

	rep(i,1,n)

	{

		scanf("%s",op);

		if(op[0]=='s')

		{

			read(vl[i]),read(co[i]);

			e[cur].pb(i);

		}

		if(op[0]=='i')

		{

			read(vl[i]),co[i]=-1;

			e[cur].pb(i),f[i]=cur,cur=i;

		}

		if(op[0]=='e')

			cur=f[cur];

	}

	solve(0);

	wt(mn[rt[0]]);

	return 0;

}
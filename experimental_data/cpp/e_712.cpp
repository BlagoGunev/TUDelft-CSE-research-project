#include<iostream>

#include<cstdio>

#include<cstdlib>

using namespace std;



typedef long double ld;

#define maxn (400010)

int N,Q,A[maxn],B[maxn],lef[maxn]; ld g[maxn],f[maxn];

struct node { ld f,g; };



inline int gi()

{

	int f = 1,ret = 0; char ch;

	do ch = getchar(); while (!(ch >= '0'&&ch <= '9')&&ch != '-');

	if (ch == '-') f = -1,ch = getchar();

	do ret = ret*10+ch-'0',ch = getchar(); while (ch >= '0'&&ch <= '9');

	return f*ret;

}



inline void build(int now,int l,int r)

{

	if (l == r) { lef[l] = now; g[now] = f[now] = (ld)A[l]/(ld)B[l]; return; }

	int mid = (l+r)>>1;

	build(now<<1,l,mid); build(now<<1|1,mid+1,r);

	f[now] = (f[now<<1]*f[now<<1|1])/(1-g[now<<1]*(1-f[now<<1|1]));

	g[now] = g[now<<1|1]+(1-g[now<<1|1])*g[now<<1]*f[now<<1|1]/(1+(f[now<<1|1]-1)*g[now<<1]);

}



inline node query(int now,int l,int r,int ql,int qr)

{

	if (l == ql&&r == qr) return (node){ f[now],g[now] };

	int mid = (l+r)>>1;

	if (qr <= mid) return query(now<<1,l,mid,ql,qr);

	else if (ql > mid) return query(now<<1|1,mid+1,r,ql,qr);

	else

	{

		node a,b,ret;

		a = query(now<<1,l,mid,ql,mid); b = query(now<<1|1,mid+1,r,mid+1,qr);

		ret.f = (a.f*b.f)/(1-a.g*(1-b.f));

		ret.g = b.g+(1-b.g)*a.g*b.f/(1+(b.f-1)*a.g);

		return ret;

	}

}



int main()

{

	//freopen("E.in","r",stdin);

	//freopen("E.out","w",stdout);

	scanf("%d %d",&N,&Q);

	for (int i = 1;i <= N;++i) A[i] = gi(),B[i] = gi();

	build(1,1,N);

	while (Q--)

	{

		int opt = gi();

		if (opt == 1)

		{

			int now = lef[gi()],a = gi(),b = gi(); 

			f[now] = g[now] = (ld)a/(ld)b;

			for (now >>= 1;now;now >>= 1)

			{

				f[now] = (f[now<<1]*f[now<<1|1])/(1-g[now<<1]*(1-f[now<<1|1]));

				g[now] = g[now<<1|1]+(1-g[now<<1|1])*g[now<<1]*f[now<<1|1]/(1+(f[now<<1|1]-1)*g[now<<1]);

			}

		}

		else

		{

			int l = gi(),r = gi();

			printf("%.10lf\n",(double)query(1,1,N,l,r).f);

		}

	}

	//fclose(stdin); fclose(stdout);

	return 0;

}
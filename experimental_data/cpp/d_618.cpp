/*

                ____________    ______________       __

               / _________  /\ /_____   _____/\     / /\

              / /\       / /  \\    /  /\    \ \   / /  \

             / /  \_____/ /   / \__/  /  \____\/  / /   /

            / /   /    / /   /    /  /   /       / /   /

           / /   /    / /   /    /  /   /       / /   /

          / /   /    / /   /    /  /   /       / /   /

         / /___/____/ /   /    /  /   /       / /___/________

        /____________/   /    /__/   /       /______________/\

        \            \  /     \  \  /        \              \ \

         \____________\/       \__\/          \______________\/

           ___       ___               ___    __________

          /  /\     /  /\             /  /\  /_______  /\

         /  /__\___/  /  \           /  /  \ \      /  /  \

        /____    ____/   /          /  /   /  \____/  /   /

        \   /   /\   \  /          /  /   /       /  /   /

         \_/   /  \___\/ ___      /  /   /       /  /   /

          /   /   /     /  /\    /  /   /       /  /   /

         /   /   /     /  /__\__/  /   /       /  /___/____

        /___/   /     /___________/   /       /___________/\

        \   \  /      \           \  /        \           \ \

         \___\/        \___________\/          \___________\/

       

          A FAN OF FIZZYDAVID

           

*/



#include<bits/stdc++.h>



#define HEAP priority_queue

#define rep(i,n) for(int i=0;i<(n);i++)

#define per(i,n) for(int i=(n)-1;i>=0;i--)

#define forn(i,l,r) for(int i=(l);i<=(r);i++)

#define nrof(i,r,l) for(int i=(r);i>=(l);i--)

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define mp make_pair

#define pb push_back

#define X first

#define Y second

#define eps 1e-20

#define pi 3.1415926535897932384626433832795

#define orz int

#define yjz main

#define fizzydavid return

#define ak 0

#define la ;

#define debug puts("OK");

#define SZ(x) (int)x.size()

#define ALL(x) x.begin(),x.end()

#define foreach(i,u) for(int i=head[(u)];i;i=e[(i)].nxt)



using namespace std;



typedef long long LL;

typedef double flt;

typedef vector<int> vi;

typedef pair<int,int> pii;



const int iinf=1e9+7;

const LL linf=1ll<<60;

const flt dinf=1e10;



void scf(int &x)

{

	bool f=0; x=0; char c=getchar();

	while((c<'0' || c>'9') && c!='-') c=getchar();

	if(c=='-') { f=1; c=getchar(); }

	while(c>='0' && c<='9') { x=x*10+c-'0';   c=getchar(); }

	if(f) x=-x; return;

}



void scf(int &x,int &y) { scf(x); return scf(y); }



void scf(int &x,int &y,int &z) { scf(x); scf(y); return scf(z); }



//---------------------------head----------------------------



const int N=2e5+100;



struct edge

{

	int to,nxt;

	edge () {}

	edge (int t,int n){ to=t; nxt=n; }

}e[N<<1];



int head[N],etot;

int n;

LL x,y;

int dp[N][3],cst[N],mx[N];



inline void add_edge(int u,int v)

{

	etot++; e[etot]=edge(v,head[u]); head[u]=etot;

	etot++; e[etot]=edge(u,head[v]); head[v]=etot;

	return;

}



inline int MAX(int a,int b){ return a>b?a:b; }

inline int MAX(int a,int b,int c){ return MAX(MAX(a,b),c); }



inline void dfs(int u=1,int f=0)

{

	int m1,m2;

	m1=m2=iinf;

	foreach(i,u)

	{

		int v=e[i].to;

		if(v==f) continue;

		dfs(v,u);

		dp[u][0]+=mx[v];

		if(cst[v]<m1) m2=m1, m1=cst[v];

		else if(cst[v]<m2) m2=cst[v];

	}

	if(m1!=iinf)

	{

		dp[u][1]=dp[u][0]-m1+1;

		if(m2!=iinf) dp[u][2]=dp[u][1]-m2+1;

	}

	mx[u]=MAX(dp[u][0],dp[u][1],dp[u][2]);

	cst[u]=mx[u]-MAX(dp[u][0],dp[u][1]);

	return;

}



orz yjz()

{

	scf(n); scanf("%I64d%I64d",&x,&y);

	rep(i,n-1){ int u,v; scf(u,v); add_edge(u,v); }

	if(x>=y)

	{

		forn(u,1,n)

		{

			int cnt=0;

			foreach(i,u) cnt++;

			if(cnt==n-1){ printf("%I64d\n",y*(LL)(n-2)+x); fizzydavid ak la }

		}

		printf("%I64d\n",y*(LL)(n-1));

		fizzydavid ak la

	}

	dfs();

	printf("%I64d\n",(LL)mx[1]*x+(LL)(n-1-mx[1])*y);

	fizzydavid ak la

}
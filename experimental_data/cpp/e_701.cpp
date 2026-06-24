/* ***********************************************

┆  ┏┓　　　┏┓ ┆

┆┏┛┻━━━┛┻┓ ┆

┆┃　　　　　　　┃ ┆

┆┃　　　━　　　┃ ┆

┆┃　┳┛　┗┳　┃ ┆

┆┃　　　　　　　┃ ┆

┆┃　　　┻　　　┃ ┆

┆┗━┓　马　┏━┛ ┆

┆　　┃　勒　┃　　┆　　　　　　

┆　　┃　戈　┗━━━┓ ┆

┆　　┃　壁　　　　　┣┓┆

┆　　┃　的草泥马　　┏┛┆

┆　　┗┓┓┏━┳┓┏┛ ┆

┆　　　┃┫┫　┃┫┫ ┆

┆　　　┗┻┛　┗┻┛ ┆

************************************************ */



#include <stdio.h>

#include <string.h>

#include <iostream>

#include <algorithm>

#include <vector>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <string>

#include <math.h>

#include <stdlib.h>

#include <bitset>

using namespace std;



#define rep(i,a,b) for (int i=(a),_ed=(b);i<=_ed;i++)

#define per(i,a,b) for (int i=(b),_ed=(a);i>=_ed;i--)

#define pb push_back

#define mp make_pair

const int inf_int = 2e9;

const long long inf_ll = 2e18;

#define inf_add 0x3f3f3f3f

#define mod 1000000007

#define LL long long

#define ULL unsigned long long

#define MS0(X) memset((X), 0, sizeof((X)))

#define SelfType int

SelfType Gcd(SelfType p,SelfType q){return q==0?p:Gcd(q,p%q);}

SelfType Pow(SelfType p,SelfType q){SelfType ans=1;while(q){if(q&1)ans=ans*p;p=p*p;q>>=1;}return ans;}

#define Sd(X) int (X); scanf("%d", &X)

#define Sdd(X, Y) int X, Y; scanf("%d%d", &X, &Y)

#define Sddd(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())

#define all(a) a.begin(), a.end()

typedef pair<int, int> pii;

typedef pair<long long, long long> pll;

typedef vector<int> vi;

typedef vector<long long> vll;

inline int read(){int ra,fh;char rx;rx=getchar(),ra=0,fh=1;while((rx<'0'||rx>'9')&&rx!='-')rx=getchar();if(rx=='-')fh=-1,rx=getchar();while(rx>='0'&&rx<='9')ra*=10,ra+=rx-48,rx=getchar();return ra*fh;}

//#pragma comment(linker, "/STACK:102400000,102400000")



const int N = 2e5 +5;



struct Edge

{

    int to,nx;

}edge[N*2];



int vis[N],head[N],cnt;



void addedge(int u,int v)

{

    edge[cnt] = Edge{v,head[u]};

    head[u] = cnt++;

}



int son[N];

LL ans;

int n,k;



void dfs(int u,int fa)

{

    if(vis[u])son[u] = 1;

    for(int i=head[u];i;i=edge[i].nx)

    {

        int v = edge[i].to;

        if(v==fa)continue;

        dfs(v,u);

        son[u] += son[v];

    }

    ans += min(son[u],2*k-son[u]);

}





int main()

{

	//freopen("in.txt","r",stdin);

	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(0);

	cin.tie(0);

	n = read(), k = read();

	for(int i=1;i<=2*k;i++)

    {

        int x = read();

        vis[x] = 1;

    }

    cnt = 1;

    for(int i=1;i<n;i++)

    {

        int u,v;

        u = read(), v = read();

        addedge(u,v);

        addedge(v,u);

    }

	dfs(1,-1);

	printf("%I64d\n",ans);



	return 0;

}
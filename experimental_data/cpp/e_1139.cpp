#pragma GCC optimmize(3)
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 5010
#define M 
using namespace std;

int n,m,Q,an,que[N],pos[N],num[N],ans[N],pp[N];
bool have[N][N],gg[N],use[N];
vector<int>to[N];

inline void in(int u)
{
	if(!have[pos[u]][num[u]])
	{
		have[pos[u]][num[u]]=1;
//		cerr<<" "<<num[u]<<" "<<pos[u]<<endl;
		to[num[u]].push_back(pos[u]);
	}
}

bool dfs(int now)
{
	int i,t;
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i];
		if(use[t]) continue;
		use[t]=1;
		if(pp[t]==-1 || dfs(pp[t]))
		{
			pp[t]=now;
			return 1;
		}
	}
	return 0;
}

inline void calc()
{
	for(;;an++)
	{
		memset(use,0,sizeof(use));
		if(!dfs(an)) return;
	}
}

int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	memset(pp,-1,sizeof(pp));
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	for(i=1;i<=n;i++) scanf("%d",&pos[i]);
	cin>>Q;
	for(i=1;i<=Q;i++) scanf("%d",&que[i]),gg[que[i]]=1;
	for(i=1;i<=n;i++) if(!gg[i]) in(i);
	for(i=Q;i>=1;i--)
	{
		calc();
		ans[i]=an;
		in(que[i]);
	}
	for(i=1;i<=Q;i++) printf("%d\n",ans[i]);
}
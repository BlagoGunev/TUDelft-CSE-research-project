#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int T,cc,u[500010],v[500010];
int n,m,nxt[4100005],head[2000005],k=1,cnt,go[4100005],dfn[2000005],low[2000005],ans;
vector<int> dcc[500005];int bl[200010],is[200010];
void add(int x,int y)
{
	nxt[++k]=head[x];
	head[x]=k;
	go[k]=y;
}
int up,tot;
stack<int>sta;
vector<int>e[N];
void tarjan(int x,int edge)
{
	dfn[x]=low[x]=++cnt;
	if(x<=n)up++;
	sta.push(x);
	for(int i=head[x];i;i=nxt[i])
	{
		int g=go[i];
		if(!dfn[g])
		{
			tarjan(g,i);
			low[x]=min(low[x],low[g]);
			if(low[g]>dfn[x])
			{
				ans++;
				is[ans]=tot;
				int p;
				do{
					p=sta.top();
					sta.pop();
					dcc[ans].push_back(p);
					bl[p]=ans;
				}while(p!=g);
			}
		}
		else if(i!=(edge^1))
		low[x]=min(low[x],dfn[g]);
	}
}
int gp[200010],js[N*2];
set<int>sz[200010];
void dfs(int x,int fa){
    js[x]=dcc[x].size();
    for(auto v:e[x])if(v!=fa){
        dfs(v,x);
        js[x]+=js[v];
    }
    sz[is[x]].insert(js[x]);
    sz[is[x]].insert(gp[is[x]]-js[x]);
    return;
}
bitset<N/2>ans1,ans2;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&cc);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
            if(u[i]==v[i]) continue;
            add(u[i],v[i]);
            add(v[i],u[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(!dfn[i])
            {
                up=0;tot++;
                add(i+n,i);
                tarjan(i+n,0);
                gp[tot]=up;
            }
        }
        for(int i=1;i<=m;i++)
            if(bl[u[i]]!=bl[v[i]]){
                e[bl[u[i]]].push_back(bl[v[i]]);
                e[bl[v[i]]].push_back(bl[u[i]]);
            }
        for(int i=1;i<=ans;i++)
            if(!js[i])dfs(i,0);
        ans1.reset();
        ans2.reset();
        ans1[0]=1;
        ans2[0]=1;
        for(int i=1;i<=tot;i++){
            ans2|=(ans2<<gp[i]);
            for(auto h:sz[i])
                if(h)ans2|=(ans1<<h);
            ans1|=(ans1<<gp[i]);
        }
        long long ot=1ll*n*n*2;
        for(int i=0;i<=min(n,N/2);i++)
            if(ans1[i]||ans2[i])
                ot=min(ot,1ll*i*i+1ll*(n-i)*(n-i));
        ot=ot+1ll*cc*(tot-1);
        if(tot==1&&sz[1].size()==2)printf("-1\n");
        else   printf("%lld\n",ot);
        for(int i=1;i<=ans;i++)
            dcc[i].clear();
        for(int i=1;i<=2*n;i++)
            head[i]=low[i]=dfn[i]=0;
        for(int i=1;i<=k;i++)
            go[i]=nxt[i]=0;
        while(!sta.empty())sta.pop();
        k=1;cnt=ans=0;
        for(int i=1;i<=tot;i++){
            gp[i]=0;
            sz[i].clear();
        }for(int i=1;i<=n;i++)
            e[i].clear(),js[i]=bl[i]=is[i]=0;
        tot=0;
    }
    return 0;
}
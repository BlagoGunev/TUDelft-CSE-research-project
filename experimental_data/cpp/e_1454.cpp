#include<iostream>
using namespace std;

const int N=2e5+10;
int T,n,tot,num,num1,num2[N],first[N],to[N*2],nxt[N*2],po[N],fa[N];
long long ans,w1,w2,sum;
bool check,bj[N];


void create(int x,int y)
{
    tot++;
    nxt[tot]=first[x];
    first[x]=tot;
    to[tot]=y;
}

int get_fa(int x)
{
	if(fa[x]!=x) fa[x]=get_fa(fa[x]);
	return fa[x];
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        first[i]=0;
        bj[i]=false;
        num2[i]=0;
    }
    ans=0;sum=0;num=0;num1=0;
    tot=0;check=false;
}

void dfs1(int u,int v,int dep)
{
    bj[u]=true;
    if(u==v)
    {
        bj[v]=true;
        po[dep]=v;
        check=true;
        num=dep;
        return;
    }
    for(int e=first[u];e;e=nxt[e])
    {
        int s=to[e];
        if(bj[s]==false)
        {
            dfs1(s,v,dep+1);
            if(check==true) break;
        }
    }
    po[dep]=u;
    if(check==false) bj[u]=false;
}


void dfs2(int u)
{
    bj[u]=true;
    for(int e=first[u];e;e=nxt[e])
    {
        int v=to[e];
        if(bj[v]==false)
        {
            num1++;
            dfs2(v);
        }
    }
}


int main()
{
    int x,y,fx,fy,u,v;
   // freopen("lx.in","r",stdin);

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            fx=get_fa(x);
            fy=get_fa(y);
            if(fx!=fy)
            {
                fa[fx]=fy;
                create(x,y);
                create(y,x);
            }
            else
            {
                u=x;
                v=y;
            }
        }
        dfs1(u,v,1);
        for(int i=1;i<=num;i++)
        {
            num1=0;
            dfs2(po[i]);
            num2[i]=num1;
        }
        w1=n;w2=num;
        ans+=w1*(w1-1)/2+w2*(w2-1)/2;
        for(int i=1;i<=num;i++)
        {
            w1=num2[i];w2=num-1;
            ans+=w1*w2;
            w2=n-num2[i]-num;
            sum+=w1*w2;
        }
        ans+=sum/2;
        printf("%lld\n",ans);
        clear();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long T,a,b,d[1000001],an,dp[1000001],st[1000001],cn,L,ls[1000001],idd[1000001],g[1000001],h[1000001],dp1[1000001],inf=5e15,cnn,stt[1000001];
struct p{long long q,w;};
vector<int> ve[1000001];
vector<int> solve(int md,vector<p> &qq)
{
    int tt=qq.size();
    for(int i=0;i<tt;i++)
    {
        for(int j=qq[i].q;j<=qq[i].w;j++) dp[j]=1e16;
    }
    dp[md]=d[md];cn=0;L=1,st[++cn]=md;ls[md]=0;
    idd[md]=0;
    for(int i=0;i<tt;i++)
    {
        ve[i].resize(qq[i].w-qq[i].q+1);
        for(int j=0;j<ve[i].size();j++) ve[i][j]=0;
    }
    for(int i=1;i<tt;i++)
    {
        cn=0;L=1;
        for(int j=qq[i-1].q;j<=qq[i-1].w;j++)
        {
            dp1[j]=dp[j],dp[j]=1e16;
            while(cn>=L&&dp1[j]<=dp1[st[cn]]) --cn;
            st[++cn]=j;
        }
        for(int j=qq[i].q;j<=qq[i].w;j++)
        {
            while(L<=cn&&st[L]<j-b) ++L;
            if(L>cn)
            {
                ve[i][j-qq[i].q]=0;dp[j]=1e16;
                continue;
            }
            dp[j]=dp1[st[L]]+d[j];
            ve[i][j-qq[i].q]=st[L];
        }
    }
    long long ann=1e16,id=0;
    for(int i=qq[tt-1].q;i<=qq[tt-1].w;i++)
    {
        if(dp[i]<ann&&i>=a+md-b)
        {
            ann=dp[i],id=i;
        }
    }
    vector<int> Tmp;
    if(!id||ann>inf) return Tmp;
    long long hh=id,yy=tt-1;
    cn=0;
    while(hh)
    {
        st[++cn]=hh;
        hh=ve[yy][hh-qq[yy].q];
        --yy;
    }an=min(an,ann);
    for(int i=1;i<=cn/2;i++) swap(st[i],st[cn-i+1]);
    for(int i=1;i<=cn;i++) Tmp.push_back(st[i]);
    return Tmp;
}
void work(vector<p> &qq)
{
    for(int i=0;i<qq.size();i++)
    {
        if(qq[i].q>qq[i].w) return;
    }
    int tt=qq.size();
    int md=(qq[0].q+qq[0].w)/2;
    vector<int> mdd=solve(md,qq);
    if(mdd.size()==0) return;
    vector<p> tmp1,tmp2;
    for(int i=0;i<tt;i++)
    {
        if(i==0)
        {
            tmp1.push_back(p{qq[i].q,mdd[i]-1});
            tmp2.push_back(p{mdd[i]+1,qq[i].w});
        }
        else
        {
            tmp1.push_back(p{qq[i].q,mdd[i]});
            tmp2.push_back(p{mdd[i],qq[i].w});
        }
    }
    work(tmp1),work(tmp2);
}
vector<p> tmp;
int main()
{
    scanf("%lld",&T);
    for(int ii=1;ii<=T;ii++)
    {
        scanf("%lld%lld",&a,&b);
        for(int i=1;i<=a;i++) scanf("%lld",&d[i]);
        for(int i=0;i<=a+1;i++) dp[i]=1e16,ls[i]=0,g[i]=1e16;d[a+1]=0;
        dp[1]=d[1];
        cn=0;L=1;st[++cn]=1;
        for(int i=2;i<=a;i++)
        {
            while(L<=cn&&st[L]<i-b) ++L;
            dp[i]=dp[st[L]]+d[i];
            ls[i]=st[L];idd[i]=idd[st[L]]+1;
            while(cn>=L&&dp[i]<=dp[st[cn]]) --cn;
            st[++cn]=i;
        }
        long long ff=ls[a+1],id=a;
        an=1e16;
        for(int i=a-b+1;i<=a;i++)
        {
            if(dp[i]<an)
            {
                an=dp[i];
                id=i;
            }
        }
        cn=0;ff=id;
        while(ff)
        {
            st[++cn]=ff;ff=ls[ff];
        }
        for(int i=1;i<=cn/2;i++) swap(st[i],st[cn-i+1]);
        tmp.clear();
        st[cn+1]=a;
        cnn=cn;
        for(int i=1;i<=cnn+1;i++) stt[i]=st[i];
        for(int i=1;i<=cn;i++)
        {
            tmp.push_back(p{st[i],st[i+1]});
        }
        work(tmp);
        tmp.clear();
        tmp.push_back(p{1,1});
        for(int i=1;i<=cnn;i++) tmp.push_back(p{stt[i],stt[i+1]});
        vector<int> tmp1=solve(1,tmp);
        if(tmp1.size()>0)
        {
            tmp.clear();tmp1.push_back(a);
            for(int i=0;i+1<tmp1.size();i++) tmp.push_back(p{tmp1[i],tmp1[i+1]});
            work(tmp);
        }
        tmp.clear();stt[cnn]=a;
        for(int i=1;i<cnn;i++) tmp.push_back(p{stt[i],stt[i+1]});
        if(tmp.size()>0)
        {
            tmp1=solve(1,tmp);
            if(tmp1.size()>0)
            {
                tmp.clear();tmp1.push_back(a);
                for(int i=0;i+1<tmp1.size();i++) tmp.push_back(p{tmp1[i],tmp1[i+1]});
                work(tmp);
            }
        }
        printf("%lld\n",an);
    }
    return 0;
}
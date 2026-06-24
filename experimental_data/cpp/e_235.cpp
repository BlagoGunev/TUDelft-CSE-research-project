#include<cstdio>

#include<iostream>

#include<cstring>

#include<vector>

using namespace std;

const int N=2005;

const int mod=1073741824;

typedef long long ll;

vector<int>g[N];

int dp[N][N];

int gcd(int a,int b)

{

    if(b==0) return a;

    if(dp[a][b]!=-1) return dp[a][b];

    return dp[a][b]=gcd(b,a%b);

}

int mb[N];

int pri[N],tot=0;

bool vis[N];

void init()

{

    memset(vis,false,sizeof vis);

    mb[1]=1;

    for(int i=2;i<N;i++)

    {

        if(!vis[i]) {

            pri[tot++]=i;

            mb[i]=-1;

        }

        for(int j=0;j<tot && i*pri[j]<N;j++)

        {

            vis[i*pri[j]]=true;

            if(i%pri[j]) mb[i*pri[j]]=-mb[i];

            else {

                mb[i*pri[j]]=0;

                break;

            }

        }

    }

    memset(dp,-1,sizeof dp);

    for(int i=1;i<N;i++)

    {

        for(int j=1;j<N;j++)

            if(gcd(i,j)==1) g[i].push_back(j);

    }

}

int main()

{

    int a,b,c;

    init();

    scanf("%d%d%d",&a,&b,&c);

    ll ans=0;

    int up=min(b,c);

    for(int i=1;i<=a;i++)

    {

        int n=g[i].size();

        ll sum=0;

        for(int ii=0;ii<n && g[i][ii]<=up;ii++)

        {

            int d=g[i][ii];

            if(mb[d]==0) continue;

            ll t1=0;

            int up1=b/d;

            ll tmp=mb[d];

            for(int jj=0;jj<n && g[i][jj]<=up1;jj++)

                t1=(t1+up1/g[i][jj])%mod;

            tmp=tmp*t1%mod;

            int up2=c/d;

            ll t2=0;

            for(int kk=0;kk<n && g[i][kk]<=up2;kk++)

                t2=(t2+up2/g[i][kk])%mod;

            tmp=tmp*t2%mod;

            sum=(sum+tmp)%mod;

        }

        ans=(ans+a/i*sum)%mod;

    }

    printf("%I64d\n",ans);

    return 0;

}
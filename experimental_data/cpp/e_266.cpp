#include<algorithm>

#include<cmath>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<ctime>

#include<deque>

#include<iterator>

#include<iostream>

#include<list>

#include<map>

#include<memory>

#include<queue>

#include<set>

#include<stack>

#include<string>

#include<vector>

#include<utility>

#include<bitset>

#define ll long long

const int N=100005;

const int P=1000000007;

using namespace std;



ll Pow[N][6],sum[N][6];

int a[N];

struct st{

       ll t[N*4],lazy[N*4];

       int w;

       void init(){

            memset(lazy,-1,sizeof(lazy));

       }

       void build(int k,int l,int r){

            if(r-l==1) {t[k]=1LL*(ll)a[l]*Pow[l][w]%P;return;}

            int m=(l+r)>>1;

            build(k*2,l,m);

            build(k*2+1,m,r);

            t[k]=(t[k*2]+t[k*2+1])%P;

       }

       

       void Push(int k,int l,int r){

            if(r<=l) return;

            int m=(l+r)>>1;

            lazy[k*2]=lazy[k];

            lazy[k*2+1]=lazy[k];

            t[k*2]=1LL*lazy[k]*(sum[m-1][w]-sum[l-1][w]+P)%P;

            t[k*2+1]=1LL*lazy[k]*(sum[r-1][w]-sum[m-1][w]+P)%P;

            lazy[k]=-1;

       }

       

       void update(int k,int l,int r,int a,int b,ll x){

            //cout<<k<<' '<<l<<' '<<r<<' '<<a<<' '<<b<<' '<<x<<endl;

            if(a>=r || b<=l) return;

            if(a<=l && b>=r)

            {  lazy[k]=x;t[k]=1LL*x*(sum[r-1][w]-sum[l-1][w]+P)%P;return;}

            if(lazy[k]!=-1) Push(k,l,r);

            int m=l+r>>1;

            update(k*2,l,m,a,b,x);

            update(k*2+1,m,r,a,b,x);

            t[k]=(t[k*2+1]+t[k*2])%P;

       }

       ll query(int k,int l,int r,int a,int b){

           //cout<<k<<' '<<l<<' '<<r;system("pause");

            if(a>=r || b<=l) return 0;

            if(a<=l && b>=r) return t[k];

            if(lazy[k]!=-1) Push(k,l,r);

            ll res=0;

            res=(res+query(k*2,l,(l+r)>>1,a,b))%P;

            res=(res+query(k*2+1,(l+r)>>1,r,a,b))%P;

            return res;

       }

}T[6];



int c[6][6];

int main(){

    int i,j;

    c[0][0]=1;

    for(i=1;i<=5;i++)

    {   c[i][0]=c[i][i]=1;

        for(j=1;j<i;j++)

            c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;

    }    

    int n,m;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)

    {   Pow[i][0]=1;

        sum[i][0]=i;

    }

    for(i=1;i<=5;i++)

        for(j=1;j<=n;j++)

        {  Pow[j][i]=1LL*Pow[j][i-1]*(ll)j%P;

           sum[j][i]=(sum[j-1][i]+Pow[j][i])%P;

        }

    for(i=1;i<=n;i++)

        scanf("%d",&a[i]);

    for(i=0;i<=5;i++)

    {   T[i].w=i;

        T[i].init();

        T[i].build(1,1,n+1);

    }

    

    while(m--)

    {  int l,r,k;

       char ch;

       ch=getchar();

       while(!(ch=='?' || ch=='=')) ch=getchar();

       scanf("%d%d%d",&l,&r,&k);

       if(ch=='=')

       {  for(i=0;i<=5;i++)

          {   T[i].update(1,1,n+1,l,r+1,(ll)k);//for(j=1;j<=2*n-1;j++) cout<<T[i].t[j]<<' ';cout<<endl;

          }

       }

       else

       {  ll ans=0,pw=1;

          for(i=0;i<=k;i++)

          {   ans=ans+1LL*c[k][i]*pw%P*T[k-i].query(1,1,n+1,l,r+1)%P;

              ans%=P;//cout<<T[k-i].query(1,1,n+1,l,r+1)%P<<endl;

              pw=1LL*pw*(ll)(1-l+P)%P;//cout<<pw<<endl;//<<' '<<ans;

              //ans+=c[k][i]*pw*T[k-i].query(1,1,n+1,l,r+1);

              //pw*=(1-l);cout<<ans<<endl;

          }

          printf("%I64d\n",ans);

       }

    }

    //system("pause");

    return 0;

}
#include<bits/stdc++.h>

#define ll long long

using namespace std;



int a[100010];

int p[100010];

int c[100010];

int sum[100010];

void add(int x,int v)

{

    while(x<=5000)

    {

        c[x]+=v;

        x+=x&-x;

    }

}

int get(int x)

{

    int res=0;

    while(x)

    {

        res+=c[x];

        x-=x&-x;

    }

    return res;

}

void solve()

{

    int n;

    cin>>n;

    ll ans=0;

    for(int i=1;i<=n;i++) c[i]=0;

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=n;i>=1;i--)

    {

        p[i]=get(a[i]);

        add(a[i],1);

    }

    for(int i=2;i<=n;i++)

    {

        for(int j=1;j<i;j++)

        {

            if(a[j]>a[i])p[j]--;

        }

    

        for(int j=1;j<i;j++) sum[j]=sum[j-1]+p[j];

        for(int j=1;j<i;j++)

        {

            if(a[j]<a[i]) ans+=-sum[j]+sum[i-1];

        }

     } 

     cout<<ans<<'\n';

    //for(int i=1;i<=n;i++)

}



int main()

{

    int t;

    cin>>t;

    while(t--) solve();

}
#include<bits/stdc++.h>



using namespace std;



typedef long long ll;



char s[15];

int n,m,k;

int a[15][105];

int b[15][105];

int c[15][105];



pair<int,int> t[105];

int sell(int x,int y)

{

    int k=::k,res=0;

    for(int i=0;i<m;i++)

    {

        t[i]={b[y][i]-a[x][i],c[x][i]};

    }

    sort(t,t+m,greater<pair<int,int> >());

    for(int i=0;i<m&&k>0;i++)

    {

        if(t[i].first<0)break;

        int z=min(k,t[i].second);

        res+=z*t[i].first;

        k-=z;

    }

    return res;

}

int main()

{

    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<n;i++)

    {

        scanf("%s",s);

        for(int j=0;j<m;j++)

        {

            scanf("%d%d%d",&a[i][j],&b[i][j],&c[i][j]);



        }

    }

    int ans=0;

    for(int i=0;i<n;i++)

        for(int j=i+1;j<n;j++)

    {

        ans=max(ans,sell(i,j));

        ans=max(ans,sell(j,i));

    }

    printf("%d\n",ans);

}
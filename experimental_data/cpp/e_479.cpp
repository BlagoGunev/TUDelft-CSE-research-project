#include<cstdio>

#include<cstdlib>

#include<cmath>

#include<algorithm>

#include<string>

#include<cstring>

#include<iostream>

#include<limits.h>

#define min(a,b) ((a)<(b)?(a):(b))

#define max(a,b) ((a)>(b)?(a):(b))

#define abs(a) ((a)<0?-(a):(a))

using namespace std;

const int moder=1000000007;

int f[5005][5005];

int n,k,a,b;

int ans=0;

void mod(int& k) {if(k>moder) k-=moder;}

void cul(int& k) {if(k<0) k+=moder;}

int main()

{

    //freopen("data.in","r",stdin);

    //freopen("data.out","w",stdout);

    scanf("%d%d%d%d",&n,&a,&b,&k);

    f[0][a]=1;

    for(int i=1;i<=k;i++)

    {

        int pos=0;

        int sum=0;

        if(a<b)

        {

            for(int j=1;j*2<1+b;j++) sum+=f[i-1][j],mod(sum),pos=j;

            for(int j=1;j<b;j++)

            {

                if((pos+1)*2<j+b) pos++,sum+=f[i-1][pos],mod(sum);

                f[i][j]=sum;

                if(f[i][j]) f[i][j]-=f[i-1][j],cul(f[i][j]);

            }

        }

        else

        {

            for(int j=n;j*2>n+b;j--) sum+=f[i-1][j],mod(sum),pos=j;

            for(int j=n;j>b;j--)

            {

                if((pos-1)*2>j+b) pos--,sum+=f[i-1][pos],mod(sum);

                f[i][j]=sum;

                if(f[i][j]) f[i][j]-=f[i-1][j],cul(f[i][j]);

            }

        }

    }

    for(int i=1;i<=n;i++)

    {

        ans+=f[k][i];

        if(ans>=moder) ans-=moder;

    }

    /*

    for(int i=0;i<=k;i++)

    {

        for(int j=1;j<=n;j++) printf("%d ",f[i][j]);

        cout<<endl;

    }*/

    printf("%d",ans);

    //fclose(stdin);

    //fclose(stdout);

    return 0;

}
#include<stdio.h>

int S[1010][2020];
int D[1010][2020];

int s(int n,int k);
int d(int n,int k);

int main()
{
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=2*i;j++)
        {
            S[i][j]=-1;
            D[i][j]=-1;
        }
    }
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",(s(x,y)+d(x,y))%998244353);
}

int s(int n,int k)
{

    if(k==0)return 0;
    if(k>2*n)return 0;
    if(k==1)return 2;

    if(S[n][k]!=-1)return S[n][k];
    return S[n][k]=((s(n-1,k)+s(n-1,k-1))%998244353+2*d(n-1,k)%998244353)%998244353;
}

int d(int n,int k)
{
    if(k==0)return 0;
    if(k>2*n)return 0;
    if(k==2*n)return 2;

    if(D[n][k]!=-1)return D[n][k];
    return D[n][k]=((d(n-1,k)+d(n-1,k-2))%998244353+2*s(n-1,k-1)%998244353)%998244353;
}
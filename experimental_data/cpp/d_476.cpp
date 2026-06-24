#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mod 1000000007
#define bitcount    __builtin_popcountll
#define pb push_back
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k,i,j,m;
    sd(n);
    sd(k);
    m=(6*(n-1)+5)*k;
    printf("%d\n",m);
    for(i=0;i<n;i++)
    {
    	j=6*i*k;
    	printf("%d %d %d %d\n",j+k,j+2*k,j+3*k,j+5*k);
    }
    return 0;
}
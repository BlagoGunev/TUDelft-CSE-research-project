#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int ncr(int n, int r)
{
    int C[r+1]={0};
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
int main()
{
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,q;
    cin>>n>>m>>k;
    a=ncr(n-1,k);
    for(i=0;i<k;i++){
        a*=(m-1);a%=p;
    }
    a*=m;
    a%=p;
    cout<<a<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long n,m,k,ans,g,f,l,sum,i,o,z;
int main()
{
    cin >> n >> m >> k;
    if(n==1)
    {
        cout << m << endl;
        exit(0);
    }
    ans=1;
    m-=n;
    g=k-1;
    f=n-k;
    l=min(g,f);
    o=max(g,f);
    z=l;
    if(m==1)
    {
        cout << 2 << endl;
        exit(0);
    }
    else if(m==0)
    {
        cout << 1 << endl;
        exit(0);
    }
    ans=2;
    m--;
    for(i=1;i<=o;i++)
    {
        sum++;
        sum+=i;
        if(l)
        {
            l--;
            sum+=i;
        }
        else
        {
            sum+=z;
        }
        if(sum>=m)
        {
            break;
        }
    }
    if(i==o+1)
    {
        cout << (ans+o)+((m-sum)/n) << endl;
        exit(0);
    }
    if(sum==m)
    {
        cout << ans+i << endl;
        exit(0);
    }
    else
    {
        cout << (ans+i)-1 << endl;
        exit(0);
    }
    return 0;
}
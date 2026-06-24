#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n+1],b[m+1];
    a[0]=0;
    b[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
        b[i]+=b[i-1];
    }
    int c[n+1],d[m+1];
    for(int i=0;i<=n;i++)
    {
        c[i]=INT_MAX;
    }
    for(int i=0;i<=m;i++)
    {
        d[i]=INT_MAX;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j+i<=n;j++)
        {
            c[i]=min(c[i],a[j+i]-a[j]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j+i<=m;j++)
        {
            d[i]=min(d[i],b[j+i]-b[j]);
        }
    }
    int x,p;
    cin >> x;
    int dp=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            p=x/c[i];
            if(d[j]<=p)
                dp=max(dp,i*j);
            else
                break;
        }
    }
    cout << dp;
	return 0;
}
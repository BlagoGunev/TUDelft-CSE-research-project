#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll readin()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    ll i;
    ll a,b,t,n;
    t=readin();
    ll x,y;
    while(t--)
    {
        a=-1;
        b=1e10;
        n=readin();
        for(i=1;i<=n;i++)
        {
            x=readin();
            y=readin();
            a=max(a,x);
            b=min(b,y);
        }
        if(n==1)
        {
            cout<<0<<endl;
        }
        else
        {
            ll stp=0;
            stp=max(a-b,(ll)0);
            cout<<stp<<endl;
        }
    }
}
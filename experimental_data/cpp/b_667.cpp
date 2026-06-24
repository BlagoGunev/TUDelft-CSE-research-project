#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 10000002
using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

int main()
{
    int n=getnum();

    ll tot=0,mx=0;

    for(int i=1;i<=n;i++)
    {
        ll x=getnum();
        tot+=x;
        mx=max(x,mx);
    }

    tot-=mx;
    tot=abs(tot-mx)+1;

    printf("%I64d",tot);
}
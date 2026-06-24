#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,long long>
#define piii pair<pair<int,int>,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
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

pii R[100004],L[100004];
ll H[100004];

int main()
{
    ll n=getnum(),x1=getnum(),x2=getnum(),hort=0,flag=0;
    ll inf=-1LL*(1LL)<<(62LL);
    int l=0,r=0,h=0;

    for(int i=1;i<=n;i++)
    {
        ll m=getnum(),c=getnum();

        ll y1=m*x1+c;
        ll y2=m*x2+c;

        if(y1<y2)R[++r]=mp(y2,y1);
        else if(y1>y2) L[++l]=mp(y1,y2);
        else H[++h]=y1;
    }

    sort(R+1,R+r+1);
    reverse(R+1,R+r+1);

    for(int i=2,cur=1;i<=r;i++)
    {
        if(R[cur].ff==R[i].ff)cur++;
        else if(R[cur].ss>=R[i].ss)cur++;
        else {;flag=1;break;}
    }

    sort(L+1,L+l+1);
    reverse(L+1,L+l+1);

    for(int i=2,cur=1;i<=l;i++)
    {
        if(L[cur].ff==L[i].ff)cur++;
        else if(L[cur].ss>=L[i].ss)cur++;
        else {;flag=1;break;}
    }

    sort(H+1,H+h+1);
    reverse(H+1,H+h+1);

    for(int i=1,rx=1;i<=h&&rx<=r;)
    {
        if(H[i]>=R[rx].ff)i++;
        else if(H[i]<R[rx].ff&&H[i]>R[rx].ss){flag=1;break;}
        else rx++;
    }

    for(int i=1,rx=1;i<=h&&rx<=l;)
    {
        if(H[i]>=L[rx].ff)i++;
        else if(H[i]<L[rx].ff&&H[i]>L[rx].ss){flag=1;break;}
        else rx++;
    }

    for(int rx=1,lx=1;rx<=r&&lx<=l;)
    {
        if(R[rx].ff>L[lx].ss&&R[rx].ss<L[lx].ff){flag=1;break;}
        else if(R[rx].ss>=L[lx].ff)rx++;
        else lx++;
    }

    if(flag)puts("Yes");
    else puts("No");
}
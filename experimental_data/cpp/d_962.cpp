#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
const int maxn=150000+7;
typedef long long ll;
typedef pair<long long,int> pli;
ll a[maxn];
priority_queue<pli,vector<pli>,greater<pli> >Q;
int main()
{
    int n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        Q.push(make_pair(a[i],i));
    }
    while(Q.size()>=2)
    {
        pli p=Q.top();
        Q.pop();
        pli v=Q.top();
        Q.pop();
        while(p.first!=v.first&&Q.size())
        {
            p=v;
            v=Q.top();
            Q.pop();
        }
        if(p.first!=v.first) break;
        a[p.second]=0;
        a[v.second]*=2;
        v.first*=2;
        Q.push(v);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        if(a[i]) cnt++;
    printf("%d\n",cnt);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==0)continue;
        else printf("%lld ",a[i]);
    }
    if(a[n-1]!=0) printf("%lld\n",a[n-1]);
    else printf("\n");
}
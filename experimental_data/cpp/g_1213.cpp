#if 1

#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
int n,m;
int p[200005];
pair <int,int> q[200005];
ll sum,cnt[200005],ans[200005];
vector <pair <int,pair <int,int> > > v;

int Find (int x)
{
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void add(int p1,int p2)
{
    Find(p1),Find(p2);
    sum -= cnt[p[p1]]*(cnt[p[p1]]-1)/2;
    sum -= cnt[p[p2]]*(cnt[p[p2]]-1)/2;
    cnt[p[p1]] += cnt[p[p2]];
    p[p[p2]] = p[p1];
    sum += cnt[p[p1]]*(cnt[p[p1]]-1)/2;
}

int main()
{
    scanf("%d %d", &n, &m);
    int x,y,w;
    for(int i = 1;i <= n-1;i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        v.push_back({w,{x,y}});
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&q[i].first);
        q[i].second = i;
    }
    for(int i = 1;i <= n;i++) p[i] = i,cnt[i] = 1;

    sort(v.begin(),v.end());
    sort(q+1,q+m+1);
    int p1,p2,cost,wt = 1;
    for(auto i : v)
    {
        cost = i.first;
        p1 = i.second.first;
        p2 = i.second.second;
        while(wt <= m&&q[wt].first < cost) ans[q[wt++].second] = sum;
        add(p1,p2);
    }
    while(wt <= m) ans[q[wt++].second] = sum;
    for(int i = 1;i <= m;i++)
    {
        printf("%lld ",ans[i]);
    }
}

#endif // 1
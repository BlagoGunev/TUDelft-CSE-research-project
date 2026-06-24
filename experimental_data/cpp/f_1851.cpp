#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,kk,t,a[500005],tot,ch[200005*32][2],vis[200005*32][2],p[200005*32],times;
vector<int> ed[200005*32];

void insert(int x,int id)
{
    int s = 0;
    for(int i = kk;i >= 0;i --)
    {
        int k = (x >> i) & 1;
        if(vis[s][k] != times) ch[s][k] = ++tot;
        else p[ch[s][k]] = times;
        vis[s][k] = times,s = ch[s][k];
    }
    ed[s].push_back(id);
}

int query(int x,int id)
{
    int s = 0,flag = 0;
    for(int i = kk;i >= 0;i --)
    {
        int k = (x >> i) & 1;
        if(vis[s][k] == times && (flag || (p[ch[s][k]] == times))) s = ch[s][k];
        else s = ch[s][!k],flag = 1;
    }
    if(ed[s][0] == id) return ed[s][1];
    return ed[s][0];
}

void work()
{
    cin >> n >> kk,times ++,kk--,tot = 0;
    int mi,mj,mx,ans = -1;

    for(int i = 1;i <= n;i ++) cin >> a[i],insert(a[i],i);

    for(int i = 1;i <= n;i ++)
    {
        int rj = query(a[i],i),rx = a[rj],res = 0,tx = 0;
        for(int j = kk;j >= 0;j --)
        {
            int k1 = (rx >> j) & 1,k2 = (a[i] >> j) & 1;
            if(k1 == k2) res += (1 << j);
            if(k1 == k2 && k1 == 0) tx += (1 << j);
        }
        if(res > ans) ans = res,mi = i,mj = rj,mx = tx;
    }
    
    cout << mi << " " << mj << " " << mx << "\n";
    for(int i = 0;i <= (kk+1)*n;i ++) ed[i].clear();
}

signed main()
{
    cin >> t;
    while(t --) work();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<int, int>

const int N=1e5+5;
const int KL=1e6+5;
const int B=1e9+5;
const int mod= 1e9+7;

int t;
int n;
vector<pair<int, pii>> v;
bool vis[1010];
vector<pair<pii, int >>ans;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof vis);
        v.clear();
        ans.clear();
        scanf("%d", &n);
        for (int i=0;i<n;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            v.push_back({y-x+1, {x, y}});
        }
        sort(v.begin(), v.end());
        for (auto X: v)
        {
            if (X.f==1)
            {
                ans.push_back({X.s, X.s.f});
                vis[X.s.f]=1;
            }
            else
            {
                for (int i=X.s.f;i<=X.s.s;i++)
                {
                    if (vis[i]==0)
                    {
                        vis[i]=1;
                        ans.push_back({X.s, i});
                        break;
                    }
                }
            }
        }
        for (int i=0;i<ans.size();i++)
        {
            printf("%d %d %d%c", ans[i].f.f, ans[i].f.s, ans[i].s, '\n');
        }

    }


    return 0;
}
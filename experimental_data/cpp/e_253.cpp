#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef set<pii>::iterator vit;

struct TASK
{
    int t;
    int s;
    int p;
    int id;
    ll FT;
    inline bool operator<(const TASK& b) const 
    {
        return t == b.t ? s > b.s : t < b.t;
    }
};
TASK Tasks[55555];

pii ps[55555];

ll ftans[55555];

int main(void)
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int n = 0;
    scanf("%d",&n);
    int target = -1;
    for(int i = 0;i < n;i++)
    {
        scanf("%d %d %d",&Tasks[i].t,&Tasks[i].s,&Tasks[i].p);
        Tasks[i].id = i;
    }
    
    ll T = 0;
    scanf("%I64d",&T);

    sort(Tasks,Tasks+n);
    for(int i = 0;i < n;i++) if(Tasks[i].p == -1) target = i;

    ll inside = T-Tasks[target].t-Tasks[target].s;
    set<pii> que;
    int maxx = (int)1e9+1;
    int minx = 0;
    // result in (minx,maxx), take (minx+maxx)/2
    for(int i = 0;i < n;i++)
    {
        if(i && Tasks[i].t != Tasks[i-1].t)
        {
            ll ft = Tasks[i].t-Tasks[i-1].t;
            ll ct = Tasks[i-1].t;
            while(ft && que.size())
            {
                vit it = que.begin();
                int tid = it->second;
                int cost = min<ll>(ft,Tasks[tid].s);
                ct += cost;
                Tasks[tid].s -= cost;
                ft -= cost;
                if(Tasks[tid].s == 0) { que.erase(it); Tasks[tid].FT = ct; }
            }
        }
        if(Tasks[i].p == -1)
        {
            int xpcnt = 0;
            for(int j = 0;j < n;j++)
            {
                if(Tasks[j].t > T) break;
                if(Tasks[j].s == 0 || Tasks[j].p == -1) continue;
                ps[xpcnt++] = pii(Tasks[j].p,Tasks[j].s);
            }
            sort(ps,ps+xpcnt);
            ll sum = 0;
            for(int j = xpcnt;j >= 0;j--)
            {
                sum += ps[j].second;
                if(sum == inside)
                {
                    if(j < xpcnt) maxx = ps[j].first;
                    if(j) minx = ps[j-1].first;
                    break;
                }
            }
            Tasks[i].p = (minx+maxx)/2;
            //printf("!!!!!! %d\n",Tasks[i].p);
        }
        que.insert(pii(-Tasks[i].p,i));
    }
    ll ct = Tasks[n-1].t;
    while(que.size())
    {
        vit it = que.begin();
        int tid = it->second;
        int cost = Tasks[tid].s;
        ct += cost;
        Tasks[tid].s -= cost;
        if(Tasks[tid].s == 0) { que.erase(it); Tasks[tid].FT = ct; }
    }

    printf("%d\n",Tasks[target].p);
    for(int i = 0;i < n;i++) ftans[Tasks[i].id] = Tasks[i].FT;
    for(int i = 0;i < n;i++) printf("%I64d ",ftans[i]);
    puts("");
    while(getchar() != EOF);
    return 0;
}
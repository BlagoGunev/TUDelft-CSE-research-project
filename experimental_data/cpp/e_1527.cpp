#include<bits/stdc++.h>
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define task "name" 

const int oo = 1e9 + 7;
const ll loo = (ll)1e18 + 7;
const int MOD = 1e9 + 7;
const int N = 35e3 + 10;
const int BASE = 10;

template <typename T1, typename T2> bool minimize(T1 &a, T2 b){if (a > b) {a = b; return true;} return false;}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b){if (a < b) {a = b; return true;} return false;}

int n, k;
int a[N];
int pre[N];
int f[103][N];
int d[103][N];
int pos_lef[N], pos_rig[N];
int cost, lef, rig;
int get(int l, int r)
{
    if(rig < r)
    {
        for(int i = rig + 1; i <= r; i++)
            if(lef <= pos_lef[i]) cost += (i - pos_lef[i]); 
        rig = r;

    }
    while(rig > r)
    {
        for(int i = rig; i > r; i--)
            if(lef <= pos_lef[i]) cost -= (i - pos_lef[i]);
        rig = r;
    }
    while(lef < l)
    {
        
        for(int i = lef; i < l; i++)
            if(pos_rig[i] <= rig) 
            {
                cost -= (pos_rig[i] - i);
            }
        lef = l;
    }
    while(lef > l)
    {
        for(int i = lef - 1; i >= l; i--)
            if(pos_rig[i] <= rig) cost += (pos_rig[i] - i);
        lef = l;
    }
    
    return cost;
}
void dnc(int g, int l, int r, int from, int to)
{
    if(l > r) return;
    int mid = (l + r)/2;
    
    for(int i = from; i <= to; i++)
    {
        if(f[g][mid] > get(i, mid) + f[g - 1][i - 1])
        {
            f[g][mid] = get(i, mid) + f[g - 1][i - 1];
           // if(get(i, mid) < 0) cout << g << " " << mid << '\n';
            d[g][mid] = i;
        }
    }
    dnc(g, l, mid - 1, from, d[g][mid]);
    dnc(g, mid + 1, r, d[g][mid], to);
}
void Solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos_lef[i] = pre[a[i]];
        pre[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) pre[i] = n + 1;
    for(int i = n; i >= 1; i--)
    {
        pos_rig[i] = pre[a[i]];
        pre[a[i]] = i;
    }
    lef = 1;
    rig = 1;
    cost = 0;
    // cout << get(2, 2);
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= n; i++) 
    {
        f[1][i] = get(1, i);
    }
    for(int i = 2; i <= k; i++) dnc(i, 1, n, 1, n);
   cout << f[k][n];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    //cin >> T;
    while(T--)
    {
        Solve();
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prl(x) printf("%lld\n",x)
#define yes printf("YES\n")
#define no printf ("NO\n")
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define tmp (l+r)/2
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ld pi=2*acos(0);
const ll mod=1e9+7;
const ld eps=1e-9;
const ll ll_max=2e18;
///const ll mod=998244353;

using namespace std;
const int N=200200;
ll a[N],pre[N],suf[N];
ll n,c;
int ans[N];
map<ll,ll>fre;
void solve()
{
    fre.clear();
    scl(n);scl(c);
    ll mx=0;
    for(int i=1;i<=n;i++)
    {
        scl(a[i]);
        mx=max(mx,a[i]);
    }
    suf[n+1]=-1;
    for(int i=n;i>=1;i--)
        suf[i]=max(suf[i+1],a[i]);
    a[1]+=c;
    mx=max(mx,a[1]);

    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
        fre[a[i]]++;
        if(a[i]==mx)
        {
            if(fre[a[i]]==1)
            {
                ans[i]=0;
            }
            else
            {
                ans[i]=i-1;
            }
        }
        else
        {
            ll x=pre[i];
            if(suf[i+1]>x)
                ans[i]=i;
            else
                ans[i]=i-1;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}
int main()
{
    int t=1;
    sc(t);
    while(t--)
    {
        solve();
    }
    return 0;
}
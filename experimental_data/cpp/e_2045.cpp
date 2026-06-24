#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5;
const int INF = 1e9;

const int MOD = 998244353;
struct mint
{
    int x;
    mint(void) : x(0) {}
    mint(int x) : x(x) {}
    mint operator+ (int ot) const { return x + ot >= MOD ? x + ot - MOD : x + ot; }
    mint operator- (int ot) const { return x >= ot ? x - ot : x + MOD - ot; }
    mint operator* (int ot) const { return 1ll * x * ot % MOD; }
    mint operator+= (int ot) { return *this = *this + ot; }
    mint operator-= (int ot) { return *this = *this - ot; }
    mint operator*= (int ot) { return *this = *this * ot; }
    operator int(void) { return x; }
};
mint mpow(mint a, int b)
{
    mint ret=1;
    while(b)
    {
        if(b&1) ret*=a;
        a*=a; b>>=1;
    }
    return ret;
}
mint inv(mint a) { return mpow(a, MOD-2); }

int N, A[MAXN+10], B[MAXN+10];
mint ITP[MAXN+10];
int L[MAXN+10], R[MAXN+10];

struct BIT1
{
    int tree[MAXN+10];
    void init() { for(int i=1; i<=MAXN; i++) tree[i]=0; }
    void update(int i, int k) { for(; i<=MAXN; i+=(i&-i)) tree[i]=max(tree[i], k); }
    int query(int i) { int ret=0; for(; i>0; i-=(i&-i)) ret=max(ret, tree[i]); return ret; }
}bit1;

struct BIT2
{
    int tree[MAXN+10];
    void init() { for(int i=1; i<=MAXN; i++) tree[i]=N+1; }
    void update(int i, int k) { for(; i<=MAXN; i+=(i&-i)) tree[i]=min(tree[i], k); }
    int query(int i) { int ret=N+1; for(; i>0; i-=(i&-i)) ret=min(ret, tree[i]); return ret; }
}bit2;

int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i], A[i]=MAXN-A[i]+1;
    for(int i=1; i<=N; i++) cin >> B[i], B[i]=MAXN-B[i]+1;
    A[0]=A[N+1]=B[0]=B[N+1]=-INF;

    ITP[0]=1; ITP[1]=inv(2);
    for(int i=2; i<=N; i++) ITP[i]=ITP[i-1]*ITP[1];

    mint ans;

    bit1.init(); bit2.init();
    for(int i=1; i<=N; i++)
    {
        L[i]=bit1.query(A[i]);
        bit1.update(A[i], i);
    }
    for(int i=N; i>=1; i--)
    {
        R[i]=bit2.query(A[i]-1);
        bit2.update(A[i], i);
    }
    for(int i=1; i<=N; i++)
    {
        int l=L[i], r=R[i];
        // for(int j=i-1; j>=0; j--) if(A[j]<=A[i]) { l=j; break; }
        // for(int j=i+1; j<=N+1; j++) if(A[j]<A[i]) { r=j; break; }
        // cout << i << " : " << l << " " << r << "\n";
        ans+=ITP[1]*(mint(1)-(l==0 ? mint(0) : ITP[i-l]))*(mint(1)-(r==N+1 ? mint(0) : ITP[r-i]))*(MAXN-A[i]+1);
    }

    bit1.init(); bit2.init();
    for(int i=1; i<=N; i++)
    {
        L[i]=bit1.query(B[i]);
        bit1.update(B[i], i);
    }
    for(int i=N; i>=1; i--)
    {
        R[i]=bit2.query(B[i]-1);
        bit2.update(B[i], i);
    }
    for(int i=1; i<=N; i++)
    {
        int l=L[i], r=R[i];
        // for(int j=i-1; j>=0; j--) if(B[j]<=B[i]) { l=j; break; }
        // for(int j=i+1; j<=N+1; j++) if(B[j]<B[i]) { r=j; break; }
        // cout << i << " : " << l << " " << r << "\n";
        ans+=ITP[1]*(mint(1)-(l==0 ? mint(0) : ITP[i-l]))*(mint(1)-(r==N+1 ? mint(0) : ITP[r-i]))*(MAXN-B[i]+1);
    }

    bit1.init(); bit2.init();
    for(int i=1; i<=N; i++)
    {
        L[i]=bit1.query(A[i]);
        bit1.update(min(A[i], B[i]+1), i);
    }
    for(int i=N; i>=1; i--)
    {
        R[i]=bit2.query(A[i]-1);
        bit2.update(min(A[i], B[i]), i);
    }
    for(int i=1; i<=N; i++)
    {
        if(B[i]<A[i]) continue;
        int l=L[i], r=R[i];
        // for(int j=i-1; j>=0; j--) if(A[j]<=A[i] || B[j]+1<=A[i]) { l=j; break; }
        // for(int j=i+1; j<=N+1; j++) if(A[j]<A[i] || B[j]<A[i]) { r=j; break; }
        // cout << i << " : " << l << " " << r << "\n";
        ans-=ITP[1]*(mint(1)-(l==0 ? mint(0) : ITP[i-l]))*(mint(1)-(r==N+1 ? mint(0) : ITP[r-i]))*(MAXN-A[i]+1);
    }

    bit1.init(); bit2.init();
    for(int i=1; i<=N; i++)
    {
        L[i]=bit1.query(B[i]);
        bit1.update(min(B[i], A[i]+1), i);
    }
    for(int i=N; i>=1; i--)
    {
        R[i]=bit2.query(B[i]-1);
        bit2.update(min(B[i], A[i]), i);
    }
    for(int i=1; i<=N; i++)
    {
        if(A[i]<B[i]) continue;
        int l=L[i], r=R[i];
        // for(int j=i-1; j>=0; j--) if(B[j]<=B[i] || A[j]<B[i]) { l=j; break; }
        // for(int j=i+1; j<=N+1; j++) if(B[j]<B[i] || A[j]<B[i]) { r=j; break; }
        // cout << i << " : " << l << " " << r << "\n";
        ans-=ITP[1]*(mint(1)-(l==0 ? mint(0) : ITP[i-l]))*(mint(1)-(r==N+1 ? mint(0) : ITP[r-i]))*(MAXN-B[i]+1);
    }

    cout << ans << "\n";
}
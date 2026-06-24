#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < n; i++)
#define dep(i,n) for(int i = n-1 ; i >= 0; i--)
#define re(i,a,b) for(int i = a ; i <= b; i++)
#define de(i,b,a) for(int i = b ; i >= a; i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define dbg1(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define prq(x) priority_queue<x,vector<x> > 
#define ll long long
#define db double
#define ld long double
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
    ll a[3],b[3];
    rep(i,3) cin>>a[i];
    rep(i,3) cin>>b[i];
    ll g=__gcd(a[2],b[2]);
    a[1]-=a[0];
    b[1]-=b[0];
    ll d=b[0]-a[0];
    d%=g;d+=g;
    d%=g;
    ll m1=min(a[1],b[1]+d)-d+1;
    d=g-d;
    ll m2=min(a[1]+d,b[1])-d+1;
    m2=max(m2,0LL);
    cout<<max(m1,m2)<<endl;
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t beg=clock();
    int t=1;
    // cin>>t;
    while(t--) solve();
    // 
    clock_t end=clock(); 
    fprintf(stderr, "%lf sec\n", (double)(end-beg)/(CLOCKS_PER_SEC));
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < n; i++)
#define dep(i,n) for(int i = n-1 ; i >= 0; i--)
#define re1(i,n) for(int i = 1 ; i <= n; i++)
#define de1(i,n) for(int i = n ; i > 0; i--)
#define rab(i,a,b) for(int i = a ; i <= b; i++)
#define dab(i,b,a) for(int i = b ; i >= a; i--)
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
    int n,m,k;cin>>n>>m>>k;
    ll ans=0;
    rep(i,k){
        ans+=(2*n+2*m-4);
        n-=4;
        m-=4;
    }
    cout<<ans;
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
#include <bits/stdc++.h>

using namespace std;
#define int long long
mt19937 rnd;
#define app push_back
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define debug(...) [](auto...a){ ((cout << a << ' '), ...) << endl;}(#__VA_ARGS__, ":", __VA_ARGS__)
#define debugv(v) do {cout<< #v <<" : {"; for(int izxc=0;izxc<v.size();++izxc) {cout << v[izxc];if(izxc+1!=v.size()) cout << ","; }cout <<"}"<< endl;} while(0)
#else
#define debug(...)
#define debugv(v)
#endif
#define lob(a,x) lower_bound(all(a),x)
#define upb(a,x) upper_bound(all(a),x)
int p;
const int maxn=1002;
int ans[maxn][maxn];
int res[maxn][maxn];
int dp[maxn][maxn];
int mi[maxn];
int answer[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) {
        int n,p;cin>>n>>p;int mod=p;
        for(int i=0;i<=2*n;++i) {for(int j=0;j<=2*n;++j) {ans[i][j]=0;dp[i][j]=0;}}
        int l2=n; {
            for(int r2=l2;r2<=2*n-1;++r2) {
                for(int i=0;i<2*n;++i) {mi[i]=max(abs(i-l2)+1,abs(i-r2)+1);}
                for(int l=2*n-1;l>=0;--l) {
                    for(int r=l;r<=2*n-1;++r) {
                        if(l==r) {
                            dp[l][r]=n+1-mi[l];continue;
                        }
                        int h=r-l+1;
                        dp[l][r]=dp[l+1][r]*(n+1-max(h,mi[l]))+dp[l][r-1]*(n+1-max(h,mi[r]));
                        int c=1;if(l+1<=r-1) {c=dp[l+1][r-1];}
                        dp[l][r]-=c*(n+1-max(h,mi[l]))*(n+1-max(h,mi[r]));
                        dp[l][r]%=mod;
                    }
                }
                for(int beg=r2-n+1;beg<=l2;++beg) {
                ans[l2-beg][r2-beg]=(dp[beg][beg+n-1]%mod+mod)%mod;
                }
            }
        }
        for(int l=0;l<=n-1;++l) {
            for(int r=l;r<=n-1;++r) {
                res[l][r]=ans[l][r];
                if(l-1>=0) {res[l][r]-=ans[l-1][r];}
                if(r+1<=n-1) {res[l][r]-=ans[l][r+1];}
                if(l-1>=0 && r+1<=n-1) {res[l][r]+=ans[l-1][r+1];}
                res[l][r]%=mod;res[l][r]+=mod;res[l][r]%=mod;
            }
        }
        int su=1;for(int i=1;i<=n;++i) {su*=n;su%=p;}
        for(int k=1;k<=n;++k) {
            int ans=0;
            for(int l=0;l<=n-k;++l) {
                int r=l+k-1;
                ans+=res[l][r];ans%=mod;
            }
            answer[k]=ans;su-=ans;su%=p;
        }
        answer[0]=su;
        for(int i=0;i<=n;++i) cout<<(answer[i]%p+p)%p<<' '; cout<<'\n';
    }
    return 0;
}
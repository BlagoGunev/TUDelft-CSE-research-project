#include <bits/stdc++.h>
#define int long long
#define double long double
#define pii pair<int,int>
#define F first
#define S second
#define no_more_love ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
//#define P pair<int,int>
using namespace std;
const int maxn=1000005,MOD=998244353;
int ar[maxn];
bool vis[maxn];
int cnt[maxn];
int ar2[maxn];
int ar3[maxn];
int ar4[maxn];
map<int,int>mp,mp2;
vector<int>v[maxn],v2,v3,v4;
int dp[maxn],dp2[maxn],n,m;
multiset<int>s,ss,sss,ssss;
//queue<int>q;
deque<int>dq;

signed main()
{
    no_more_love;
    register int t,i,j,a=0,b,a1,b1,k,d,cnt2,flag,flag2,a2,c,x,y,z;
    t=1;
    string s1,s2,s3,s4;
    char cccc,ccccc;
    cin>>t;
    while(t--){cin>>n>>x>>y;
        z=0;
        for(i=0;i<n;i++)cin>>ar[i];
        sort(ar,ar+n);
        int ans=0;
        for(i=0;i<n;i++){
            ar[i]+=z;
            if(y>x){
                ans+=(x*ar[i]);
                y-=x;
                z+=x;
            }
            else {
                ans+=(y*ar[i]);
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
*/
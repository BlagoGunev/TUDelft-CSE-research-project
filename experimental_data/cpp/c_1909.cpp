#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
typedef priority_queue< int, vector<int>, greater<int> > pql;
const int N= 1e6+1,M=18,mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //    freopen("error.txt", "w", stderr);
    //#endif
    ll t1=1,mod=1e9+7,n,d,l,r,k,m,a,b,i,j,p,q,s,ans,ans1,x,y;
    cin>>t1;
    while(t1--)
    {
        cin>>n;
        vector<ll> l(n), r(n),c(n),v,v1;
        for(i=0; i<n; i++) cin>>l[i];
        for(i=0; i<n; i++) cin>>r[i];
        for(i=0; i<n; i++) cin>>c[i];
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        sort(c.begin(),c.end());
        j=0;
        ans=0;
        for(i=0; i<n; i++){
            while(j<n && l[j]<r[i]){
                v.push_back(l[j]);
                j++;
            }
            v1.push_back(r[i]-v.back());
            v.pop_back();
        }
        sort(v1.rbegin(),v1.rend());
        for(i=0; i<n; i++) ans+=v1[i]*c[i];
        cout<<ans<<'\n';
    }
    return 0;
}
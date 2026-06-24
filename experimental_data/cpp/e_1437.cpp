#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define iinf INT_MAX
#define linf LONG_LONG_MAX;
#define LOOP  \
    ll _;     \
    cin >> _; \
    for (ll LP_ = 1; LP_ <= _; ++LP_)
#define syncfalse                \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define YON              \
    if (ok)              \
        cout << "YES\n"; \
    else                 \
        cout << "NO\n";
#define printans cout << "ans = " <<
const ll mod = 998244353;
// const ll MAXN = 200005;
// const int MAXN = 200000 + 5;

//------------------------------- I'm just a line -------------------------------
ll a[500005],b[500005];

int main() {
    //freopen("in.txt", "r", stdin);
    syncfalse;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]-=i;
    }
    for(int i=1;i<=k;i++){
        cin>>b[i];
    }
    bool ok=1;
    for(int i=2;i<=k;i++){
        if(a[b[i]]<a[b[i-1]]){
            ok=0;
            break;
        }
    }
    if(ok==0){
        cout<<-1;
        return 0;
    }
    b[0]=0;
    b[k+1]=n+1;
    a[0]=-linf;
    a[n+1]=linf;
    int ans=0;
    for(int i=1;i<=k+1;i++){
        int l=b[i-1];
        int r=b[i];
        vector<int> v;
        for(int j=l+1;j<r;j++){
            if(a[j]<a[l]||a[j]>a[r])continue;
            auto it = upper_bound(v.begin(),v.end(),a[j]);
            if(it==v.end())v.push_back(a[j]);
            else *it = a[j];
        }
        ans += r-l-1-v.size();
    }
    cout<<ans;
}
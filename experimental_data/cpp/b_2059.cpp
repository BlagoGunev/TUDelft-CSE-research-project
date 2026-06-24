#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long ll;
typedef complex<double> base;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF=1e9;
const ll LINF=1e18;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    if(n-k==0){
        int ans=1;
        for(int i=1;i<n;i+=2){
            if(v[i]!=ans){
                cout<<ans<<"\n";
                return;
            }
            ans++;
        }
        cout<<k/2+1<<"\n";
    }
    else{
        for(int i=1;i<=1+n-k;i++){
            if(v[i]!=1){
                cout<<1<<"\n";
                return;
            }
        }
        cout<<2<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
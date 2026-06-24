#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll=long long;
#define rep(i,a,b) for (int i=(ll)(a);i<(ll)(b);i++)
#define all(p) p.begin(),p.end()


void solve();
// oddloop
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    rep(i,0,t) solve();
}

void solve(){
    ll M,K;
    cin>>M>>K;
    vector<ll> A(M+1);
    rep(i,0,M+1) cin>>A[i];
    vector<int> order(M+1);
    rep(i,0,M+1) order[i]=i;
    sort(all(order),[&](int l,int r){
        return A[l]<A[r];
    });
    ll L=1,R=M+2;
    // if sum >= p[i], Alice will win
    vector<ll> p(M+1);
    p[0]=1;
    rep(i,0,M){
        // Bob erase
        p[i+1]=p[i]+K;
        // Alice pick
        p[i+1]+=(p[i+1]-1)/(i+1);
    }
    while(R-L>1){
        ll mid=(L+R)/2;
        vector<ll> B(mid);
        int ind=0;
        rep(i,0,M+1) if(order[i]<mid) B[ind++]=A[order[i]];
        vector<ll> sum(mid+1);
        rep(i,0,mid) sum[i+1]=sum[i]+B[i];
        bool ok=1;
        ll r=0;
        rep(k,1,mid) if(ok){
            // O(N)!
            while(r!=k){
                if(r*K<=(sum[k+1]-sum[r])-(k+1-r)*B[r]){
                    r++;
                }
                else{
                    break;
                }
            }
            ll tmp=sum[k+1]-sum[r];
            tmp-=r*K;
            if(tmp<p[k-r]){
                ok=0;
                break;
            }
        }
        if(ok) L=mid;
        else R=mid;
    }
    cout<<L<<"\n";
}
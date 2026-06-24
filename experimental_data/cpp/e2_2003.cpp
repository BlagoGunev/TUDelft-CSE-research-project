#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define vi vector<int>
#define ii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define vll vector<ll>
// #define int ll
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int N= 5e3+9, K= 500, OFF=102;
// const ll mod= 998244353;
ll dp[N][N][2],n,m;
int ckl[N],ckr[N];

ll rec(int i,int j,int f){
    if(i==0) {
        if(j==0) return 0;
        return -1e18;
    }
    if(j<0) return -1e18;
    // if(i<0) return 0;

    ll &ret= dp[i][j][f],res=-1e18;
    if(ret != -1)return ret;

    if(ckl[n-i]==2){
        res= max(res,(ll)i-1+rec(i-1,j,0));
        // if(!f){
        res= max(res,(ll)j-1+rec(i-1,j-1,0));
        // }
        // cout<<n-i-j+1<<endl;
    }
    else {
        if(ckl[n-i]){
            if(f) return ret= -1e18;
            res= max(res,(ll)j-1+rec(i-1,j-1,f));
        }
        else if(ckr[n-i]){
            int nf=0;
            if(ckr[n-i]==1) nf=1;
            res= max(res,(ll)i-1+rec(i-1,j,nf));
            // if(!f){
            //     res= max(res,(ll)j-1+rec(i-1,j-1,nf));
            // }
        }
        else {
            res= max(res,(ll)i-1+rec(i-1,j,1));
            if(!f){
                res= max(res,(ll)j-1+rec(i-1,j-1,0));
            }
        }
    }


    // cout<<i<<" "<<j<<" "<<res<<endl;
    return ret=res;
}

void solve(int tc){
    // ll n,m;
    cin>>n>>m;

    for(int i=0;i<=n+2;i++) {
        ckl[i]=ckr[i]=0;
        for(int j=0;j<=n+2;j++) dp[i][j][0]=dp[i][j][1]=-1;
    }

    vector<ii> dt(m);
    for(int i=0;i<m;i++){
        cin>>dt[i].fi>>dt[i].se;
        dt[i].fi--;
        dt[i].se--;
        ckl[dt[i].fi]=1;
        ckr[dt[i].se]=1;
    }

    // if(m){
    //     for(int i=0;i<dt[0].fi;i++) ckl[i]=2;
    //     for(int i=0;i<m-1;i++){
    //         for(int j=dt[i].se+1;j<dt[i+1].fi;j++) ckl[j]=2;
    //     }
    //     for(int i=dt.back().se+1;i<n;i++) ckl[i]=2;
    // }
    // else{
    //     for(int i=0;i<n;i++) ckl[i]=2;
    // } 

    for(int i=0;i<n;i++){
        int ys=1;
        for(int j=0;j<m;j++){
            if(dt[j].fi<=i && dt[j].se>=i) ys=0;
        }
        if(ys) ckl[i]=2;
    }


    for(int i=0;i<m;i++){
        ckr[dt[i].se]=2;
        for(int j=0;j<m;j++){
            if(dt[j].fi<=dt[i].se && dt[j].se>dt[i].se) ckr[dt[i].se]=1;
        }
    }

    for(int i=0;i<n;i++){
        if(ckl[i] && ckr[i]){
            cout<<"-1\n";
            return;
        }
    }

    ll res=-1;

    for(int i=0;i<=n;i++) {
        res=max(res, rec(n,i,0));
        // cout<<i<<" "<<rec(n,i,0)<<endl;
    }

    cout<<res<<"\n";

    // for(int mx=m;mx<=n;mx++){
    //     ll rem=mx;
    //     vi f(n,0);
    //     rem -= m;
    //     ll cur=0,dn=0;
    //     vi cand;
    //     if(m){
    //         // for(int i=0;i<dt[0].fi;i++) cand.push_back(i);
    //         // for(int i=0;i<m-1;i++){
    //         //     for(int j=dt[i].se+1;j<dt[i+1].fi;j++) cand.push_back(j);
    //         // }
    //         for(int i=dt.back().se+1;i<n;i++) cand.push_back(i);
    //     }

    //     for(int j=m-1;j>=0;j--){
    //         ll ln= dt[j].se-dt[j].fi-1;
    //         ll tmp=min(rem,ln);
    //         rem -= tmp;

    //         while(!cand.empty() && cand.back()>dt[j].se){
    //             cur += dn;
    //             dn++;
    //             f[cand.back()]=1;
    //             cand.pop_back();
    //         }
    //         for(int k=dt[j].fi+tmp;k>=dt[j].fi;k--){
    //             f[k]=1;
    //             cur += dn;
    //             dn++;
    //         }
    //     }

    //     if(rem) break;
    //     for(int j=n-1;j>=0;j--){
    //         if(f[j]) continue;
    //         cur += n-1-j;
    //     }
    //     res=max(res,cur);
    // }

    // cout<<res<<"\n";

}
 

signed main()
{  
    // freopen ("inp2.txt","r",stdin);
    // freopen ("outp2.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // srand(time(0));

    
    int tc=1;
    cin>>tc;
 
    for(int t=1;t<=tc;t++){
        // cout<<"Case "<<t<<":";
        solve(t);
    }
 
}
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX=1e5;            //for limit of nodes

const int MOD=998244353;        //for those annoying ass questions

vector<int>adj[MAX];

void solve(){

    int n;

    cin>>n;

    int cnt=0;

    while (n!=0) {

        n/=2;

        cnt++;

    }

    int ans=pow(2,cnt-1)-1;

    cout<<ans<<"\n";

}

signed main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin>>t;

    while (t--) {

       solve();

    }

return 0;

}
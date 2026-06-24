#include<bits/stdc++.h>

using namespace std;

#define int long long

#define rep(i,a,b) for(int i=a;i<b;i++)

#define pr(x) cout << #x << " = " << x << endl;

const int MOD = 1e9+7;



int solve(){

    int n , ans = 1 , x , l , r;

    cin >> n;

    int mp[n];

    rep(i,0,n){

        cin >> x;

        mp[x] = i;

        if(x == 0) l = i;

        if(x == 1) r = i;

    }

    if(l > r) swap(l,r);

    rep(i,2,n){

        if(mp[i] < l) l = mp[i];

        else if(r < mp[i]) r = mp[i];

        else ans = (ans * (r - l + 1 - i)) % MOD;

    }

    return ans;   

}



signed main(){    

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);     

    int testcases=1;       cin >> testcases;

    while(testcases--)   cout <<    solve()    << endl    ;

    return 0;

}
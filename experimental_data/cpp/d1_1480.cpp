#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;



#define int long long

#define mp make_pair

#define pb push_back



//#pragma GCC optimize("Ofast")

//#pragma GCC optimize("unroll-loops")

//#pragma GCC target("avx2")



constexpr int INF = (int)2e18;

constexpr int N = (int)5e5 + 111;

constexpr int md = (int)998244353;

constexpr int mdPower = (int)1e9+7 - 1;



typedef __int128 _uint;

typedef long long ll;



mt19937_64 rnd(time(nullptr));



void add(int& a,int b){

    a += b; if(a >= md) a -= md;

}

void sub(int& a,int b){

    a -= b; while(a < 0) a += md;

}

void add(__int128& a,int b){

    a += b;

}

void sub(__int128& a,int b){

    a -= b;

}



int bpow(int a,int b){

    if(b == 0)

        return 1;

    if(b % 2 == 0){

        int t = bpow(a,b>>1);

        return 1ll*t*t%md;

    }

    return 1ll * a*bpow(a,b-1) % md;

}



int inv(int a){

    return bpow(a,md-2);

}



//int fac[N],invfac[N];

//

//void init(){

//    fac[0] = 1;

//    for(int i = 1; i < N; i++){

//        fac[i] = (fac[i-1] * i) % md;

//    }

//    invfac[N-1] = inv(fac[N-1]);

//    for(int i = N-2; i >= 0; i--){

//        invfac[i] = (invfac[i+1] * (i+1))%md;

//    }

//    return;

//}

//

//int C(int n,int k){

//    if(k > n)

//        return 0;

//    return fac[n] * invfac[k] % md * invfac[n-k] % md;

//}

//

//int A(int n,int k){

//    if(k > n)

//        return 0;

//    return fac[n] * invfac[n-k] % md;

//}



struct DSU{ /// currently there is dsu on array

    vector<int> parent;

    vector<int> sz;

    DSU(){}

    DSU(int n){

        n = n+10;

        parent.resize(n);

        sz.resize(n);

        for(int i = 0; i < n; i++)

            parent[i] = i, sz[i] = 1;

    }

    int get(int x){

        return parent[x] == x ? x : parent[x] = get(parent[x]);

    }

    void union_sets(int a,int b){

        a = get(a), b = get(b);

        if(a == b)

            return;

        #warning DSU is written badly

        if(rnd()&1)

            swap(a,b);

        parent[a] = b;

        sz[b] += sz[a];

        return;

    }

    bool connected(int a,int b){

        return get(a) == get(b);

    }

};



void solve(){

    int n;

    cin >> n;



    int a[n+1];

    int ans = 1;



    for(int i = 1; i <= n; i++){

        cin >> a[i];

    }



    for(int i = 1; i + 1 <= n; i++){

        ans += (a[i] != a[i+1]);

    }



    int pr[2] = {};

    pr[0] = a[1];

    for(int i = 2; i < n; i++){

        if(pr[1] != a[i] && (a[i] == pr[0] || a[i] == a[i+1])){

            pr[1] = a[i];

            ans++;

        } else if(pr[1] != a[i] && pr[0] != a[i+1]){

            pr[1] = a[i];

        } else

            pr[0] = a[i];

//        cerr << i << " " << ans << "\n";

    }



    cout << ans << "\n";



    return;

}



signed main(){

    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int tests = 1;

//    cin >> tests;

    for(int test = 1; test <= tests; test++){

//        cerr << "test = " << test << "\n";

        solve();

    }

    return 0;

}

/**



**/
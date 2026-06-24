#include <bits/stdc++.h>



#define debug(x) cout << "> " << #x << " = " << x << endl;

#define debugat(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;



using namespace std;



typedef long long ll;



const ll MOD = 1e9 + 7;

const int N = 1050;

ll fat[N];



inline ll add(ll a, ll b) {

    a += b;

    if(a >= MOD)

        a -= MOD;

    return a;

}



inline ll mult(ll a, ll b) {

    return (a * b) % MOD;

}



inline ll power(ll a, ll b) {

    ll res = 1;

    while(b) {

        if(b & 1)

            res = mult(res, a);

        a = mult(a, a);

        b >>= 1;

    }

    return res;

}



inline void init() {

    fat[0] = 1;

    for(int i = 1; i < N; ++i)

        fat[i] = mult(fat[i - 1], i);

}



inline ll inv(ll a) {

    return power(a, MOD - 2LL);

}



inline ll combinations(ll n, ll k) {

    ll num = fat[n];

    ll den = mult(fat[k], fat[n - k]);

    return mult(num, inv(den));

}



int colors[N];

int k;



inline ll solve() {

    ll total = colors[1];

    ll ans = 1;

    for(int i = 2; i <= k; ++i) {

        ans = mult(ans, combinations(total + colors[i] - 1, total));

        total += colors[i];

    }

    return ans;

}



int main() {

    

    scanf("%d", &k);



    for(int i = 1; i <= k; ++i) {

        scanf("%d", colors + i);

    }



    init();

    ll ans = solve();



    printf("%lld\n", ans);

    return 0;

}
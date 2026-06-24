#include <iostream>

#include <algorithm>

#include <cstring>

#include <vector>

#include <cstdio>

#include <queue>

#include <unordered_map>

#include <set>

#include <cmath>

#include <map>



#define x first

#define y second



using namespace std;



typedef long long LL;

typedef pair<int , int> PII;



const int N = 3e6 + 5;

const int INF = 0x3f3f3f3f;

const int mod = 998244353;



int read(){

    int x = 0 , f = 1;

    char c = getchar();

    while(c < '0' || c > '9'){

        if(c == '-')f = -1;

        c = getchar();

    }

    while(c >= '0' && c <= '9'){

        x = x * 10 + c - '0';

        c = getchar();

    }

    return x * f;

}



int fact[N] , infact[N];

int f[2][N];



int qmi(int a , int b){

    int res = 1;

    while(b){

        if(b & 1)res = (LL)res * a % mod;

        a = (LL)a * a % mod;

        b >>= 1;

    }

    return res;

}



int C(int a , int b){

    if(a < b)return 0;

    return (LL)fact[a] * infact[a - b] % mod * infact[b] % mod;

}



void solve(){

    int n;

    cin >> n;

    fact[0] = 1;

    int tot = (1 << (21)) - 1;

    for(int i = 1 ; i <= tot ; i ++)fact[i] = (LL)fact[i - 1] * i % mod;

    infact[tot] = qmi(fact[tot] , mod - 2);

    for(int i = tot ; i ; i --)infact[i - 1] = (LL)infact[i] * i % mod;

    f[0][(1 << n)] = 1;

    for(int i = 1 ; i <= n ; i ++){

        int st = 1 << (n - i);

        for(int j = 1 ; j <= (1 << n) ; j ++)f[i & 1][j] = 0;

        for(int j = st * 2 ; j <= (1 << n) ; j ++){

            if(f[(i - 1) & 1][j] == 0)continue;

            f[i & 1][j - 1] = (LL)f[(i - 1) & 1][j] * C(j - st - 1 , st - 1) % mod * fact[st] % mod * 2 % mod;

        }

        for(int j = (1 << n) ; j ; j --)f[i & 1][j] = (f[i & 1][j] + f[(i) & 1][j + 1]) % mod;

    }

    for(int i = (1 << n) ; i ; i --)

        cout << f[n & 1][i] << '\n';

    cout << endl;

}



int main(){

    int T = 1;

    // cin >> T;

    while(T --){

        solve();

    }

    return 0;

}

/* stuff you should look for

 * int overflow, array bounds

 * special cases (n=1?)

 * do smth instead of nothing and stay organized

 * WRITE STUFF DOWN

 * DON'T GET STUCK ON ONE APPROACH

 */
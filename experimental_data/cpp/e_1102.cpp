#include<bits/stdc++.h>

#define ll long long
#define INF 2147483647
#define lc(a) (a << 1)
#define rc(a) (a << 1 | 1)
#define mod 998244353
#define int long long

inline int inp(){
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}

int a[400010], l[400010], r[400010], b[400010], delta[400010];

ll powmod(ll a, int b){
    ll sum = 1;
    while(b){
        if(b & 1){
            sum *= a;
            sum %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return sum;
}

signed main(){
    int n = inp();
    for(int i = 1; i <= n; i++)
        a[i] = inp();
    memcpy(b, a, sizeof(a));
    std::sort(b + 1, b + n + 1);
    int m = std::unique(b + 1, b + n + 1) - b;
    for(int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
    for(int i = 1; i <= n; i++)
        r[a[i]] = i;
    for(int i = n; i >= 1; i--)
        l[a[i]] = i;
    for(int i = 1; i <= n; i++){
        if(l[i] == 0)
            continue;
        delta[l[i] + 1]++;
        delta[r[i] + 1]--;
    }
    int sum = 0;
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        sum += delta[i];
        if(sum == 0)
            cnt++;
    }
    std::cout << powmod(2, cnt) << std::endl;
}
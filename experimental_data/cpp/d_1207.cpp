#include<bits/stdc++.h>

#define ll long long
#define INF 2147483647
#define mod 998244353

int inp(){
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

std::pair<int, int> s[300010];
ll fact[300010];
int n;

ll solve(){
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        int cur = i + 1;
        while(cur <= n && s[cur].first == s[i].first)
            cur++;
        ans *= fact[cur - i];
        ans %= mod;
        i = cur - 1;
    }
    // printf("solve() = %lld\n", ans);
    return ans;
}

int main(){
    n = inp();
    for(int i = 1; i <= n; i++){
        s[i].first = inp();
        s[i].second = inp();
    }
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
    ll ans = fact[n];
    std::sort(s + 1, s + n + 1);
    bool flg = true;
    for(int i = 1; i <= n; i++)
        if(s[i].second < s[i - 1].second){
            flg = false;
            break;
        }
    ans -= solve();
    ans += mod;
    ans %= mod;
    if(flg){
        ll res = 1;
        for(int i = 1; i <= n; i++){
            int cur = i + 1;
            while(cur <= n && s[cur] == s[i])
                cur++;
            res *= fact[cur - i];
            res %= mod;
            i = cur - 1;
        }
        // printf("res = %lld\n", res);
        ans += res;
        ans %= mod;
    }
    for(int i = 1; i <= n; i++)
        std::swap(s[i].first, s[i].second);
    std::sort(s + 1, s + n + 1);
    ans -= solve();
    ans += mod;
    ans %= mod;
    printf("%lld\n", ans);
}
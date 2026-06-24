#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>

const int INF = 1 << 30;
const double eps = 1e-8;
const int maxn = 20;
const int maxm = 1 << 19;
typedef long long ll;

ll dp[maxm][maxn];
ll es[maxn][maxn];
ll s[maxn];
ll ans[maxn];
using namespace std;

typedef pair<int, int> P;

int main(){
    int n, m, k;
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        memset(es, 0, sizeof(es));
        for(int i = 1; i <= n; ++ i){
            scanf("%lld", &s[i]);
        }

        for(int i = 0; i < k; ++ i){
            int x, y;
            ll ss;
            scanf("%d%d%lld", &x, &y, &ss);
            es[x][y] = ss;
        }
        memset(dp, 0, sizeof(dp));
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i < (1 << n); ++ i){
            int num[maxn];
            int amount = 0;
            for(int j = 0; j < n; ++ j){
                if(i&(1<<j)){
                    num[amount ++] = j;
                }
            }
            for(int j = 0; j < amount; ++ j){
                dp[i][num[j]+1] = s[num[j]+1];
                for(int k = 0; k < amount; ++ k){
                    if(j == k) continue;
                    dp[i][num[j]+1] = max(dp[i][num[j]+1],
                                          dp[i&(~(1<<num[j]))][num[k]+1] + s[num[j]+1] + es[num[k]+1][num[j]+1]);
                }
                ans[amount] = max(ans[amount], dp[i][num[j]+1]);
            }
        }
        printf("%lld\n", ans[m]);
    }
    return 0;
}
/*
 * Author: OpenLegend
 * Created Time:  2011-4-10 16:39:24
 * File Name: c.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 105;
const int INF = 1234567890;
char s[maxn];
int dp[maxn][maxn][26];
int pt[26][26];
char buf[10], buf2[10];
void update(int& x, int v){
    x = max(x, v);
}
int main() {
    int K;
    while(scanf("%s%d", s, &K) != EOF){
        int len = strlen(s);
        int n;
        scanf("%d", &n);
        memset(pt, 0, sizeof(pt));
        while(n--){
            int v;
            scanf("%s%s%d", buf, buf2, &v);
            pt[buf[0]-'a'][buf2[0]-'a'] += v;
        }
        for(int i = 0; i <= len; i ++){
            for(int j = 0; j <= K; j ++){
                for(int l1 = 0; l1 < 26; l1 ++){
                    dp[i][j][l1] = -INF;
                }
            }
        }
        for(int l1 = 0; l1 < 26; l1 ++){
            dp[1][(l1==(s[0]-'a')?0:1)][l1] = 0;
        }
        for(int i = 1; i < len; i ++){
            for(int j = 0; j <= K; j ++){
                for(int l1 = 0; l1 < 26; l1 ++){
                    int tmp = dp[i][j][l1];
                    if(tmp == -INF) continue;
                    for(int l2 = 0; l2 < 26; l2 ++){
                        update(dp[i+1][j+(l2==(s[i]-'a')?0:1)][l2], tmp+pt[l1][l2]);
                    }
                }
            }
        }
        int ans = -INF;
        for(int j = 0; j <= K; j ++){
            for(int l1 = 0; l1 < 26; l1 ++){
                update(ans, dp[len][j][l1]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
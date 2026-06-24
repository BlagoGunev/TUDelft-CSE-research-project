#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

#define N 100010
#define M 1000000007
#define inf 0x3f3f3f3f
#define eps 1e-8
#define LL long long
#define Pi acos(-1)

struct Node{
    int s,t;
    bool operator < (const Node tmp) const{
        return t < tmp.t;
    }
}a[N];

int n, m;

int find(int l, int r, int x){
    if (l > r) return -1;
    if (a[r].t < x) return -1;
    int mid;
    while (l < r){
        mid = (l + r) >> 1;
        if (x <= a[mid].t){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (l > 1) l--;
    while (a[l].t < x && l <= r) l++;
    l--;
    return l;
}

int main(){
    //freopen("a.txt","r",stdin);
    int n, i, pos, res, sum[N], dp[N], flag[N];
	while (scanf("%d%d",&n,&m) != EOF){
        for (i = 1; i <= m; ++i){
            scanf("%d%d",&a[i].s, &a[i].t);
        }
        sort(a + 1, a + m + 1);
        sum[0] = 0;
        res = 0;
        flag[1] = 0;
        for (i = 2; i <= m; ++i){
            if (a[i].t == a[i - 1].t) flag[i] = flag[i - 1];
            else flag[i] = i - 1;
        }
        //memset(dp, 0, sizeof(dp));
        for (i = 1; i <= m; ++i){
            pos = find(1, flag[i], a[i].s);
            if (pos != -1){
                dp[i] = (sum[flag[i]] - sum[pos] + M) % M;
            }
            else dp[i] = 0;
            if (a[i].s == 0) dp[i] = (dp[i] + 1) % M;
            sum[i] = (sum[i - 1] + dp[i]) % M;
            if (a[i].t == n){
                res = (res + dp[i]) % M;
            }
        }
        printf("%d\n", res);
	}
    return 0;
}
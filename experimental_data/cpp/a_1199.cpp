/*
 * Author       : YangDavid
 * Created Time : 2019年07月31日 星期三 00时19分32秒
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 111111;
int n;
bool valid(int xx) { return xx >= 1 && xx <= n; }
int x, y, a[maxn];
int main() {
    scanf("%d%d%d", &n, &x, &y);
    rep(i, n) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) {
        bool ok = true;
        for(int j = i - x; j < i; ++j) if(valid(j) && a[j] <= a[i])
            ok = false;
        for(int j = i + 1; j <= i + y; ++j) if(valid(j) && a[j] <= a[i])
            ok = false;
        if(ok) { printf("%d\n", i); return 0; }
    }
    return 0;
}
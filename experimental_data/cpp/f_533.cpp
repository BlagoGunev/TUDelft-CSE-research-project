#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <map>
#include <queue>
#include <bitset>
using namespace std;

const int maxn =210000;
vector <int> ans;

int m, n, now[maxn], pre[maxn], pre1[maxn], nxt[maxn];
char S[maxn], T[maxn];

bool ok(int x, int y) {
    if (pre[x] < x - y + 1)
        return pre[y] == 0;
    else
        return x - pre[x] == y - pre[y];
}

bool ok1(int x, int y) {
    if (pre1[x] < x - y + 1)
        return pre[y] == 0;
    else
        return x - pre1[x] == y - pre[y];
}

bool check(int x) {
    int to[26];
    for (int i = 0; i < 26; i++)
        to[i] = -1;
    for (int i = 0; i < 26; i++)
        if (now[i]) {
            to[i] = S[x + now[i] - 1] - 'a';
        }
    for (int i = 0; i < 26; i++)
        if (to[i] >= 0 && to[to[i]] >= 0 && i != to[to[i]]) return false;
    return true;
}

int main() {

    scanf("%d%d", &m, &n);
    scanf("%s", S);
    scanf("%s", T);
    for (int i = m; i > 0; i --)  S[i] = S[i - 1];
    for (int i = n; i > 0; i --)  T[i] = T[i - 1];
    S[0]=T[0]=0;

    for (int i = 0; i < 26; i++)
        now[i] = 0;
    for (int i = 1; i <= m; i++) {
        pre1[i] = now[S[i] - 'a'];
        now[S[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++)
        now[i] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = now[T[i] - 'a'];
        now[T[i] - 'a'] = i;
    }
    int p = 0;
    for (int i = 2; i <= n; i++) {
        for (; p && !ok(i, p + 1); p = nxt[p]);
        if (ok(i, p + 1)) p++;
        nxt[i] = p;
    }
    p = 0;
    for (int i = 1; i <= m; i++) {
        for (; p && !ok1(i, p + 1); p = nxt[p]);
        if (ok1(i, p + 1)) p++;
        if (p == n) {
            p = nxt[p];
            if (check(i - n + 1)) ans.push_back(i - n + 1);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int) ans.size(); i++)
        printf("%d ", ans[i]);
    return 0;
}
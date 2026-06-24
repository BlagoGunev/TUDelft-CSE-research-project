#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

const int N = 3000 + 5;

int n, m;
int l[N][N], r[N][N], cnt[N], fen[N];
char s[N][N];
vector < int > del[N];

void up(int x, int k) {
    //printf("up x = %d k = %d\n", x, k);
    cnt[x] += k;
    for(; x; x -= x & -x)
        fen[x] += k;
}

int get(int x) {
    int res = 0;
    for(; x < N; x += x & -x)
        res += fen[x];
    return res;
}

ll start(int x, int y) {
    memset(fen, 0, sizeof(fen));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i++)
        del[i].clear();
    ll ans = 0;
    int go = x;
    //printf("IN x = %d y = %d\n", x, y);
    while(x <= n and y >= 1) {
        for(auto u : del[x])
            up(u, -1);
        if(s[x][y] == '.') {
            for(int i = go; i < x; i++)
                if(cnt[i])
                    up(i, -1);
            go = x + 1;
            x++;
            y--;
            continue;
        }
        up(x, +1);
        if(x + l[x][y] <= n)
            del[x + l[x][y]].push_back(x);
        int len = min(r[x][y], x - go + 1);
        ans += get(x - len + 1);
        //printf("x = %d y = %d len = %d addd = %d\n", x, y, len, get(x - len + 1));
        x++;
        y--;
    }
    //printf("ans = %lld\n", ans);
    return ans;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for(int j = 1; j <= m; j++) {
            l[i][j] = s[i][j] == 'z' ? l[i][j - 1] + 1 : 0;
        }
        for(int j = m; j >= 1; j--) {
            r[i][j] = s[i][j] == 'z' ? r[i][j + 1] + 1 : 0;
        }
    }
    
    ll ans = 0;
    
    for(int i = 1; i <= m; i++) {
        ans += start(1, i);
    }
    
    for(int i = 2; i <= n; i++) {
        ans += start(i, m);
    }
    
    printf("%lld\n", ans);
    
    return 0;
    
}
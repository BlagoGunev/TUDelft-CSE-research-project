/*
 * by purple
 * at 11-08-30 1:15:06
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for(int i=0;i<(n);++i)
#define repf(i,a,b) for(int i=(a);i<=(b);++i)

// using the power of purple light : )

typedef pair<int,int> pii;

const int maxn = 100000 + 10;

bool lucky(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int id[maxn], a[maxn], pos[maxn], n;
bool f[maxn];

bool check() {
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] < a[i]) {
            return false;
        }
    }
    return true;
}

bool comp(int x, int y) {
    return a[x] < a[y];
}

int main() {
    while (scanf ("%d", &n) != EOF) {
        int c = -1;
        for (int i = 0; i < n; ++i) {
            scanf ("%d", a + i);
            if (lucky(a[i])) c = i;
            id[i] = i;
        }
        if (c == -1) {
            printf ("%d\n", check()? 0 : -1);
            continue;
        }
        sort (id, id + n, comp);
        
        for (int i = 0; i < n; ++i) {
            pos[id[i]] = i;
            f[i] = false;
            //printf ("%d : %d pos\n", id[i], i);
        }
        
        int posc = c;
        vector<pii> ans;
        //out(posc);
        while (posc != pos[c]) {
            ans.push_back(pii(posc, id[posc]));
            f[posc] = true;
            //out(posc);
            posc = id[posc];
        }
        f[posc] = true;
        for (int i = 0; i < n; ++i) {
            if (pos[i] != i && !f[i]) {
                ans.push_back(pii(posc, i));
                int tmp = posc;
                posc = i;
                while (pos[i] != posc) {
                    ans.push_back(pii(posc, id[posc]));
                    f[posc] = true;
                    posc = id[posc];
                }
                f[posc] = true;
                ans.push_back(pii(posc, tmp));
                posc = tmp;
            }
        }
        printf ("%d\n", sz(ans));
        for (int i = 0; i < sz(ans); ++i) {
            printf ("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        }
    }
    return 0;
}
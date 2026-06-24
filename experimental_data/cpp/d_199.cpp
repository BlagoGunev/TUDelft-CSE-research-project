#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MP make_pair
#define PB push_back
using namespace std;
int n, k;
char x[2][100005];
bool v[2][100005];

struct node {

    int p;
    bool l;
    int t;
};
queue<node> q;

int main() {
    while (scanf("%d%d", &n, &k) == 2) {
        scanf(" %s %s", x[0], x[1]);
        memset(v, 0, sizeof (v));
        node cur, nxt;
        cur.p = 0;
        cur.l = 0;
        cur.t = 0;
        v[0][0] = 1;
        bool flag = 0;
        while (!q.empty()) q.pop();
        q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur.p + k >= n) {
                flag = 1;
                break;
            }
            if (cur.p + 1 < n && x[cur.l][cur.p + 1] == '-' && !v[cur.l][cur.p + 1]) {
                nxt.p = cur.p + 1;
                nxt.l = cur.l;
                nxt.t = cur.t + 1;
                if (nxt.p >= nxt.t) {
                    v[cur.l][cur.p + 1] = 1;
                    q.push(nxt);
                }
            }
            if (cur.p - 1 >= 0 && x[cur.l][cur.p - 1] == '-' && !v[cur.l][cur.p - 1]) {
                nxt.p = cur.p - 1;
                nxt.l = cur.l;
                nxt.t = cur.t + 1;
                if (nxt.p >= nxt.t) {
                    v[cur.l][cur.p - 1] = 1;
                    q.push(nxt);
                }
            }
            if (cur.p + k < n && x[cur.l^1][cur.p + k] == '-' && !v[cur.l^1][cur.p + k]) {
                nxt.p = cur.p + k;
                nxt.l = cur.l^1;
                nxt.t = cur.t + 1;
                if (nxt.p >= nxt.t) {
                    v[cur.l^1][cur.p + k] = 1;
                    q.push(nxt);
                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
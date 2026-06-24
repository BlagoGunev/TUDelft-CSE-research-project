#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long int LLI;
typedef pair<int,int> PII;

#define _ ios_base::sync_with_stdio(0);
// #define debug
#define x first
#define y second
#define MXN 10005

const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-8; 

struct node {
    int l, r, val; // val == -1 if op node
    node() {};
    node(int val) : l(-1), r(-1), val(val) {};
} nodes[MXN];

string e;
int num, memo[MXN][105][2], ops[MXN];
bool visited[MXN][105];

int dfs(int cur) {
    if (nodes[cur].val == -1) {
        ops[cur] = 1 + dfs(nodes[cur].l) + dfs(nodes[cur].r);
    } else ops[cur] = 0;
    return ops[cur];
}

PII dfs(int cur, int p, int m, int which) {
    assert(p+m == ops[cur]);
    if (nodes[cur].val != -1) return {nodes[cur].val, nodes[cur].val};
    int lp, lm, rp, rm, ln = nodes[cur].l, rn = nodes[cur].r;
    PII l, r;
    if (which) { // m is less
        if (visited[cur][m])
            return {memo[cur][m][0], memo[cur][m][1]};
        visited[cur][m] = 1;
        memo[cur][m][0] = -inf;
        memo[cur][m][1] = inf;
        if (m) {
            // use minus here
            for (int i = 0; i < m; ++i) {
                lm = i;
                lp = ops[ln] - lm;
                rm = m-1-i;
                rp = ops[rn] - rm;
                if (lp < 0 || rp < 0 || lp + rp > p) continue;
                l = dfs(ln, lp, lm, 1);
                r = dfs(rn, rp, rm, 1);
                memo[cur][m][0] = max(memo[cur][m][0], l.x - r.y);
                memo[cur][m][0] = max(memo[cur][m][0], l.y - r.y);
                memo[cur][m][0] = max(memo[cur][m][0], l.x - r.x);
                memo[cur][m][0] = max(memo[cur][m][0], l.y - r.x);

                memo[cur][m][1] = min(memo[cur][m][1], l.x - r.y);
                memo[cur][m][1] = min(memo[cur][m][1], l.y - r.y);
                memo[cur][m][1] = min(memo[cur][m][1], l.x - r.x);
                memo[cur][m][1] = min(memo[cur][m][1], l.y - r.x);
            }
        }
#ifdef debug
        cout << "after minus at " << cur << " with (p, m): " << p << " " << m << " is " << memo[cur][m][0] << " " << memo[cur][m][1] << "\n";
#endif
        if (p) {
            // use plus here
            for (int i = 0; i <= m; ++i) {
                lm = i;
                lp = ops[ln] - lm;
                rm = m-i;
                rp = ops[rn] - rm;
                if (lp < 0 || rp < 0 || lp + rp > p-1) continue;
                l = dfs(ln, lp, lm, 1);
                r = dfs(rn, rp, rm, 1);
                memo[cur][m][0] = max(memo[cur][m][0], l.x + r.y);
                memo[cur][m][0] = max(memo[cur][m][0], l.y + r.y);
                memo[cur][m][0] = max(memo[cur][m][0], l.x + r.x);
                memo[cur][m][0] = max(memo[cur][m][0], l.y + r.x);

                memo[cur][m][1] = min(memo[cur][m][1], l.x + r.y);
                memo[cur][m][1] = min(memo[cur][m][1], l.y + r.y);
                memo[cur][m][1] = min(memo[cur][m][1], l.x + r.x);
                memo[cur][m][1] = min(memo[cur][m][1], l.y + r.x);
            }
        }
#ifdef debug
        cout << "return at " << cur << " with (p, m): " << p << " " << m << " is " << memo[cur][m][0] << " " << memo[cur][m][1] << "\n";
#endif
        assert(memo[cur][m][0] >= memo[cur][m][1]);
        return {memo[cur][m][0], memo[cur][m][1]};
    } else {
        if (visited[cur][p])
            return {memo[cur][p][0], memo[cur][p][1]};
        visited[cur][p] = 1;
        memo[cur][p][0] = -inf;
        memo[cur][p][1] = inf;
        if (m) {
            // use minus here
            for (int i = 0; i <= p; ++i) {
                lp = i;
                lm = ops[ln] - lp;
                rp = p-i;
                rm = ops[rn] - rp;
                if (lm < 0 || rm < 0 || lm + rm > m-1) continue;
#ifdef debug
                cout << lp << " " << lm << " " << rp << " " << rm << "\n";
#endif
                l = dfs(ln, lp, lm, 0);
                r = dfs(rn, rp, rm, 0);
                memo[cur][p][0] = max(memo[cur][p][0], l.x - r.y);
                memo[cur][p][0] = max(memo[cur][p][0], l.y - r.y);
                memo[cur][p][0] = max(memo[cur][p][0], l.x - r.x);
                memo[cur][p][0] = max(memo[cur][p][0], l.y - r.x);

                memo[cur][p][1] = min(memo[cur][p][1], l.x - r.y);
                memo[cur][p][1] = min(memo[cur][p][1], l.y - r.y);
                memo[cur][p][1] = min(memo[cur][p][1], l.x - r.x);
                memo[cur][p][1] = min(memo[cur][p][1], l.y - r.x);
            }
        }
#ifdef debug
        cout << "after minus at " << cur << " with (p, m): " << p << " " << m << " is " << memo[cur][p][0] << " " << memo[cur][p][1] << "\n";
#endif
        if (p) {
            // use plus here
            for (int i = 0; i < p; ++i) {
                lp = i;
                lm = ops[ln] - lp;
                rp = p-1-i;
                rm = ops[rn] - rp;
                if (lm < 0 || rm < 0 || lm + rm > m) continue;
                l = dfs(ln, lp, lm, 0);
                r = dfs(rn, rp, rm, 0);
                memo[cur][p][0] = max(memo[cur][p][0], l.x + r.y);
                memo[cur][p][0] = max(memo[cur][p][0], l.y + r.y);
                memo[cur][p][0] = max(memo[cur][p][0], l.x + r.x);
                memo[cur][p][0] = max(memo[cur][p][0], l.y + r.x);

                memo[cur][p][1] = min(memo[cur][p][1], l.x + r.y);
                memo[cur][p][1] = min(memo[cur][p][1], l.y + r.y);
                memo[cur][p][1] = min(memo[cur][p][1], l.x + r.x);
                memo[cur][p][1] = min(memo[cur][p][1], l.y + r.x);
            }
        }
#ifdef debug
        cout << "return at " << cur << " with (p, m): " << p << " " << m << " is " << memo[cur][p][0] << " " << memo[cur][p][1] << "\n";
#endif
        assert(memo[cur][p][0] >= memo[cur][p][1]);
        return {memo[cur][p][0], memo[cur][p][1]};
    }
}

int create(int l, int r) {
    int cur = num;
    if (e[l] == '(' && e[r] == ')') {
        int cnt = 0;
        for (int i = l+1; i < r; ++i) {
            if (e[i] == '(') ++cnt;
            else if (e[i] == ')') --cnt;
            else if (e[i] == '?' && !cnt) {
                nodes[num++] = node(-1);
                nodes[cur].l = create(l+1, i-1);
                nodes[cur].r = create(i+1, r-1);
            }
        }
    } else {
        assert(l == r);
        nodes[num++] = node(e[l] - '0');
    }
    return cur;
}

void print(int cur) {
    cout << "at " << cur << " values " << nodes[cur].val << ": " << nodes[cur].l << " " << nodes[cur].r << "\n";
    if (nodes[cur].val == -1) {
        print(nodes[cur].l);
        print(nodes[cur].r);
    }
}


int main() { _
    int p, m, n, root;
    while (cin >> e >> p >> m) {
        num = 0;
        n = e.length();
        root = create(0, n-1); // O(n^2)
#ifdef debug
        print(root);
        cout << "\n";
#endif
        dfs(root);
        memset(visited, 0, sizeof(visited));
        if (p <= 100) cout << dfs(root, p, m, 0).x << "\n";
        else cout << dfs(root, p, m, 1).x << "\n";
    }

    return 0;
}
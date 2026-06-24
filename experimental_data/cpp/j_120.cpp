#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define SQR(x) ((x) * (x))
const int maxint = -1u>>1;

struct P {
    int x, y, id, k;
    int dist(const P &a) const {
        return SQR(x - a.x) + SQR(y - a.y);
    }
    bool operator < (const P &a) const {
        return x < a.x || x == a.x && y < a.y;
    }
    void input() {
        scanf("%d%d", &x, &y);
    }
};

const int maxn = 200000 + 100;
int n;
P pt[maxn];

void update(int &ans, pair<int, int> &res, const pair<int, int> r) {
    int dist = pt[r.first].dist(pt[r.second]);
    if (ans > dist) {
        ans = dist;
        res = r;
    }
}
pair<int, int> work(int lf, int rt, vector<int> &idy) {
    if (lf + 2 == rt) return make_pair(lf, lf + 1);
    int mid = (lf + rt) / 2;
    vector<int> idlf, idrt;
    for (int i = 0; i < (int)idy.size(); ++i) {
        if (pt[idy[i]].x < pt[mid].x || pt[idy[i]].x == pt[mid].x && pt[idy[i]].y < pt[mid].y) {
            idlf.push_back(idy[i]);
        } else {
            idrt.push_back(idy[i]);
        }
    }
    pair<int, int> res(-1, -1);
    int ans = maxint;
    if (mid - lf >= 2) {
        pair<int, int> rlf = work(lf, mid, idlf);
        update(ans, res, rlf);
    }
    if (rt - mid >= 2) {
        pair<int, int> rrt = work(mid, rt, idrt);
        update(ans, res, rrt);
    }
    int cnt = 0;
    for (int i = 0; i < (int)idy.size(); ++i) {
        if (abs(pt[idy[i]].x - pt[mid].x) <= ans) idy[cnt++] = idy[i];
    }
    idy.resize(cnt);
    for (int i = 0; i < cnt; ++i) {
        for (int j = i + 1; j < i + 8 && j < cnt; ++j) {
            update(ans, res, make_pair(idy[i], idy[j]));
        }
    }
    return res;
}
bool cmp(const int &x1, const int &x2) {
    return pt[x1].y < pt[x2].y || pt[x1].y == pt[x2].y && pt[x1].x < pt[x2].x;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (scanf("%d", &n) == 1) {
        vector<int> idy;
        for (int i = 0; i < n; ++i) {
            pt[i].input();
            pt[i].id = i;
            idy.push_back(i);
            pt[i].k = 0;
            if (pt[i].x < 0) {
                pt[i].k += 1;
                pt[i].x = -pt[i].x;
            }
            if (pt[i].y < 0) {
                pt[i].k += 2;
                pt[i].y = -pt[i].y;
            }
        }
        sort(pt, pt + n);
        bool flag = false;
        for (int i = 1; i < n; ++i) {
            if (pt[i - 1].x == pt[i].x && pt[i - 1].y == pt[i].y) {
                printf("%d %d %d %d\n", pt[i - 1].id + 1, pt[i - 1].k + 1, pt[i].id + 1, 4 - pt[i].k);
                flag = true;
                break;
            }
        }
        if (flag) continue;
        sort(idy.begin(), idy.end(), cmp);
        pair<int, int> ans = work(0, n, idy);
        printf("%d %d %d %d\n", pt[ans.first].id + 1, pt[ans.first].k + 1, pt[ans.second].id + 1, 4 - pt[ans.second].k);
        //printf("%d\n", pt[ans.first].dist(pt[ans.second]));
    }
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <limits>
#include <memory.h>
#include <inttypes.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned int uint;
typedef unsigned char uchar;
typedef vector<int64> vi64;
typedef vector<vi64> vvi64;
typedef vector<vvi64> vvvi64;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<string,string> pss;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef pair<int64,int64> pii64;
typedef pair<pii64,int64> piii64;
typedef vector<pii64> vpii64;
typedef pair<int64,piii> qelem;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,pii> pdii;
typedef pair<double,double> pdd;    
typedef pair<double,pdd> pddd;
typedef pair<pdd,int> pddi;

const int64 kInf = 1000000000000000018LL;

int n, m;
vi c;
vvi a;
vvpii b;
vvi lnk;

inline void init() {
    cin >> n >> m;
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    a.assign(n, vi(m));
    b.assign(m, vpii(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b[j][i] = pii(a[i][j], i);
        }
    }
    lnk.assign(m, vi(n, -1));
    for (int i = 0; i < m; ++i) {
        sort(b[i].begin(), b[i].end());
        for (int j = 0; j < n; ++j) {
            lnk[i][b[i][j].second] = j;
        }
    }
}

inline int get_id(int x, int y, int z) {
    return ((x * m + y) * 3) + z;
}

inline int64 solve() {
    priority_queue<qelem, vector<qelem>, greater<qelem>> q;
    vi64 len(((n * m) * 3) + 2, kInf);
    int64 res = kInf;
    for (int i = 0; i < m; ++i) {
        int ind = get_id(0, i, 0);
        len[ind] = 0LL;
        q.push(qelem(0LL, piii(0, pii(i, 0))));
        res = min(res, static_cast<int64>(c[n - 1] + max(0, a[0][i] - a[n - 1][i])));
    }
    while (!q.empty()) {
        qelem cur = q.top();
        q.pop();
        int x = cur.second.first;
        int y = cur.second.second.first;
        int z = cur.second.second.second;
        int ind = get_id(x, y, z);
        int64 cur_len = len[ind];
        if (cur_len != cur.first) {
            continue;
        }
        if (z < 2) {
            int ny = (y + 1) % m;
            int nx = x;
            int nz = 1;
            int64 new_len = cur_len;
            int nind = get_id(nx, ny, nz);
            if (len[nind] > new_len) {
                len[nind] = new_len;
                q.push(qelem(new_len, piii(nx, pii(ny, nz))));
            }
        }
        if (z) {
            int nx = x;
            int ny = y;
            int nz = 0;
            int64 new_len = cur_len + c[x];
            int nind = get_id(nx, ny, nz);
            if (len[nind] > new_len) {
                len[nind] = new_len;
                q.push(qelem(new_len, piii(nx, pii(ny, nz))));
            }
        }
        if (lnk[y][x] != n - 1) {
            int ny = y;
            int nx = b[y][lnk[y][x] + 1].second;
            int nz = 2;
            int64 new_len = cur_len;
            int nind = get_id(nx, ny, nz);
            if (len[nind] > new_len) {
                len[nind] = new_len;
                q.push(qelem(new_len, piii(nx, pii(ny, nz))));
            }
        }
        if (lnk[y][x] != 0) {
            int ny = y;
            int nx = b[y][lnk[y][x] - 1].second;
            int nz = 2;
            int64 new_len = cur_len + a[x][y] - a[nx][y];
            int nind = get_id(nx, ny, nz);
            if (len[nind] > new_len) {
                len[nind] = new_len;
                q.push(qelem(new_len, piii(nx, pii(ny, nz))));
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        res = min(res, len[get_id(n - 1, i, 0)]);
    }
    return res;
}

int main() {
#ifdef _PKHAU_DEBUG
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int nt;
    cin >> nt;
    for (;nt--;) {
        init();
        int64 res = solve();
        cout << res << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

#define fin stdin
#define fout stdout
//FILE *fin = fopen("x.in", "r"), *fout = fopen("x.out", "w");

typedef long long i64;

const int nmax = 2000;

int n;
map<i64, int> mp;

struct pct {
    int x, y;
} v[nmax + 1];

i64 aria;
int ord[nmax + 1], pos[nmax + 1];

int ia, ib, ic;

struct lin {
    int x, y;
    pair<int, int> p;

    bool operator < (const lin &shp) const {
        return 1LL * p.first * shp.p.second < 1LL * p.second * shp.p.first;
    }
};
vector<lin> wlin;

pair<int, int> panta;
inline bool cmp (int a, int b) {
    return 1LL * (v[a].y - v[b].y) * panta.second < 1LL * panta.first * (v[a].x - v[b].x);
}

inline i64 A2 (int a, int b, int c) {
    return 1LL * v[a].x * v[b].y - 1LL * v[a].y * v[b].x
         + 1LL * v[b].x * v[c].y - 1LL * v[b].y * v[c].x
         + 1LL * v[c].x * v[a].y - 1LL * v[c].y * v[a].x;
}

void solve_other_lines () {
    for (int i = 1; i <= n; ++ i) {
        for (int j = i + 1; j <= n; ++ j) {
            if (v[i].x != v[j].x) {
                lin aux;

                aux.p = {(v[i].y - v[j].y), (v[i].x - v[j].x)};
                if (aux.p.second < 0)
                    aux.p.second *= -1, aux.p.first *= -1;

                aux.x = i; aux.y = j;

                wlin.push_back(aux);
            }
        }
    }

    sort(wlin.begin(), wlin.end());
    for (int i = 1; i <= n; ++ i) {
        ord[i] = i;
    }

    panta = {-1e9 - 1, 1};
    sort(ord + 1, ord + n + 1, cmp);
    for (int i = 1; i <= n; ++ i) {
        pos[ord[i]] = i;
    }

    int n2;
    for (n2 = 1; (n2 << 1) <= n; n2 <<= 1) {
    }

    for (auto q : wlin) {
        assert(abs(pos[q.x] - pos[q.y]) == 1);

        swap(ord[pos[q.x]], ord[pos[q.y]]);
        swap(pos[q.x], pos[q.y]);

        int st = max(pos[q.x], pos[q.y]);


        /// cauta in sus
        int aux = st;
        for (int step = n2; step > 0; step >>= 1) {
            if (aux + step <= n && A2(ord[st - 1], ord[st], ord[aux + step]) <= 2 * aria) {
                aux += step;
            }
        }

        if (A2(ord[st - 1], ord[st], ord[aux]) == 2 * aria) {
            ia = ord[st - 1]; ib = ord[st]; ic = ord[aux];
        }

        /// cauta in jos
        aux = st;
        for (int step = n2; step > 0; step >>= 1) {
            if (aux - step > 0 && A2(ord[st - 1], ord[st], ord[aux - step]) <= 2 * aria) {
                aux -= step;
            }
        }

        if (A2(ord[st - 1], ord[st], ord[aux]) == 2 * aria) {
            ia = ord[st - 1]; ib = ord[st]; ic = ord[aux];
        }
    }
}

int main() {
    fscanf(fin, "%d%lld", &n, &aria);

    for (int i = 1; i <= n; ++ i) {
        fscanf(fin, "%d%d", &v[i].x, &v[i].y);
        mp[v[i].x] = i;
    }

    ia = ib = ic = -1;
    for (int i = 1; i <= n; ++ i) {
        for (int j = i + 1; j <= n; ++ j) {
            if (v[i].x == v[j].x) {
                int dist = abs(v[i].y - v[j].y);

                if (2 * aria % dist != 0)
                    continue;

                i64 cautx = v[i].x + 2 * aria / dist;

                if (mp.find(cautx) != mp.end()) {
                    ia = i; ib = j; ic = mp[cautx];
                }

                cautx = v[i].x - 2 * aria / dist;
                if (mp.find(cautx) != mp.end()) {
                    ia = i; ib = j; ic = mp[cautx];
                }
            }
        }
    }

    solve_other_lines();

    if (ia == -1) {
        fprintf(fout, "No\n");
    } else {
        fprintf(fout, "Yes\n%d %d\n%d %d\n%d %d\n", v[ia].x, v[ia].y, v[ib].x, v[ib].y, v[ic].x, v[ic].y);
    }

    return 0;
}
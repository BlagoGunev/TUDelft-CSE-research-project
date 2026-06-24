#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const int Maxn = 100005;
const ld lim = 1e12l;
const int Maxt = 70;

struct point {
    ld x, y;
    ld Len() const {
        return sqrt(x * x + y * y);
    }
    point Scale(ld a) const { return {a * x, a * y}; }
    point Norm() const {
        ld l = Len();
        return Scale(1.0l / l);
    }
    ld operator^(const point &oth) const {
        return x * oth.y - y * oth.x;
    }
    point operator-(const point &oth) const {
        return {x - oth.x, y - oth.y};
    }
    point operator+(const point &oth) const {
        return {x + oth.x, y + oth.y};
    }
    point Rot() const { return {-y, x}; }
};

point P1, P2;
int n;
point C[Maxn];
ld R[Maxn];

int getStatus(int ind, const point &p)
{
    ld st = (P1 - p).Len() - (C[ind] - p).Len();
    if (st <= -R[ind]) return -1;
    if (st < R[ind]) return 0;
    return 1;
}

ld getLeft(int ind, int val, const point &m, const point &norm)
{
    if (getStatus(ind, m) != val) return -1;
    ld lef = 0, rig = lim;
    for (int i = 0; i < Maxt; i++) {
        ld mid = (lef + rig) / 2.0l;
        if (getStatus(ind, m + norm.Scale(mid)) == val)
            lef = mid;
        else rig = mid;
    }
    return lef;
}

ld getRight(int ind, int val, const point &m, const point &norm)
{
    if (getStatus(ind, m) == val) return 0;
    ld lef = 0, rig = lim;
    for (int i = 0; i < Maxt; i++) {
        ld mid = (lef + rig) / 2.0l;
        if (getStatus(ind, m + norm.Scale(mid)) == val)
            rig = mid;
        else lef = mid;
    }
    return rig;
}

ld Best(const point &mid, const point &norm, bool sw)
{
    vector <ldld> V;
    for (int i = 0; i < n; i++) {
        int a = -1, b = 1;
        if ((((P2 - P1) ^ (C[i] - P1)) < 0) ^ sw)
            swap(a, b);
        V.push_back(ldld(getLeft(i, a, mid, norm), getRight(i, b, mid, norm)));
    }
    sort(V.begin(), V.end());
    ld cur = 0.0l;
    for (int i = 0; i < V.size(); i++)
        if (cur > V[i].first)
            cur = max(cur, V[i].second);
    return cur;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin >> P1.x >> P1.y >> P2.x >> P2.y;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> C[i].x >> C[i].y >> R[i];
    point mid = P1.Scale(0.5l) + P2.Scale(0.5l);
    point norm = (P2 - P1).Norm().Rot();
    ld res = Best(mid, norm, false);
    norm = norm.Rot().Rot();
    res = min(res, Best(mid, norm, true));
    point cent = mid + norm.Scale(res);
    ld ans = (cent - P1).Len();
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
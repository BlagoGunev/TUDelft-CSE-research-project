#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000, MAXM = MAXN;
const long long INF = LLONG_MAX;
int n, m, k, s, di, pi;
int drate[MAXN + 1], prate[MAXN + 1];
int dbest[MAXN + 1], pbest[MAXN + 1];
vector<pair<int, int>> dcost, pcost;

bool ok(int day) {
    long long dollar = drate[dbest[day]];
    long long pound = prate[pbest[day]];
    long long sum = 0;
    di = pi = 0;
    for (int i = 0; i < k; i++) {
        long long ds = di < dcost.size() ? dcost[di].first * dollar : INF;
        long long ps = pi < pcost.size() ? pcost[pi].first * pound : INF;
        if (ds < ps) {
            sum += ds;
            di++;
        } else {
            sum += ps;
            pi++;
        }
    }
    return sum <= s;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &s);
    int min_idx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &drate[i]);
        if (drate[i] < drate[min_idx])
            min_idx = i;
        dbest[i] = min_idx;
    }
    min_idx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &prate[i]);
        if (prate[i] < prate[min_idx])
            min_idx = i;
        pbest[i] = min_idx;
    }
    for (int i = 0; i < m; i++) {
        int t, c;
        scanf("%d%d", &t, &c);
        if (t == 1)
            dcost.emplace_back(c, i + 1);
        else
            pcost.emplace_back(c, i + 1);
    }
    sort(dcost.begin(), dcost.end());
    sort(pcost.begin(), pcost.end());

    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (ok(mid))
            right = mid;
        else
            left = mid + 1;
    }
    if (left == n)
        puts("-1");
    else {
        printf("%d\n", left + 1);
        ok(left);
        for (int i = 0; i < di; i++)
            printf("%d %d\n", dcost[i].second, dbest[left] + 1);
        for (int i = 0; i < pi; i++)
            printf("%d %d\n", pcost[i].second, pbest[left] + 1);
    }
}
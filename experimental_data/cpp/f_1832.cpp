# include <bits/stdc++.h>

using namespace std;

const int N = 2005;

struct Interval {
    int l, r;
    Interval(int left = 0, int right = 0) : l(left), r(right) {}
};

// Global variables
int n, k, x, m, num_unique_points;
vector<Interval> intervals(N);
vector<int> unique_points;
int optimal_indices[N][N];
long long dp[N][N];
long long f[N];
int h[N];
long long intersection_values[N << 1][N];

// Calculates intersection length between two intervals
int intersect(Interval interval_1, Interval interval_2) {
    if (interval_1.l > interval_2.l) swap(interval_1, interval_2);
    if (interval_1.r <= interval_2.l) return 0;
    return min(interval_1.r, interval_2.r) - interval_2.l;
}

// Computes dp array using dynamic programming
void compute_dp() {
    for (int i = 1; i <= num_unique_points; ++i) {
        for (int j = 1; j <= n; ++j) {
            intersection_values[i][j] = intersection_values[i][j - 1] +
                intersect(Interval(unique_points[i], unique_points[i] + m), intervals[j]);
        }
    }

    for (int d = n - 1; d >= 0; --d) {
        for (int l = 1; l <= n - d; ++l) {
            int r = l + d;
            int pl = (l == 1) ? 1 : optimal_indices[l - 1][r];
            int pr = (r == n) ? num_unique_points : optimal_indices[l][r + 1];

            dp[l][r] = LLONG_MIN;
            for (int i = pl; i <= pr; ++i) {
                long long val = intersection_values[i][r] - intersection_values[i][l - 1];
                if (dp[l][r] < val) {
                    optimal_indices[l][r] = i;
                    dp[l][r] = val;
                }
            }
        }
    }
}

// Computes optimal results for a given slope
pair<int, long long> compute(long long slp) {
    for (int i = 1; i <= n; ++i) {
        pair<long long, int> best = {dp[1][i], 0};
        for (int j = 1; j < i; ++j) {
            best = max(best, {f[j] + dp[j + 1][i], -h[j]});
        }
        f[i] = best.first - slp;
        h[i] = -best.second + 1;
    }
    return {h[n], f[n]};
}

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> n >> k >> x >> m;

    long long ans = 1LL * x * n - 1LL * m * n;

    for (int i = 1; i <= n; ++i) {
        cin >> intervals[i].l >> intervals[i].r;
        ans -= intervals[i].r - intervals[i].l;
        unique_points.push_back(intervals[i].l + m > x ? x - m : intervals[i].l);
        unique_points.push_back(intervals[i].r - m < 0 ? 0 : intervals[i].r - m);
    }

    sort(intervals.begin() + 1, intervals.begin() + n + 1, [] (Interval a, Interval b) {
        return a.l + a.r < b.l + b.r;
    });

    sort(unique_points.begin(), unique_points.end());
    unique_points.resize(unique(unique_points.begin(), unique_points.end()) - unique_points.begin());

    num_unique_points = unique_points.size();
    unique_points.insert(unique_points.begin(), 0);

    compute_dp();

    long long cl = 0, cr = 2000000000000LL, ca = 0, cc = 0;

    // Binary search on the slope
    while (cl <= cr) {
        long long cm = (cl + cr) / 2;
        auto res = compute(cm);
        if (res.first <= k) {
            ca = res.second;
            cc = cm;
            cr = cm - 1;
        } else {
            cl = cm + 1;
        }
    }

    cout << ca + ans + cc * k << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
const int N = 10;
int h[N][N];
double e[N][N];
pair<int, int> step(int i, int j, int steps) {
    int orig_i = i, orig_j = j;
    if(i % 2) {
        j += steps;
        if(j >= N) {
            i--;
            j = N - 1 - (j - N);
        }
    } else {
        j -= steps;
        if(j < 0) {
            i--;
            j = -j - 1;
        }
    }
    if(i < 0) {
        return {orig_i, orig_j};
    } else if(h[i][j] == 0) {
        return {i, j};
    } else {
        return e[i][j] < e[i - h[i][j]][j] ? pair{i, j} : pair{i - h[i][j], j};
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> h[i][j];
        }
    }
    vector<int> increasing(N), decreasing(N);
    iota(increasing.begin(), increasing.end(), 0);
    iota(decreasing.begin(), decreasing.end(), 0);
    reverse(decreasing.begin(), decreasing.end());
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         for(int steps = 1; steps <= 6; steps++) {
    //             err(i, j, steps, step(i,j,steps));
    //         }
    //     }
    // }
    for(int i = 0; i < N; i++) {
        for(int j : i % 2 ? decreasing : increasing) {
            if(i == 0 and j == 0) {
                e[i][j] = 0;
            } else {
                double multiplier = 1.0;
                for(int steps = 1; steps <= 6; steps++) {
                    auto [ii, jj] = step(i, j, steps);
                    if(ii == i and jj == j) {
                        e[i][j] += 1 / 6.0;
                        multiplier -= 1 / 6.0;
                    } else {
                        e[i][j] += (1 + e[ii][jj]) / 6;
                    }
                }
                e[i][j] /= multiplier;
            }
        }
    }
    cout << fixed << setprecision(6) << e[N-1][0] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int T, N;
int mx, mn;
int A[20];

void solve() {
    cin >> N;
    mx = mn = 0;
    for (int n = 0; n < N; n++) {
        cin >> A[n];
        if (A[n] < A[mn]) mn = n;
        if (A[n] > A[mx]) mx = n;
    }
    cout << 2*N-1 << '\n';
    if (A[mx] < -A[mn]) {
        for (int n = 0; n < N; n++) cout << n+1 << ' ' << mn+1 << '\n';
        for (int n = N; n > 1; n--) cout << n-1 << ' ' << n << '\n';
    }
    else {
        for (int n = 0; n < N; n++) cout << n+1 << ' ' << mx+1 << '\n';
        for (int n = 1; n < N; n++) cout << n+1 << ' ' << n << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--) solve();
}
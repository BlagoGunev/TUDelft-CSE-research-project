#include <bits/stdc++.h>
#define inf 1<<30
#define MOD 998244353
#define NMAX 3005
using namespace std;
int N, M, st, dr, i, j, sol, A[NMAX], H;
bool check (int k) {
    int aux[NMAX];
    for (int i = 1; i <= k; ++i)
        aux[i] = A[i];
    sort (aux + 1, aux + k + 1);
    long long sum = 0;
    for (int i = k; i >= 0; i -=2)
        sum += aux[i];
    if (sum > H)
        return false;
    return true;
}
int main() {
    cin >> N >> H;
    for (i = 1; i <= N; ++i)
        cin >> A[i];
    int st = 1;
    int dr = N;
    while (st <= dr) {
        int mid = (st + dr) / 2;
        if (check(mid)) {
            sol = mid;
            st = mid + 1;
        }
        else dr = mid - 1;
    }
    cout << sol;
    return 0;
}
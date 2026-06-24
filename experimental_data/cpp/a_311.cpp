#include <bits/stdc++.h>

using namespace std;



typedef long long LL;

typedef pair<int, int> II;



int main() {

    #ifdef LOCAL

        freopen("Data.inp", "r", stdin);

        freopen("Data.out", "w", stdout);

    #endif



    int n, k; cin >> n >> k;

    if (k >= n * (n - 1) / 2) {

        puts("no solution");

        return 0;

    }



    for (int i = 1; i <= n; ++i) printf("0 %d\n", i);

    return 0;

}
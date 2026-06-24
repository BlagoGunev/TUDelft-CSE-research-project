#include <bits/stdc++.h>



using namespace std;



int res = 0,a, b, n, ans;



int main() {

    //freopen("codef.inp", "r", stdin);

    //freopen("codef.out", "w", stdout);

    scanf("%d", &n);



    for (int i = 1; i <= n; ++i) {

        scanf("%d %d\n", &a, &b);

        res -= a; res += b;

        ans = max(ans, res);

    }

    printf("%d\n", ans);

    return 0;

}
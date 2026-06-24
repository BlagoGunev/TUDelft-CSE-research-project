#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



inline int rd() {

    int x = 0;

    bool f = 0;

    char c = getchar();

    for (; !isdigit(c); c = getchar()) f |= (c == '-');

    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);

    return f ? -x : x;

}



int a[107];



int main() {

    int n = rd();

    if (n <= 100) {

        int ans = 100;

        for (int i = 1; i <= n; ++i) a[i] = (a[i - 1] ^ rd());

        for (int l = 1; l < n; ++l)

            for (int m = l; m < n; ++m)

                for (int r = m + 1; r <= n; ++r)

                    if ((a[m] ^ a[l - 1]) > (a[r] ^ a[m]))

                        ans = min(ans, r - l - 1);

        printf("%d\n", ans == 100 ? -1 : ans);

    } else puts("1");

    return 0;

}
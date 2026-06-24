#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <sstream>
#include <cmath>
#include <ctime>
#include <climits>
#include <list>
#include <map>
#include <queue>
#include <cassert>

using namespace std;

typedef long long ll;

int n, k, a;
int l1, r1, l2, r2;

int ans[100001];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        l2 = max(1, i - k);
        r2 = min(n, i + k);
        if (a == 0) {
            ans[i] = r2 - l2 + 1;
        }
        else {
            l1 = max(1, a - k);
            r1 = min(n, a + k);

            ans[i] = ans[a] + (r2 - l2 + 1) - (r1 >= l2 ? (r1 - l2 + 1) : 0);
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}
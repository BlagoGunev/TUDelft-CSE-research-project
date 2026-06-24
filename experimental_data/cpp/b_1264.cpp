#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000005;

int a, b, c, d;
int n;
int ans[N];

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    n = a + b + c + d;
    if (abs((a + c) - (b + d)) > 1) {
        printf("NO\n");
        return 0;
    }
    if (a + c > b + d) {
        for (int i = 1; i <= n; i++) {
            ans[i] = 1 - i % 2;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            ans[i] = i % 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (c > 0 && ans[i] == 0) {
            ans[i] = 2;
            c--;
        }
    }

    for (int i = 1; i <= n; i++) {
        if ((i == 1 || ans[i - 1] == 2) && (i == n || ans[i + 1] == 2) && ans[i] == 1) {
            if (d > 0) {
                ans[i] = 3;
                d--;
            }
        }
    }

    if (c > 0 || d > 0) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
	return 0;
}
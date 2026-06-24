#include <cstdio>
#include <cstring>

int nca, n, m, k;

bool solve(int n, int m) {
    int d = n < m ? n : m;
    if (0 == d % (k + 1)) {
        return true;
    }
    if (k == 1)return (n + m) % 2;
    return ((d / (k + 1)) % 2) ^ ((n + m) % 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &nca, &k) != EOF) {
        for (int i = 0; i < nca; i++) {
            scanf("%d%d", &n, &m);
            if (solve(n, m)) {
                puts("+");
            }
            else {
                puts("-");
            }
        }
    }
    return 0;
}
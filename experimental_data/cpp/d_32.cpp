#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int n, m, k;
char s[301][301];

inline void out(int i, int j) {
    printf("%d %d\n", i+1, j+1);
}

inline void gao() {
    for (int r = 1; r < n && r < m; r ++) {
        for (int i = r; i < n-r; i ++) {
            for (int j = r; j < m-r; j ++) {
                if (s[i][j] == '*' && s[i-r][j] == '*' && s[i][j-r] == '*' && s[i+r][j] == '*' && s[i][j+r] == '*')
                    k --;
                if (k == 0) {
                    out(i, j);
                    out(i-r, j);
                    out(i+r, j);
                    out(i, j-r);
                    out(i, j+r);
                    return;
                }
            }
        }
    }
    puts("-1");
}

int main() {
//  freopen("in.txt", "r", stdin);
    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        for (int i = 0; i < n; i ++)
            scanf("%s", s[i]);
        gao();
    }
    return 0;
}
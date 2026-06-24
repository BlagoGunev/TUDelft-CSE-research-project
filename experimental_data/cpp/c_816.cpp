#include <bits/stdc++.h>

using namespace std;
int grid[101][101];
int grid2[101][101];
int AN[101], AM[101];
int AN2[101], AM2[101];

void apply1(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] -= (AN[i]);
        }
    }
}

void apply2(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] -= (AM[j]);
        }
    }
}

void apply21(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid2[i][j] -= (AM2[j]);
        }
    }
}

void apply22(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid2[i][j] -= (AN2[i]);
        }
    }
}

bool check_done(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool check_done2(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid2[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &grid[i][j]);
            grid2[i][j] = grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int mini = INT_MAX;
        for (int j = 0; j < m; ++j) {
            mini = min(mini, grid[i][j]);
        }
        AN[i] = mini;
        ans += mini;
    }
    for (int i = 0; i < m; ++i) {
        int mini = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mini = min(mini, grid2[j][i]);
        }
        AM2[i] = mini;
        ans2 += mini;
    }
    apply1(n, m);
    apply21(n, m);
    for (int i = 0; i < m; ++i) {
        int mini = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mini = min(mini, grid[j][i]);
        }
        AM[i] = mini;
        ans += mini;
    }
    for (int i = 0; i < n; ++i) {
        int mini = INT_MAX;
        for (int j = 0; j < m; ++j) {
            mini = min(mini, grid2[i][j]);
        }
        AN2[i] = mini;
        ans2 += mini;
    }
    apply2(n, m);
    apply22(n, m);
    if (check_done(n, m) && check_done2(n, m)) {
        if (ans < ans2) {
            printf("%d\n", ans);
            for (int i = 0; i < n; ++i) {
                while (AN[i]--) {
                    printf("row %d\n", i + 1);
                }
            }
            for (int i = 0; i < m; ++i) {
                while (AM[i]--) {
                    printf("col %d\n", i + 1);
                }
            }
        } else {
            printf("%d\n", ans2);
            for (int i = 0; i < n; ++i) {
                while (AN2[i]--) {
                    printf("row %d\n", i + 1);
                }
            }
            for (int i = 0; i < m; ++i) {
                while (AM2[i]--) {
                    printf("col %d\n", i + 1);
                }
            }
        }
    } else if (check_done(n, m)) {
        printf("%d\n", ans);
        for (int i = 0; i < n; ++i) {
            while (AN[i]--) {
                printf("row %d\n", i + 1);
            }
        }
        for (int i = 0; i < m; ++i) {
            while (AM[i]--) {
                printf("col %d\n", i + 1);
            }
        }
    } else if (check_done2(n, m)) {
        printf("%d\n", ans2);
        for (int i = 0; i < n; ++i) {
            while (AN2[i]--) {
                printf("row %d\n", i + 1);
            }
        }
        for (int i = 0; i < m; ++i) {
            while (AM2[i]--) {
                printf("col %d\n", i + 1);
            }
        }
    } else {
        puts("-1");
    }
}
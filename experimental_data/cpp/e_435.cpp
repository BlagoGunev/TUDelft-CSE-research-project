#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 104;

int n, m;
int a[N][N];
int gen[N][N];

int fil[5];
bool inq[5];

bool check() {
    bool flag = 1;
    for(int i = 1; i <= n + 1; i += 2) {
        for(int j = 1; j <= m + 1; j += 2) {
            gen[i][j] = fil[1], gen[i][j + 1] = fil[2];
        }
        bool tg = 1;
        for(int j = 1; j <= m; j++) {
            if(a[i][j] && gen[i][j] != a[i][j])
                tg = 0;
        }
        if(!tg) {
            for(int j = 1; j <= m + 1; j += 2) {
                gen[i][j] = fil[2], gen[i][j + 1] = fil[1];
            }
            for(int j = 1; j <= m; j++) {
                if(a[i][j] && gen[i][j] != a[i][j])
                    flag = 0;
            }
        }
        for(int j = 1; j <= m + 1; j += 2) {
            gen[i + 1][j] = fil[3], gen[i + 1][j + 1] = fil[4];
        }
        tg = 1;
        for(int j = 1; j <= m; j++) {
            if(a[i + 1][j] && gen[i + 1][j] != a[i + 1][j])
                tg = 0;
        }
        if(!tg) {
            for(int j = 1; j <= m + 1; j += 2) {
                gen[i + 1][j] = fil[4], gen[i + 1][j + 1] = fil[3];
            }
            for(int j = 1; j <= m; j++) {
                if(a[i + 1][j] && gen[i + 1][j] != a[i + 1][j])
                    flag = 0;
            }
        }
    }
    if(flag)
        return 1;
    flag = 1;
    for(int j = 1; j <= m + 1; j += 2) {
        for(int i = 1; i <= n + 1; i += 2) {
            gen[i][j] = fil[1], gen[i + 1][j] = fil[2];
        }
        bool tg = 1;
        for(int i = 1; i <= n; i++) {
            if(a[i][j] && gen[i][j] != a[i][j])
                tg = 0;
        }
        if(!tg) {
            for(int i = 1; i <= n + 1; i += 2) {
                gen[i][j] = fil[2], gen[i + 1][j] = fil[1];
            }
            for(int i = 1; i <= n; i++) {
                if(a[i][j] && gen[i][j] != a[i][j])
                    flag = 0;
            }
        }
        for(int i = 1; i <= n + 1; i += 2) {
            gen[i][j + 1] = fil[3], gen[i + 1][j + 1] = fil[4];
        }
        tg = 1;
        for(int i = 1; i <= n; i++) {
            if(a[i][j + 1] && gen[i][j + 1] != a[i][j + 1])
                tg = 0;
        }
        if(!tg) {
            for(int i = 1; i <= n + 1; i += 2) {
                gen[i][j + 1] = fil[4], gen[i + 1][j + 1] = fil[3];
            }
            for(int i = 1; i <= n; i++) {
                if(a[i][j + 1] && gen[i][j + 1] != a[i][j + 1])
                    flag = 0;
            }
        }
    }
    if(flag)
        return 1;
    return 0;
}

void dfs(int x) {
    if(x == 5) {
        if(check()) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    printf("%d", gen[i][j]);
                }
                printf("\n");
            }
            exit(0);
        }
        return;
    }
    for(int i = 1; i <= 4; i++) {
        if(!inq[i]) {
            inq[i] = 1;
            fil[x] = i;
            dfs(x + 1);
            inq[i] = 0;
        }
    }
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        char str = getchar();
        while(str < 33 || str > 126)
            str = getchar();
        int j = 0;
        while(str >= 33 && str <= 126) {
            a[i][++j] = str - '0';
            str = getchar();
        }
    }
    dfs(1);
    printf("0\n");
    return 0;
}
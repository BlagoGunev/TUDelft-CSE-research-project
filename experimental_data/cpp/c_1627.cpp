#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int cnt[200000];
int ans[200000];
int connected[200000][2];
int edgeid[200000][2];
void work() {
    int n;
    scanf("%d", &n);
    memset(cnt, 0, n * sizeof(int));
    bool allow = true;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        if (!allow)continue;
        connected[u][cnt[u]] = v;
        connected[v][cnt[v]] = u;
        edgeid[u][cnt[u]] = i;
        edgeid[v][cnt[v]] = i;
        cnt[u]++; cnt[v]++;
        if (cnt[u] > 2 || cnt[v] > 2) {
            allow = false;
        }
    }
    if (!allow) { printf("-1\n"); return; }
    int b;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 1)b = i;
    }
    int last_visited = b;
    int tmp = 5;
    ans[edgeid[b][0]] = 2;
    b = connected[b][0];
    while (cnt[b] == 2) {
        int choose = ((last_visited == connected[b][0]) ? 1 : 0);
        ans[edgeid[b][choose]] = tmp;
        tmp = 7 - tmp;
        last_visited = b;
        b = connected[b][choose];
        
    }
    for (int i = 0; i < n - 1; i++)
        printf("%d ", ans[i]);
    printf("\n");
}
int main()
{
    //calc_prime();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        work();
    return 0;
}
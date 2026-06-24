#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int maxn = 200002;
int graph[maxn];
int Prev[maxn];
int top[maxn];
int len[maxn];
int a[maxn];
int res[maxn];
int T;
void Insert(int u, int v, int w){
    T++;
    graph[T] = v;
    Prev[T] = top[u];
    top[u] = T;
    len[T] = w;
}
int n;
int b[maxn];
long long s[maxn];
void build(int u, int h){
    b[h - 1] ++;
    b[(lower_bound(s+1, s + h, s[h] - a[u]) - s) - 1] --;
    b[h] = 0;
    for(int i = top[u]; i; i = Prev[i]){
        int v = graph[i];
        int w = len[i];
        s[h + 1] = s[h] + w;
        build(v, h + 1);
    }
    res[u] = b[h];
    b[h-1] += b[h];
}
void t_main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", a+i);
    for(int i = 2, u, w; i <= n; i ++){
        scanf("%d %d", &u, &w);
        Insert(u, i, w);
    }
    build(1, 1);
    for(int i = 1; i <= n; i ++) printf("%d%c", res[i], " \n"[i==n]);
}
void run(){
    int t = 1;
    while(t --) t_main();
}
int main(){
    run();
    return 0;
}
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <chrono>
#include <random>
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;
typedef long long ll;
template <class T>
void read(T &x){
    char c;
    bool op = 0;
    while(c = getchar(), c < '0' || c > '9')
        if(c == '-') op = 1;
    x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    if(op) x = -x;
}
template <class T>
void write(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 300005;
int n, tot, ls[N], rs[N], fath[N];
int fa[N];

int findfa(int u){
    return fa[u] == u ? u : fa[u] = findfa(fa[u]);
}
void dfs(int u){
    //printf("u = %d, ls = %d, rs = %d\n", u, ls[u], rs[u]);
    if(u <= n){
        write(u), space;
        return;
    }
    dfs(ls[u]), dfs(rs[u]);
}

int main(){

    read(n), tot = n;
    for(int i = 1; i <= 2 * n; i++) fa[i] = i;
    for(int i = 1, a, b; i < n; i++){
        read(a), read(b);
        a = findfa(a), b = findfa(b);
        fath[a] = fath[b] = ++tot;
        ls[tot] = a, rs[tot] = b;
        fa[a] = fa[b] = tot;
    }
    dfs(tot), enter;

    return 0;
}
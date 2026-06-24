#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
using namespace std;

#define fst first
#define snd second
#define elif else if
#define mp make_pair
#define for(i,a,n) for (int i=(a);i<(n);i++)
#define for_b(i,a,n) int i=(n);while(--i>=(a))
#define readf(x) freopen((x), "r", stdin)
#define writef(x) freopen((x), "w", stdout)
#define all(x) (x).begin(),(x).end()

template <typename T>
void umin(T x, T &y) {
    if (x < y) y = x;
}

template <typename T>
void umax(T x, T &y) {
    if (x > y) y = x;
}

template <typename T>
T getint() {
    T x = 0, p = 1;
    char ch;
    do {ch = getchar();} while(ch <= ' ');
    if (ch == '-') p = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * p;
}

typedef long long ll;
typedef long double ld;

const int INF = (int)1e9;
const int N = (int)1e3+1;
const ll mod = (ll)1e9+7;
const ll LLINF = (ll)1e17;



    int n, m;
    bool pos[N][N];
    pair <int, int> c[N], l[N];



int main()
{

    //readf(".in");
    //writef(".out");

    n = getint<int>(), m = getint<int>();
    for (i, 0, max(n, m)) c[i].fst = l[i].fst = INF;
    for (i, 0, n) for (j, 0, m) {
        pos[i][j] = (bool)getint<int>();
        if (pos[i][j]) {
            umin(j, c[i].fst);
            umax(j, c[i].snd);
            umin(i, l[j].fst);
            umax(i, l[j].snd);
        }
    }
    int res = 0;
    for (i, 0, n) for (j, 0, m) {
        if (!pos[i][j]) {
            if (j > c[i].fst) res++;
            if (j < c[i].snd) res++;
            if (i > l[j].fst) res++;
            if (i < l[j].snd) res++;
        }
    }
    printf("%d", res);

    return 0;
}
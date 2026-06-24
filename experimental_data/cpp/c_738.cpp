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
const int N = (int)2e5+1;
const ll mod = (ll)1e9+7;
const ll LLINF = (ll)1e17;



    int n, t, s, k;
    int g[N];
    pair <int, int> car[N];



bool can(int idx) {
    int time = 2 * s, pos = 0;
    int fuel = car[idx].snd;
    for (i, 0, k) {
        if (g[i] - pos > fuel) return false;
        time -= min(fuel - g[i] + pos, g[i] - pos);
        pos = g[i];
    }
    if (time > t) return false;
    return true;
}

int main()
{

    //readf(".in");
    //writef(".out");

    scanf("%d%d%d%d", &n, &k, &s, &t);
    for (i, 0, n) {
        car[i].fst = getint<int>();
        car[i].snd = getint<int>();
    }
    for (i, 0, k) g[i] = getint<int>();
    g[k++] = s;
    sort(g, g + k);
    sort(car, car + n, [&](pair<int, int> x, pair<int, int> y) {
        return x.snd < y.snd;
    });
    int l = 0, r = n - 1;
    if (!can(r)) {
        puts("-1");
        return 0;
    }
    for (i, 0, 32) {
        int mid = (l + r) / 2;
        if (can(mid)) r = mid;
        else l = mid;
    }
    cout << min_element(car + r, car + n)->fst;

    return 0;
}
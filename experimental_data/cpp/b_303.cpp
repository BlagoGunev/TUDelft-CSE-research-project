#include <functional>

#include <algorithm>

#include <iostream>

#include <cstring>

#include <cassert>

#include <fstream>

#include <cstdlib>

#include <numeric>

#include <iomanip>

#include <cstdio>

#include <vector>

#include <math.h>

#include <queue>

#include <stack>

#include <ctime>

#include <set>

#include <map>



using namespace std;



typedef long long ll;

typedef long double ld;



template <typename T>

T nextInt() {

    T x = 0, p = 1;

    char ch;

    do { ch = getchar(); } while(ch <= ' ');

    if (ch == '-') {

        p = -1;

        ch = getchar();

    }

    while(ch >= '0' && ch <= '9') {

        x = x * 10 + (ch - '0');

        ch = getchar();

    }

    return x * p;

}

const int maxN = (int)3e5 + 10;

const int INF = (int)1e9;

const int mod = (int)1e9 + 7;

const ll LLINF = (ll)1e18 + 5;



int main() {



    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);



    int n, m, x, y, a, b;

    cin >> n >> m >> x >> y >> a >> b;

    int g = __gcd(a, b);

    a /= g; b /= g;

    int k = min(n / a, m / b);



    int dx = k * a, dy = k * b;



    int x1, y1, x2, y2;

    x1 = x - (dx + 1) / 2;

    x2 = x + dx / 2;

    y1 = y - (dy + 1) / 2;

    y2 = y + dy / 2;

    if (x1 < 0) {

        x2 -= x1;

        x1 = 0;

    }

    if (x2 > n) {

        x1 -= x2 - n;

        x2 = n;

    }

    if (y1 < 0) {

        y2 -= y1;

        y1 = 0;

    }

    if (y2 > m) {

        y1 -= y2 - m;

        y2 = m;

    }

    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

    return 0;

}
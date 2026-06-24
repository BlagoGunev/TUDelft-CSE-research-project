#include <functional>

#include <algorithm>

#include <iostream>

#include <cstring>

#include <cassert>

#include <fstream>

#include <cstdlib>

#include <numeric>

#include <iomanip>

#include <bitset>

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

const int maxN = (int)1e3 + 10;

const int INF = (int)1e9 + 5;

const int mod = (int)1e9 + 7;

const ll LLINF = (ll)4e18 + 5;



char s[maxN][maxN];

int n, m;

int res = INF;



int c[maxN][maxN];



int get(int x2, int y2, int x, int y) {

    if (x2 > n || y2 > m) return 0;

    return c[x2][y2] - c[x - 1][y2] - c[x2][y - 1] + c[x - 1][y - 1];

}



int calc(int i, int j, int x, int y) {

    if (get(i + x - 1, j + y - 1, i, j) != x * y) return 0;

    int ret = x * y;

    while(true) {

        int a = get(i + x, j + y - 1, i + 1, j);

        int b = get(i + x - 1, j + y, i, j + 1);

        if (a == x * y && b == x * y) return false;

        if (a == x * y) {

            ret += y;

            i++;

        } else if (b == x * y) {

            ret += x;

            j++;

        } else return ret;

    }

}



int main() {



    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);



    n = nextInt<int>();

    m = nextInt<int>();



    int cnt = 0;

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= m; ++j) {

            s[i][j] = getchar();

            c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];

            if (s[i][j] == 'X') {

                ++c[i][j];

                cnt++;

            }

        }

        getchar();

    }



    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= m; ++j) {

            if (s[i][j] == 'X') {

                int res = INF;

                for (int x = 1; x <= n; ++x) {

                    for (int y = 1; y <= m && x * y < res; ++y) {

                        if (calc(i, j, x, y) == cnt) {

                            res = min(res, x * y);

                        }

                    }

                }

                if (res == INF) res = -1;

                printf("%d\n", res);

                return 0;

            }

        }

    }

    return 0;

}
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>

using namespace std;

typedef long long li;
typedef long double ld;

template <typename T>
T sqr(const T &x) {
    return x * x;
}

template <typename T>
T t_abs(const T &x) {
    return (x < 0) ? (-x) : x;
}

#define abs(x) t_abs(x)

const int N = 123;
int n, k;
char ans[N][N];

bool solve(int test) {
    if (scanf("%d%d", &n, &k) != 2)
        return false;
        
    if (n == 3) {    
        puts(">vv");
        puts("^<.");
        puts("^.<");
        puts("1 3");
        return true;
    } else {

    int a = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            ans[i][j] = '.';
        ans[i][n] = 0;
    }
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < a; j++)
            ans[i][j + 1] = '>';
        for (int j = a + 2; j < n; j += 2)
            ans[i][j] = '>';
        ans[i][n - 1] = 'v';
    }
    for (int i = 1; i < n; i += 2) {
        for (int j = 0; j < a; j++)
            ans[i][n - 1 - j] = '<';
        for (int j = a + 1; j < n; j += 2)
            ans[i][n - 1 - j] = '<';
        ans[i][1] = 'v';
    }
    for (int i = 0; i < a; i++)
        ans[n - 1 - i][0] = '^';
    for (int i = a + 1; i < n; i += 2)
        ans[n - 1 - i][0] = '^';
    ans[0][0] = '>';

    if (n & 1) {
        for (int j = 1; j < n; j++) {
            ans[n - 1][j] = ans[n - 2][j];
            ans[n - 2][j] = '.';
        }
        
    }
    ans[n - 1][1] = '<';
    for (int i = 0; i < n; i++)
        if (ans[i][0] == '<')
            ans[i][0] = '.';
    }
    
    for (int i = 0; i < n; i++)
        puts(ans[i]);
    puts("1 1");

    return true;
}

int main() {
#ifdef KUVIMAN
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int test = 0;
    while (solve(test))
        test++;
#ifdef KUVIMAN
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif
    return 0;
}
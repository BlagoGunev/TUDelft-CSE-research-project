#define VERBOSE
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#ifndef _DEBUG
#   undef VERBOSE
#endif

using namespace std;

typedef unsigned           uint;
typedef long long          llong;
typedef unsigned long long ullong;
typedef long double        ldouble;

struct debug_t {
    template <typename T>
    debug_t& operator<<(const T& value) {
#       ifdef VERBOSE
            cout << value;
#       endif
        return *this;
    }
} debug;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, di, dj;
    while (cin >> n >> m >> dj >> di) {
        /*
        if (di == n)
            di = 0;
        if (dj == n)
            dj = 0;
        */
        vector<int> mapping(n);
        //mapping[0] = 0;
        int i = di, j = dj;
        while (i) {
            mapping[i] = j;
            i += di;
            i %= n;
            j += dj;
            j %= n;
        }
        vector<int> result(n);
        for (i = 0; i < m; i++) {
            int row, col;
            cin >> col >> row;
            result[(col - mapping[row] + n) % n]++;
        }
        for (int x: result)
            debug << x << ' ';
        debug << '\n';
        cout << max_element(begin(result), end(result)) - begin(result) << " 0\n";
        debug << '\n';
    }
}
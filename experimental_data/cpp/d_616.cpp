#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <cassert>
#include <bitset>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

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

const int maxN = (int)5e5 + 10;
const int maxK = (int)1e6 + 10;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const ll LLINF = (ll)1e18;

int a[maxN];
int c[maxK];

int rr = 0;

void add(int x, int delta) {
    if (c[x] == 0 && c[x] + delta == 1) rr++;
    if (c[x] == 1 && c[x] + delta == 0) rr--;
    c[x] += delta;
}

int main() {

    int n = nextInt<int>();
    int k = nextInt<int>();

    for (int i = 0; i < n; ++i) {
        a[i] = nextInt<int>();
    }
    int bestl = 0, bestr = 0;
    for (int r = 0, l = 0; r < n; ++r) {
       // cout << rr << '\n';
        add(a[r], +1);
        while(rr > k) {
            add(a[l], -1);
            l++;
        }
        if (r - l > bestr - bestl) {
            bestl = l;
            bestr = r;
        }
    }

    cout << bestl + 1 << ' ' << bestr  + 1 << '\n';

    return 0;
}
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int get_char() { int c; for (; (c = gc()) <= ' '; ) { if (!~c) exit(0); } return c; }

const int N = 100111;
const int MAXP = N;
int pr[MAXP], npr;
bool is_pr[MAXP + 1];
int sieve() {
    int i, j, d;
    if (npr) return npr;
    for (i = 3; i <= MAXP; i += 2) is_pr[i] = 1; is_pr[2] = 1;
    for (i = 3; i * i <= MAXP; i += 2) if (is_pr[i]) {
        for (j = i * i, d = i << 1; j <= MAXP; j += d) is_pr[j] = 0;
    }
    for (i = 2; i <= MAXP; i++) if (is_pr[i]) pr[npr++] = i;
    return npr;
}

template<class T> int get_prime_factor(T n, T ps[]) {
    T pn = 0;
    for (int i = 0; (T)pr[i] * pr[i] <= n; i++) if (n % pr[i] == 0) {
        for (ps[pn] = pr[i]; !(n % pr[i]); n /= pr[i]) ;
        pn++;
    }
    if (n and n != 1) ps[pn] = n, pn++;
    return pn;
}

int npf[N], pf[N][10], rep[N], on[N];

int main () {
    int i, j, tcc, tc = 1 << 28;
    sieve();
    for (i = 1; i < N; i++) {
        npf[i] = get_prime_factor(i, pf[i]);
    }
    for (tcc = 0; tcc < tc; tcc++) {
        int n = getint(), Q = getint(), q;
        for (q = 0; q < Q; q++) {
            char ch = get_char();
            int num = getint();
            if (ch == '+') {
                if (on[num] == 1) {
                    puts("Already on");
                } else {
                    bool ok = 1;
                    for (i = 0; i < npf[num]; i++) {
                        if (rep[pf[num][i]]) {
                            printf("Conflict with %d\n", rep[pf[num][i]]);
                            ok = 0;
                            break;
                        }
                    }
                    if (ok) {
                        puts("Success");
                        on[num] = 1;
                        for (i = 0; i < npf[num]; i++) {
                            rep[pf[num][i]] = num;
                        }
                    }
                }
            }
            if (ch == '-') {
                if (on[num] == 0) {
                    puts("Already off");
                } else {
                    puts("Success");
                    on[num] = 0;
                    for (i = 0; i < npf[num]; i++) {
                        rep[pf[num][i]] = 0;
                    }
                }
            }
        }
    }
    return 0;
}
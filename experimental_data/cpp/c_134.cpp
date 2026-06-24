#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <complex>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

template <typename T> inline void checkmax(T &a, const T& b) { if (a < b) a = b; }
template <typename T> inline void checkmin(T &a, const T& b) { if (a > b) a = b; }

/** ----------headers above --------------*/

const int maxn = 200000 + 5;

struct Person {
    int i, c;
    friend bool operator < (const Person& x, const Person& y){
        return x.c < y.c;
    }
} p[maxn], t[maxn];

int ra[maxn], rb[maxn], rc = 0;

int main(){
    int n, s;
    while ( scanf("%d%d", &n, &s) == 2 ){
        int maxc = 0;
        for ( int i = 0; i < n; i++ ){
            scanf("%d", &p[i].c);
            p[i].i = i + 1;
            checkmax(maxc, p[i].c);
        }
        rc = 0;
        make_heap(p, p + n);
        int ok = 1;
        for (;;){
            Person a = p[0]; pop_heap(p, p + n--);
            if (a.c == 0) break;
            for (int i = 0; i < a.c; i++){
                if (n == 0) {
                    ok = 0; break;
                }
                t[i] = p[0]; pop_heap(p, p + n--);
                ra[ rc ] = a.i; rb[ rc ] = t[i].i; rc++;
                if (t[i].c == 0) {
                    ok = 0; break;
                }
                --t[i].c;
            }
            if (!ok) break;
            for (int i = 0; i < a.c; i++){
                p[n++] = t[i]; push_heap(p, p + n);
            }
        }
        if (ok){
            puts("Yes");
            printf("%d\n", rc);
            for (int i = 0; i < rc; i++){
                printf("%d %d\n", ra[i], rb[i]);
            }
        } else {
            puts("No");
        }
    }
}
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,popcnt,tune=native")
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <immintrin.h>
#include <algorithm>
#include <random>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define elif else if
#define rt return
const int BINF = 9e18, LINF = 2e9, mod = 1e9 + 7, P = 179, Q = 1791791791;
const int MAXN = 120000 + 7;
int a[MAXN];
int mx[MAXN];
int mn[MAXN];
vector<pair<int, int>> bck[MAXN];
long long ans[MAXN];
int xui[MAXN];
int buff[4];
void solve() {
    int n;
    cin >> n;
    fill(mx, mx + n, 0);
    fill(mn, mn + n, MAXN);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --r;
        --l;
        bck[r].push_back({l, i});
    }
    for (int r = 0; r < n; ++r) {
        buff[0] = r;
        buff[1] = r - 1;
        buff[2] = r - 2;
        buff[3] = r - 3;
        __m128i vl = _mm_load_si128((__m128i*)buff);
        __m128i f = _mm_set1_epi32(a[r]);
        __m128i one = _mm_set1_epi32(1);
        __m128i four = _mm_set1_epi32(4);

        int* xptr = xui;
        int* mxptr = mx;
        int* mnptr = mn;
        for (int i = 0; i < (r >> 2); ++i) {
            __m128i mxx = _mm_load_si128((__m128i*)mxptr);
            __m128i mnn = _mm_load_si128((__m128i*)mnptr);
            __m128i xx = _mm_load_si128((__m128i*)xptr);
            mxx = _mm_max_epi32(mxx, f);
            mnn = _mm_min_epi32(mnn, f);
            __m128i d = _mm_sub_epi32(mxx, mnn);
            d = _mm_cmpeq_epi32(d, vl);
            d = _mm_and_si128(d, one);
            xx = _mm_add_epi32(d, xx);
            _mm_store_si128((__m128i*)xptr, xx);
            _mm_store_si128((__m128i*)mnptr, mnn);
            _mm_store_si128((__m128i*)mxptr, mxx);
            xptr += 4;
            mnptr += 4;
            mxptr += 4;
            vl = _mm_sub_epi32(vl, four);
        }
        for (int i = (r >> 2) << 2; i <= r; ++i) {
            mx[i] = max(mx[i], a[r]);
            mn[i] = min(mn[i], a[r]);
            if (mx[i] - mn[i] == r - i)
                ++xui[i];
        }
        for (pair<int, int> pr : bck[r]) {
            __m128i sum = _mm_set1_epi32(0);
            int lans = 0;
            int p = pr.x;
            while (p % 4) {
                lans += xui[p];
                ++p;
            }
            int* xptr = xui + p;
            while (p + 3 <= r) {
                __m128i val = _mm_load_si128((__m128i*)xptr);
                sum = _mm_add_epi32(sum, val);
                p += 4;
                xptr += 4;
            }
            while (p <= r) {
                lans += xui[p];
                ++p;
            }
            _mm_store_si128((__m128i*)buff, sum);
            if (min(min(buff[0], buff[1]), min(buff[2], buff[3])) < 0) 
                exit(1);
            ans[pr.y] = (long long)lans + (long long)buff[0] + buff[1] + buff[2] + buff[3];
        }
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
    rt;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cout.precision(40);

    solve();

    rt 0;
}
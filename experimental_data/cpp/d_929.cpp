#include <bits/stdc++.h>

#define SQ(a) (a)*(a)

#define F0R(i, a) for(int i = 0; i < (a); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define R0F(i, a) for(int i = (a) - 1; i >= 0; i--)
#define ROF(i, a, b) for(int i = (b) - 1; i >= (a); i--)

#define ran() (rand() & 0x7FFF)
#define rand31() ((ran() << 16) | (ran() << 1) | (ran() & 1))
#define rand32() ((ran() << 17) | (ran() << 2) | (ran() & 3))
#define rand63() (((ll)ran() << 48) | ((ll)ran() << 33) | ((ll)ran() << 18) | ((ll)ran() << 3) | ((ll)ran() & 7))
#define rand64() (((ll)ran() << 49) | ((ll)ran() << 34) | ((ll)ran() << 19) | ((ll)ran() << 4) | ((ll)ran() & 15))

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define UB upper_bound
#define LB lower_bound
#define X real()
#define Y imag()
#define MAXN 100000

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ld> point;

int n, a, b;
int g[MAXN - 1], k[MAXN], need[MAXN];
bool have[MAXN + 1];

bool possible() {
    int lo = a, hi = a;
    have[k[a]] = 1;
    while(1) {
        if(lo > 0 && have[g[lo - 1]])
            have[k[--lo]] = 1;
        else if(hi < n - 1 && have[g[hi]])
            have[k[++hi]] = 1;
        else
            break;
    }
    return b >= lo && b <= hi;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    a--, b--;
    F0R(i, n - 1) cin >> g[i];
    F0R(i, n) cin >> k[i];
    if(!possible())
        cout << -1 << endl;
    else {
        need[a] = a;
        memset(have, 0, (MAXN + 1) * sizeof(bool));
        have[k[a]] = 1;
        int curr = a;
        FOR(i, a + 1, n) {
            while(curr > 0 && !have[g[i - 1]])
                have[k[--curr]] = 1;
            if(!have[g[i - 1]])
                break;
            need[i] = curr;
            have[k[i]] = 1;
        }
        memset(have, 0, (MAXN + 1) * sizeof(bool));
        have[k[a]] = 1;
        curr = a;
        R0F(i, a) {
            while(curr < n - 1 && !have[g[i]])
                have[k[++curr]] = 1;
            if(!have[g[i]])
                break;
            need[i] = curr;
            have[k[i]] = 1;
        }
        ll res = 0;
        while(b != a) {
            res += abs(b - need[b]);
            b = need[b];
        }
        cout << res << endl;
    }
    return 0;
}
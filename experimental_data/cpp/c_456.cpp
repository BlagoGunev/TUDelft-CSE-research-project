#include <bits/stdc++.h>

#define up(i, lower, upper) for(int i = lower; i < upper; i++)
#define down(i, lower, upper) for(int i = upper-1; i >= lower; i--)
#define MAX_N 100010

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<int>::iterator viter;
typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const double eps = 1e-10;

template<class T>

inline bool read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}

template <class T>
inline void write(T n) {
    if(n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n) {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
///-----------------------
ll a[100010];
ll dp[100010];

int main() {
    int n;
    read(n);
    int tmp;
    up(i, 0, n) read(tmp), a[tmp]++;
    ll ans = max(a[1], 2*a[2]), maxx = a[1];
    dp[1] = a[1], dp[2] = a[2]*2;
    up(i, 3, 100000+1) {
        dp[i] = maxx + i*a[i];
        ans = max(ans, dp[i]);
        maxx = max(dp[i-1], maxx);
    }
    printf("%I64d\n", ans);
}
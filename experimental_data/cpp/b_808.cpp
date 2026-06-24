#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()

template <typename T1, typename T2>
bool umin(T1 &x, const T2 &y) {return (x>y ? (x=y,true):false);}
template <typename T1, typename T2>
bool umax(T1 &x, const T2 &y) {return (x<y ? (x=y,true):false);}

template <typename T>
void read(T& x) {
    char ch;
    T p = 1; x = 0;
    do {ch = getchar();} while(ch <= ' ');
    if (ch == '-') p = -1, ch = getchar();
    while (ch>='0' && ch<='9') x = x*10 + ch-'0', ch = getchar();
    x *= p;
}

void read(string& x) {
    char ch;
    do {ch = getchar();} while (ch <= ' ');
    while (ch > ' ') x += ch, ch = getchar();
}

void read(char& x) {do {x = getchar();} while (x <= ' ');}
template<typename T, typename... R>
void read(T& x, R&... y) { read(x); read(y...); }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = (int)1e6+3;
const ll mod = (ll)1e9+7;
const int INF = (int)1e9+1;
const ll LLINF = (ll)1e18+1;
const ld pi = (ld)acos(-1.0);


int n, m;
int a[N];
ll pref[N];


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    read(n, m);
    rep(i, 0, n) {
        int x;
        read(x);
        pref[i] = x + (i > 0 ? pref[i-1] : 0);
    }
    ld res = 0;
    rep(i, 0, n-m+1) {
        ll sum = 0;
        sum = pref[i+m-1] - (i>0 ? pref[i-1] : 0);
        //cout << sum << ' ' << (pref[i+m-1]-(i>0 ? pref[i-1] : 0)) / 2.0<< endl;
        res += (ld)sum/(ld)(n-m+1);
    }
    cout.precision(16);
    cout << fixed << res << endl;

    return 0;
}
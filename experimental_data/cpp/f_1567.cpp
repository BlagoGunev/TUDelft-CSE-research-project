// #pragma comment(linker, "/STACK:1024000000,1024000000")

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define rp(i, n) for(int i=0; i<n; i++)
#define rep(i, l, r) for(int i=l; i<=r; i++)
#define dw(i, n) for(int i=n-1; i>=0; i--)
#define dow(i, l, r) for(int i=l; i>=r; i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define clr(x, c) memset(x,c,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define lowbit(x) ((x)&(-(x)))

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,int> Pli;
typedef pair<double,int> Pdi;
typedef pair<ull,int> Pui;
typedef pair<pair<int,int>,pair<int,int> > PPP;

// ====================================================== 全局数据

// #define Q 1000000007
// #define maxn 100009
// #define maxm 100009

// ====================================================== 预设函数

// inline int min(const int a, const int b) { return (a <= b) ? a : b; }
// inline int min3(const int a, const int b, const int c) { return (a <= b && a <= c) ? a : ((b <= c) ? b : c); }
// inline int max(const int a, const int b) { return (a >= b) ? a : b; }
// inline int max3(const int a, const int b, const int c) { return (a >= b && a >= c) ? a : ((b >= c) ? b : c); }
// inline int gcd(const int a, const int b) { return b==0?a:gcd(b,a%b); }
// inline int lcm(const int a, const int b) { return 1LL*a*b/gcd(a,b); }

// inline int pow(int x, int t, int mod) {
//     int g = 1;
//     while (t) {
//         if (t&1) g = 1LL*g*x%mod;
//         x = 1LL*x*x%mod, t >>= 1;
//     }
//     return g;
// }

// inline int bits(int x)  {
//     x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
//     x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
//     x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
//     x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
//     x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
//     return x;
// }

inline int read() {
    int x=0, f=0; char ch=getchar();
    while (ch<'0' || '9'<ch) f|=ch=='-', ch=getchar();
    while ('0'<=ch && ch<='9') x=x*10+ch-'0', ch=getchar();
    return f?-x:x;
}

// ====================================================== 模板代码

// =========================== 线性模数

// inline void init_inverse(int *inv, int num, int mod) {
//     inv[1] = 1;
//     rep(i, 2, num) {
//         inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
//     }
// }

// =========================== 图论

#define maxn 250009
#define maxm 1000009

#define travel(x) for(edge *p=fir[x]; p; p=p->n)
struct edge {int y; edge *n;} e[maxm], *fir[maxn], *pt=e;
inline void init_edge() { clr(fir,0); pt=e; }
inline void add_edge(const int x, const int y) {
    pt->y=y, pt->n=fir[x], fir[x]=pt++;
}

// =========================== 并查集

// int H[maxn];
// int head(const int a) {return H[a]=((H[a]==a)?a:head(H[a]));}
// inline void join(const int a, const int b) {H[head(a)] = head(b);}

// =========================== 平面几何

// #define eps 1e-6
// struct Point {
//     double x, y;
//     Point(const double x = 0, const double y = 0): x(x), y(y) {}
//     Point operator +(const Point &b) { return Point(x+b.x, y+b.y); }
//     Point operator -(const Point &b) { return Point(x-b.x, y-b.y); }
//     void operator +=(const Point &b) { x += b.x, y += b.y; }
//     void operator -=(const Point &b) { x -= b.x, y -= b.y; }
//     Point operator -(void) { x = -x; y = -y; return *this; }
//     bool operator ==(const Point &b) { return abs(x-b.x) < eps && abs(y-b.y) < eps; }
// };
// struct Line {
//     double a, b, c; // ax+by+c=0
//     Line(const double a = 0, const double b = 0, const double c = 0): a(a), b(b), c(c) {}
//     Line(const Point &p0, const Point &p1): a(p1.y-p0.y), b(p0.x-p1.x), c(-2*a*b) {}
//     inline Point direct_vec() { return Point(b, -a); }
//     inline Point normal_vec() { return Point(a, b); }
//     inline Point direct_unit_vec() { return Point(b/sqrt(a*a+b*b), -a/sqrt(a*a+b*b));}
//     inline Point normal_unit_vec() { return Point(a/sqrt(a*a+b*b), b/sqrt(a*a+b*b)); }
// };

// // 单点求极角 (Wait for check)
// inline double polar_angle(const Point &a) { return atan2(a.y, a.x); }

// // 两点求极角 (Wait for check)
// inline double polar_angle(const Point &a, const Point &b) { return atan2(b.y-a.y, b.x-a.x); }

// // 极坐标排序 (Wait for check)
// inline void sort_by_polar_coordinates(Point *p, const int n) {
//     int k = 1;
//     rep(i, 2, n) if (p[i].y<p[k].y || (p[i].y==p[k].y && p[i].x<p[k].x)) k = i;
//     swap(p[1], p[k]);
//     rep(i, 2, n) p[i] -= p[1];
//     sort(p+2, p+n+1, [](const Point &a, const Point &b)->bool{ return polar_angle(a) < polar_angle(b); });
//     rep(i, 2, n) p[i] += p[1];
// }

// ====================================================== 主程序

int n, m;
char s[509][509];
int id[509][509], st[9], c[maxn];
queue<int>q;

int main() {
    n = read(), m = read();
    rp(i, n) scanf("%s", s[i]);
    int num = 0; rp(i, n) rp(j, m) id[i][j] = num++;
    rp(i, n) rp(j, m) if (s[i][j] == 'X') {
        int o = 0;
        if (i-1 >= 0 && s[i-1][j] == '.') st[o++] = id[i-1][j];
        if (j-1 >= 0 && s[i][j-1] == '.') st[o++] = id[i][j-1];
        if (i+1 < n && s[i+1][j] == '.') st[o++] = id[i+1][j];
        if (j+1 < m && s[i][j+1] == '.') st[o++] = id[i][j+1];
        if (o & 1) {
            puts("NO");
            return 0;
        }
        if (o == 2) {
            add_edge(st[0], st[1]);
            add_edge(st[1], st[0]);
        }
        if (o == 4) {
            add_edge(st[0], st[1]);
            add_edge(st[1], st[2]);
            add_edge(st[2], st[3]);
            add_edge(st[3], st[0]);
        }
    }
    rp(i, n) rp(j, m) if (s[i][j] == '.' && c[id[i][j]] == 0) {
        c[id[i][j]] = 1; q.push(id[i][j]);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            travel(x) if (c[p->y] == 0) {
                c[p->y] = c[x] ^ 5; q.push(p->y);
            } else if (c[p->y] == c[x]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    rp(i, n) rp(j, m) if (s[i][j] == '.') {
        printf("%d%c", c[id[i][j]], j==m-1?'\n':' ');
    } else {
        int o = 0;
        if (i-1 >= 0 && s[i-1][j] == '.') o += c[id[i-1][j]];
        if (j-1 >= 0 && s[i][j-1] == '.') o += c[id[i][j-1]];
        if (i+1 < n && s[i+1][j] == '.') o += c[id[i+1][j]];
        if (j+1 < m && s[i][j+1] == '.') o += c[id[i][j+1]];
        printf("%d%c", o, j==m-1?'\n':' ');
    }

    return 0;
}
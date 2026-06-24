#include <cstdio>

#include <algorithm>

#include <iostream>

#include <cmath>



#define DB double

#define LL long long

#define MUL(x) ((LL) (x) * ((x) - 1) / 2)



#define REP(i, x, y) for (int i = x, _ = y; i <= _; ++ i)

#define rep(i, x, y) for (int i = x, _ = y; i >= _; -- i)



template <typename T> bool Chkmax(T &x, T y) { return x < y? x = y, true : false; }

template <typename T> bool Chkmin(T &x, T y) { return y < x? x = y, true : false; }



const int MAXN = 2e3 + 1e3;

const DB eps = 1e-12, PI = 3.1415926535897932;



int Dcmp(DB x)

{

    if (fabs(x) < eps)

        return 0;

    return x < 0? -1 : 1;

}



struct Line

{

    DB a, b, c;

    Line() {}

    Line(DB a, DB b, DB c):

        a(a), b(b), c(c) {}

    inline DB F(DB x) { return (a * x + c) / (-b); }

} a[MAXN];



struct Point

{

    DB x, y;

    Point() {}

    Point(DB x, DB y):

        x(x), y(y) {}

    Point operator - (const Point &p) const

    {

        return Point(x - p.x, y - p.y);

    }

} P[MAXN];



typedef Point Vector;



LL ans;

int n, m;



Point GetInter(Line l1, Line l2)

{

    if (Dcmp(l1.b) == 0)

        std::swap(l1, l2);

    DB x = (l2.b * l1.c / l1.b - l2.c) / (l2.a - l2.b * l1.a / l1.b);

    return Point(x, l1.F(x));

}



void Solve()

{

    static DB V[MAXN];

    

    int tot = 0;

    REP (i, 1, n)

        if (Dcmp(a[i].c) != 0)

            a[++ tot] = a[i];

    ans += (LL) tot * MUL(n - tot);

    n = tot;



    REP (i, 1, n)

        P[i] = GetInter(a[i], Line(a[i].b, -a[i].a, 0));

    

    REP (i, 1, n) {

        tot = 0;

        REP (j, i + 1, n) {

            Point s = P[i] - P[j];

            V[++ tot] = atan2(s.y, s.x);

            while (Dcmp(V[tot]) <= 0)

                V[tot] += PI;

        }



        std::sort(V + 1, V + tot + 1);



        int last = 0;

        REP (j, 1, tot)

            if (Dcmp(V[last + 1] - V[j]) != 0) {

                ans += MUL(j - last - 1);

                last = j - 1;

            }

        ans += MUL(tot - last);

    }



    printf("%lld\n", ans);

}



void Input()

{

    scanf("%d", &n);

    REP (i, 1, n) {

        scanf("%lf%lf%lf", &a[i].a, &a[i].b, &a[i].c);

        a[i].c *= -1;

    }

}



int main()

{

    if (fopen("D.in", "r") != NULL) {

        freopen("D.in", "r", stdin);

        freopen("D.out", "w", stdout);

    }



    Input();

    Solve();



    return 0;

}
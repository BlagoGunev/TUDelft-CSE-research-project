#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<ll> vl;

#define        mem(arr, val)                        memset(arr,val,sizeof arr)
#define            sz(vec)            (int)vec.size()
#define        sc(n)                scanf("%d",&n)
#define        scl(n)                scanf("%I64d",&n)
#define        sc2l(n, m)            scanf("%I64d %I64d",&n, &m)
#define        sc2(n, m)            scanf("%d %d",&n,&m)
#define        sc3(n, m, x)            scanf("%d %d %d",&n,&m,&x)
#define            sc4(n, m, x, y)        scanf("%d %d %d %d",&n,&m,&x,&y)
#define        println(n)            printf("%d\n",n)
#define        printlnl(n)        printf("%I64d\n",n)
#define        line()                printf("\n")
#define        print(n)            printf("%d",n)
#define        case(n)            printf("Case #%d: ",n)
#define        prints(n)            printf("%s",n)
#define        print2(n, m)        printf("%d %d",n,m)
#define        print1(n)            printf(" %d",n)
#define        fori(S, N)        for(int i = S; i<(N); i++)
#define            forj(S, N)        for(int j = S; j<(N); j++)
#define            fork(S, N)            for(int k = S; k<(N); k++)

double root2 = sqrt(2.0);
pair<double, double> rotate(int xc, int yc, int x, int y) {
    int x1 = x - xc, y1 = y - yc;
    double x2 = (x1 - y1) / root2, y2 = (x1 + y1) / root2;
    return make_pair(x2 + xc, y2 + yc);
}
double EPS = 0.0000000001;
int dcmp(double a, double b) {
    return fabs(a - b) <= EPS ? 0 : a > b ? 1 : -1;
}

int main() {
    int n = 4;
    vector<pr> sq1(n), sq2(n);
    fori(0, n) {
        sc2(sq1[i].first, sq1[i].second);
    }
    sort(sq1.begin(), sq1.end());
    fori(0, n) {
        sc2(sq2[i].first, sq2[i].second);
    }
    sort(sq2.begin(), sq2.end());
    pair<double, double> rotated = rotate(sq2[0].first, sq2[0].second, sq2[3].first, sq2[3].second);
    fori(-100, 101) {
        forj(-100, 101) {
            int checker = 0;
            if((i >= sq1[0].first && i <= sq1[3].first) && (j >= sq1[0].second && j <= sq1[3].second)) {
                checker++;
            }
            pair<double, double> r = rotate(sq2[0].first, sq2[0].second, i, j);
            if(dcmp(r.first, sq2[0].first) >= 0 && dcmp(r.first, rotated.first) <= 0 && dcmp(r.second, sq2[0].second) >= 0 && dcmp(r.second, rotated.second) <= 0) {
                checker++;
            }
            if(checker == 2) {
                prints("YES\n");
                return 0;
            }
        }
    }
    prints("NO\n");
    return 0;
}

//    std::ifstream in("in");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out");
//    std::cout.rdbuf(out.rdbuf());
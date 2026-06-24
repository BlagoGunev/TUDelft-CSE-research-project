#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const double pi = acos(-1.0);

template<typename T,typename HT>
class POINT2D_META
{
public:
    T x;
    T y;
    int id;
    POINT2D_META() { x = y = 0; id = -1; }
    POINT2D_META(T _x,T _y):x(_x),y(_y) { id = -1; }
    inline POINT2D_META operator+(const POINT2D_META& b) const { return POINT2D_META(x+b.x,y+b.y); }
    inline POINT2D_META operator-(const POINT2D_META& b) const { return POINT2D_META(x-b.x,y-b.y); }
    inline POINT2D_META operator*(const double k) const { return POINT2D_META(k*x,k*y); }
    inline HT operator*(const POINT2D_META& b) const { return (HT)x*b.y-(HT)b.x*y; }
    inline HT dot(const POINT2D_META& b) const { return (HT)x*b.x+(HT)y*b.y; }
    inline HT hypot2() const { return (HT)x*x+(HT)y*y; }
    inline T hypot() const { return ::hypot(x,y); }
    POINT2D_META rot(double ang) const { return POINT2D_META(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)); }
    inline int read() { return scanf("%lf %lf",&x,&y); }
    //inline int read() { return scanf("%d %d",&x,&y); }
    // h-v order
    inline bool operator<(const POINT2D_META& b) const { return x == b.x ? y < b.y : x < b.x; }
};
//typedef POINT2D_META<int,ll> POINT;
typedef POINT2D_META<double,double> POINT;

const double eps = 1e-8;

template<typename T>
inline T valsign(T x) { return x < 0 ? -1 : (x > 0 ? 1 : 0); }
inline double valsign(double x) { return x < -eps ? -1 : (x > eps ? 1 : 0); }

POINT pnt[22];
int angle[22];

double F[1111111]; // rightmost x

int main(void)
{
    int n = 0;
    int l = 0;
    int r = 0;
    scanf("%d %d %d",&n,&l,&r);
    for(int i = 0;i < n;i++)
    {
        pnt[i].read();
        scanf("%d",&angle[i]);
    }

    fill(F,F+(1<<n),-1e100);
    F[0] = l;
    bool best = false;
    for(int i = 0;i < (1<<n);i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(i & (1<<j)) continue;

            double gonna = F[i];
            if(fabs(pnt[j].y) < eps)
            {
                if(F[i]-pnt[j].x > eps) { best = true; gonna = r; }
                else gonna = pnt[j].x;
            }
            else if(pnt[j].y > 0)
            {
                POINT A = POINT(F[i],0);
                // pnt[j] - A , counter clockwise rotate angle[j] to B, intersect x axis
                POINT B = (A-pnt[j]).rot(angle[j]/180.*pi) + pnt[j];
                POINT adj = (B-pnt[j]);
                if(adj.y > eps) gonna = r;
                else if(fabs(pnt[j].x - B.x) < eps)
                {
                    gonna = pnt[j].x;
                }
                else if(fabs(pnt[j].y - B.y) < eps)
                {
                    best = true;
                    gonna = r;
                }
                else
                {
                    adj = adj * ((-pnt[j].y) / adj.y);
                    gonna = (pnt[j]+adj).x;
                }
            }
            else
            {
                POINT A = POINT(F[i],0);
                // pnt[j] - A , clockwise rotate angle[j] to B, intersect x axis
                POINT B = (A-pnt[j]).rot(-angle[j]/180.*pi) + pnt[j];
                POINT adj = (B-pnt[j]);
                if(adj.y < -eps) { best = true; gonna = r; }
                else if(fabs(pnt[j].x - B.x) < eps)
                {
                    gonna = pnt[j].x;
                }
                else if(fabs(pnt[j].y - B.y) < eps)
                {
                    best = true;
                    gonna = r;
                }
                else
                {
                    adj = adj * ((-pnt[j].y) / adj.y);
                    gonna = (pnt[j]+adj).x;
                }
            }
            F[i | (1<<j)] = max(F[i | (1<<j)],gonna);
        }
    }
    
    if(best) F[(1<<n)-1] = r;
    printf("%.12f\n",max(0.0,min<double>(F[(1<<n)-1]-l,r-l)));
    while(getchar() != EOF);
    return 0;
}
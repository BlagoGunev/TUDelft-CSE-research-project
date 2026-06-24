#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long
#define db double
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second

const db pi=M_PI;
const db ERR=1e-13;

int o;
int top[2];
db w,h,a;

struct Point {
    db x,y;
    Point() {}
    Point(db x,db y): x(x),y(y) {}
    Point operator -(Point a) {return Point(x-a.x,y-a.y);}
};
typedef Point Vector;

Point f[3][100];
Point p[100];

inline int Dcmp(db x) {
    if(fabs(x)<ERR) return 0;
    return x>ERR ? 1:-1;
}
inline Vector Rotate(Vector A,db rad) {
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
inline db Cross(Vector A,Vector B) {
    return A.x*B.y-B.x*A.y;
}
inline Point X(db x,db y,db xx,db yy,db kk,db bb) {
    if(x==xx) return Point(x,x*kk+bb);
    db k,b;
    Point ans;
    k=(y-yy)/(x-xx);
    b=y-x*k;
    ans.x=(b-bb)/(kk-k);
    ans.y=ans.x*k+b;
    return ans;
}
inline void Work(db k,db b) {
    o=1-o;
    top[o]=0;
    for(int i=1;i<=top[1-o];i++) {
        if(Dcmp((f[1-o][i].x*k+b-f[1-o][i].y)*(b))>=0) {
            ++top[o];
            f[o][top[o]]=f[1-o][i];
        }
        int j=i%top[1-o]+1;
        if(Dcmp((f[1-o][i].x*k+b-f[1-o][i].y)*(f[1-o][j].x*k+b-f[1-o][j].y))<0) 
            f[o][++top[o]]=X(f[1-o][i].x,f[1-o][i].y,f[1-o][j].x,f[1-o][j].y,k,b);
    }
}
inline db Area(Point *X,int s) {
    db sum=0;
    for(int i=2;i<s;i++) sum+=Cross(X[i]-X[1],X[i+1]-X[1]);
    return sum/2;
}
int main() {
    scanf("%lf %lf %lf",&w,&h,&a);
    a=a/180*pi;
    top[o]=4;
    f[o][1]=Point(-w/2,-h/2);
    f[o][2]=Point(w/2,-h/2);
    f[o][3]=Point(w/2,h/2);
    f[o][4]=Point(-w/2,h/2);
    for(int i=1;i<=4;i++) {
        Point tmp=f[o][i];
        p[i]=Rotate(tmp,a);
    }
    for(int i=1;i<=4;i++) {
        int j=i%4+1;
        if(Dcmp(p[i].x-p[j].x)==0) {
            o=1-o;
            top[o]=0;
            for(int j=1;j<=top[o^1];j++) {
                if(Dcmp((f[o^1][j].x-p[i].x)*(0-p[i].x))>=0)
                    f[o][++top[o]]=f[o^1][j];
                int k=j%top[o^1]+1;
                if(Dcmp((f[o^1][j].x-p[i].x)*(f[o^1][k].x-p[i].x))<0) {
                    if(Dcmp(f[o^1][j].x-f[o^1][k].x)==0) continue;
                    db kk=(p[k].y-p[j].y)/(p[k].x-p[j].x);
                    db bb=f[o^1][j].y-f[o^1][j].x*kk;
                    f[o][++top[o]]=Point(p[i].x,kk*p[i].x+bb);
                }
            }
            continue;
        }
        db k=(p[j].y-p[i].y)/(p[j].x-p[i].x);
        db b=p[i].y-p[i].x*k;
        Work(k,b);
    }
    printf("%.9lf\n",Area(f[o],top[o]));
    return 0;
}
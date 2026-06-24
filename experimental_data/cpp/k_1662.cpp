#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-10
const double pi=acos(-1.0);
struct lin
{
    double x,y;lin(){}
    lin(double X,double Y):x(X),y(Y){}
    double len()const
    {
        return sqrt(x*x+y*y);
    }
};
typedef lin hui;
hui operator-(const lin&a,const lin&b)
{
    return hui(a.x-b.x,a.y-b.y);
}
double dot(const hui&a,const hui&b)
{
    return a.x*b.x+a.y*b.y;
}
double jij(const hui&a,const hui&b)
{
    double t=dot(a,b)/a.len()/b.len();
    if(t>1-eps)t=1;
    if(t<-1+eps)t=-1;
    return acos(t);
}
double cal(const lin&a,const lin&b,const lin&c)
{
    double tt=pi*2/3;hui x=b-a,y=c-b,z=a-c;
    if(jij(b-a,c-a)>tt)return x.len()+z.len();
    if(jij(a-b,c-b)>tt)return x.len()+y.len();
    if(jij(a-c,b-c)>tt)return y.len()+z.len();
    double s=jij(b-a,c-a)+pi/3,X=x.len(),Y=z.len();
    return sqrt(X*X+Y*Y-2*cos(s)*X*Y);
}
lin A,B,C;
double cal(const lin&x)
{
    return max(max(cal(A,B,x),cal(B,C,x)),cal(A,C,x));
}
double check(double X)
{
    double l=-1e5,r=1e5;
    for(int s=0;s<200;s++)
    {
        double t=(r-l)/3,a=l+t,b=a+t;
        if(cal(lin(X,a))>cal(lin(X,b)))l=a;
        else r=b;
    }
    return cal(lin(X,(l+r)/2));
}
int main()
{
    scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
    double l=-1e5,r=1e5;
    for(int s=0;s<200;s++)
    {
        double t=(r-l)/3,a=l+t,b=a+t;
        if(check(a)>check(b))l=a;
        else r=b;
    }
    double ans=check((l+r)/2);
    printf("%.10lf",ans);
    return 0;
}
//rmj?
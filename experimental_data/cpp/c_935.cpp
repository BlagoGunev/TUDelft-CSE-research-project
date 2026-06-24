#include<stdio.h>
#include<math.h>
int main()
{
    double r,x1,y1,x2,y2;
    while(~scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2))
    {
        double a=x1-x2;
        double b=y1-y2;
        double s=a*a+b*b;
        if(s>r*r)
        {
            printf("%lf %lf %lf\n",x1,y1,r);
        }
        else if(s==0)
        {
            printf("%lf %lf %lf\n",x1,y1+r/2,r/2);
        }
        else
        {

            double ss=sqrt(s);
            double rr=r+ss;
            rr/=2;
            printf("%lf %lf %lf\n",(x1-x2)*rr/ss+x2,(y1-y2)*rr/ss+y2,rr);
        }
    }
    return 0;
}
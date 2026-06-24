#include <stdio.h>
using namespace std;
const double eps=0.00001;

double p(double a, int n)   {
    if(n==0)    return 1;
    double ans=p(a,n>>1);
    ans*=ans;
    if(n&1) ans*=a;
    return ans;
}



int main()  {

    double n,m;
    scanf("%lf %lf",&m,&n);
    double ans=m;
    for(double i=m-1;i>0.1;i=i-1.0)  {
        double newans=p(i/m,n);
        if(newans<eps)  break;
        ans-=newans;
    }
    printf("%lf\n",ans);
    return 0;
}
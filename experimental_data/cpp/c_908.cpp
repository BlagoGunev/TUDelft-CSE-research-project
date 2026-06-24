#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
double a[1005];
double ans[1005];

int main(){
    int n;
    double r;
    scanf("%d%lf",&n,&r);
    for (int i = 0;i < n; ++i) scanf("%lf",&a[i]);
    int flag;
    ans[0] = r;
    double mx ;
    for (int i = 1;i < n ;++i){
        flag = 1;mx = r;
        for (int j = i-1; j >= 0; --j){
            double dis = fabs(a[i]-a[j]);
            if (dis <= r+r){
                flag = 0;
                if (ans[j] + sqrt(4.0*r*r-dis*dis) > mx) mx = ans[j] + sqrt(4.0*r*r-dis*dis);
            }
        }
        ans[i] = mx;
        if (flag) ans[i] = r;
    }
    printf("%.15lf",r);
    for (int i = 1;i < n; ++i){
        printf(" %.15lf",ans[i]);
    }
    puts(" ");
    return 0;
}
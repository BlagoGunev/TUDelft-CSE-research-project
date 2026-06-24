#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ans,a,b,m;
    int n;
    scanf("%d%lf",&n,&m);
    ans = 10000000.0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&a,&b);
        ans = min(ans,m*a/b);
    }
    printf("%.8f",ans);
    return 0;
}
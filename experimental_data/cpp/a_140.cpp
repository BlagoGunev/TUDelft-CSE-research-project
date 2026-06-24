#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265359;

int n,ans;
double r,R;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONLINE_JUDGE;

    scanf("%d%lf%lf", &n, &R, &r);

    if(r>R) printf("NO\n");
    else
    {
        if(2*r>R) ans = 1;
        else ans = (int)(360/(2*asin(r/(R-r))*(180/PI)));

        if(ans<n) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
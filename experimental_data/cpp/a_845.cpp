#include <bits/stdc++.h>

using namespace std;
int a[205];
int main()
{
    int n,br1=0,i,j,br2=0,br;
    scanf("%d",&n);
    for(i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+2*n+1);
   // printf("%d %d %d\n",br,br1,br2);
    if (a[n]==a[n+1])
        printf("NO");
    else printf("YES");
    return 0;
}
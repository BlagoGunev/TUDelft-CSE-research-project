#include <stdio.h>
main()
{
long long  n,k;
scanf("%lld",&n);
scanf("%lld",&k);
 long d=n/k;
if (d%2!=0)
printf("YES");
else printf("NO");
}
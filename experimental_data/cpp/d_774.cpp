#include <math.h>
#include <stdio.h>
int main()
{
  int i,n,l,r,c;
  int a[100005]={0}, b[100005]={0};
  scanf("%d %d %d", &n, &l, &r);
  for (i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
  for (i=1; i<=n; i++)
        {
            scanf("%d", &b[i]);
        }
  c=0;
  for (i=1; i<l; i++)
        {
            if (a[i]!=b[i]) c=1;
        }
  for (i=r+1; i<=n; i++)
        {
            if (a[i]!=b[i]) c=1;
        }
  if (c==1) printf("LIE");
  if (c==0) printf("TRUTH");
}
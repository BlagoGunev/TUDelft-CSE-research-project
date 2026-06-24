#include <cstdio>

unsigned int c[210][210],d[210],f[210][210];
unsigned int i,j,k,m,n,p,s;

int main()
{
 scanf("%u%u%u",&n,&m,&p);
 for (i=0;i<=n;i++)
  for (j=0;j<=i;j++)
   if ((j==0) || (j==i))
    c[i][j]=1;
   else
    c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
 f[1][0]=1,d[1]=1;
 for (i=2;i<=n;i++)
 {
  for (j=1;j<i;j++)
   for (k=1;k<=m;k++)
    f[i][k]=(f[i][k]+1uLL*f[i-j][k-1]*d[j]%p*c[i-2][j-1])%p;
  for (k=0;k<m;k++)
   d[i]=(d[i]+f[i][k])%p;
 }
 for (i=1;i<=n;i++)
  for (j=0;j<=m;j++)
   for (k=0;j+k<=m;k++)
    if (k!=1)
     s=(s+1uLL*f[i][j]*f[n-i+1][k])%p;
 printf("%u",2uLL*n*(n-1)*s%p);
 return 0;
}
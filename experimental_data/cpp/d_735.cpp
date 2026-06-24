#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int main()
{
 scanf("%d",&n);
 bool h=false;
 int q=sqrt(n)+1;
 for (int i=2;i<=q;i++)if (i<n&&n%i==0)h=true;
 bool h2=false;
 q=sqrt(n-2)+1;
 for (int i=2;i<=q;i++)if (i<n-2&&(n-2)%i==0)h2=true;
if (h==false)printf("1\n");
 else if(h2==false)printf("2\n");
 else if (n>2&&n%2==0)printf("2\n");
  else if (n>5&&n%2==1)printf("3\n");
}
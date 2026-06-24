#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 500005;
int gi()
{
 int x=0,w=1;char ch=getchar();
 while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
 if (ch=='-') w=0,ch=getchar();
 while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
 return w?x:-x;
}
int n,a[N],top,p;
long long sum;
int main()
{
 n=gi();
 while (n--)
 {
  int opt=gi();
  if (opt==1)
  {
   int x=gi();
   a[++top]=x;
   sum+=a[top]-a[top-1];
   while (p<top&&a[p+1]<(double)sum/(p+1)) ++p,sum+=a[p];
  }
  else printf("%.10lf\n",(double)a[top]-(double)sum/(p+1));
 }
 return 0;
}
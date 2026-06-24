#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a,b,z,c,r,n,m;
int main () {
scanf ("%d %d %d",&n,&m,&z);
a=n;
b=m;
if (b>a) swap(a,b);
while (b>0) {
			r=a%b;
			a=b;
			b=r;			
}
c=n*m/a;
printf ("%d",z/c);
return 0;
}
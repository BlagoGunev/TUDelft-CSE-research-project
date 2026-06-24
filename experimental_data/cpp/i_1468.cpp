#include<cstdio>

#include<algorithm>

int n,x1,y1,x2,y2;

int main()

{

	scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);

	long long d=1ll*x1*y2-1ll*x2*y1,l=std::__gcd(x1,x2);

	if (d<0) d=-d;if (l<0) l=-l;

	if (n!=d) return puts("NO"),0;

	puts("YES");

	for (int i=1;i<=l;i++) for (int j=1;j<=d/l;j++) printf("%d %d\n",i,j);

	return 0;

}
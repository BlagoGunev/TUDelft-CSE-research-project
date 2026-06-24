#include <cstdio>
#include <algorithm>
#include <cmath>
#define Rint register int
#define LL long long
#define F(x,y,z) for(Rint x=y;x<=z;++x)
using namespace std;
inline LL R(){
    char c='!';LL x=0,z=1;
    for( ; c>'9'||c<'0';c=getchar()) if(c=='-')z=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    return x*z;
}
int n,m,ans;
int a[1000000];

int ck(int x)
{
	int ans=0;
	F(i,1,n) ans+=a[i]<=x;
	return ans;
}

int main()
{
	n=R();m=R();
	F(i,1,n) a[i]=R();
	int l=1,r=1000000000,mid;
	while (l<=r){
		mid=(l+r)/2;
		int p=ck(mid);
		if (p==m){printf("%d\n",mid);return 0;}
		if (p>m) r=mid-1;
		else l=mid+1;
	}
	printf("-1");
	return 0;
}
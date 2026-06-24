#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#define rr register
using namespace std;
double ans; int n,a[100011],b[100011];
inline signed iut(){
	rr int ans=0; rr char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) ans=(ans<<3)+(ans<<1)+(c^48),c=getchar();
	return ans;
}
signed main(){
	for (rr int T=iut();T;--T){
		n=iut(),a[0]=b[0]=ans=0;
		for (rr int i=1;i<=n*2;++i){
		    rr int x=iut(),y=iut();
		    if (!x) a[++a[0]]=y;
		        else b[++b[0]]=x;
		}
		sort(a+1,a+1+n),sort(b+1,b+1+n);
		for (rr int i=1;i<=n;++i)
		    ans+=sqrt((double)a[i]*a[i]+(double)b[i]*b[i]);
		printf("%.15lf\n",ans);
	}
	return 0;
}
#include<cstdio>
#include<cmath>
using namespace std;
const int N=4e4;
int n,m,k,a[N+1],b[N+1];
long long ans;
template<class T>inline void swap(T &x,T &y)
{
    x^=y^=x^=y;
    return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;++i) {
		scanf("%d",&b[i]);
	}
	for(int r=1,c,sqr=sqrt(k),sr,sc;r<=sqr;++r) {
		if(k%r) {
			continue;
		}
		c=k/r;
		if((r<=n)&&(c<=m)) {
			sr=sc=0;
			for(int i=1,len=0;i<=n;++i) {
				len=a[i]?len+1:0;
				sr=len>=r?sr+1:sr;
			}
			for(int i=1,len=0;i<=m;++i) {
				len=b[i]?len+1:0;
				sc=len>=c?sc+1:sc;
			}
			ans+=1ll*sr*sc;
		}
		if(r==c) {
			continue;
		}
		if((c<=n)&&(r<=m)) {
			sr=sc=0;
			for(int i=1,len=0;i<=n;++i) {
				len=a[i]?len+1:0;
				sc=len>=c?sc+1:sc;
			}
			for(int i=1,len=0;i<=m;++i) {
				len=b[i]?len+1:0;
				sr=len>=r?sr+1:sr;
			}
			ans+=1ll*sr*sc;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
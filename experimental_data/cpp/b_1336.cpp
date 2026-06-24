// Etavioxy
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define il inline
#define rep(i,s,t) for(register int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(register int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define pt(x) putchar(x)
using namespace std;
il int ci(){
	register char ch; int f=1;
	while(!isdigit(ch=getchar())) f=ch=='-'?-1:1;
	register int x=ch^'0';
	while(isdigit(ch=getchar())) x=(x*10)+(ch^'0');
	return f*x;
}

enum{N=200023};

int a[4][N];

int main(){
	int T = ci();
	while( T-- ){
		int n[4];
		rep(i,1,3) n[i] = ci();
		rep(i,1,3){
			rep(j,1,n[i]) a[i][j] = ci();
			a[i][n[i]+1] = -1e9;
			a[i][0] = -1e9;
			sort(a[i]+1,a[i]+n[i]+1);
		}
		ll ans = 8e18;
		rep(i,1,3){
			int p[4]={1,1,1,1};
			rep(j,1,n[i]){
				int x = a[i][j];
				int l=-1, r=-1;
				rep(i1,1,3) if( i1!=i ){
					int& t = p[i1];
					while( t<=n[i1] && a[i1][t]<=x ) t++;
					if( l==-1 ){
						l=a[i1][t-1];
						r=a[i1][t];
					}else{
						int l2=a[i1][t-1];
						int r2=a[i1][t];
						#define c2(x) (1ll*(x)*(x))
//						printf("%d %d %d %lld\n",x,l,r2,c2(x-l)+c2(x-r2)+c2(r2-l));
//						printf("%d %d %d %lld\n",x,r,l2,c2(x-r)+c2(x-l2)+c2(l2-r));
						ans = min(ans,c2(x-l)+c2(x-r2)+c2(r2-l));
						ans = min(ans,c2(x-r)+c2(x-l2)+c2(l2-r));
						ans = min(ans,c2(x-l)+c2(x-l2)+c2(l2-l));
						ans = min(ans,c2(x-r)+c2(x-r2)+c2(r2-r));
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
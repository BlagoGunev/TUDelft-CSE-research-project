// Etavioxy
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
#define il inline
#define ll long long
#define re register
#define rep(i,s,t) for(re int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(re int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define pt(x) putchar(x)
#define pti(x) printf("%d",x)
#define ptll(x) printf("%I64d",x)
#define file(s) freopen(s".in" ,"r",stdin),freopen(s".out","w",stdout)
using namespace std;
il int ci(){
	re char ch;int f=1;
	while(!isdigit(ch=getchar()))f=ch=='-'?-1:1;
	re int x=ch^'0';
	while(isdigit(ch=getchar()))x=(x*10)+(ch^'0');
	return f*x;
}
enum{N=400023};
int a[N],p[N];
int sum[N];
int main(){
	int T=ci();
	while( T-- ){
		int n=ci();
		rep(i,1,n) a[i]=ci();
		int tot=0, cnt=1;
		rep(i,2,n){
			if( a[i-1]!=a[i] ){
				p[++tot]= cnt;
				cnt=0;
			}
			cnt++;
		}
		p[++tot]=cnt;
		rep(i,1,tot) sum[i]=p[i]+sum[i-1];
		int s=0, b=0;
		rep(i,1+1,tot) if( sum[i]-sum[1]>sum[1] ){ s=i; break; }
		rep(i,s+1,tot) if( sum[i]-sum[s]>sum[1] ){ b=i; break; }
//		printf("%d %d %d\n",1,s,b);
		if( b==0 || sum[b]>n/2 ) printf("0 0 0\n");
		else{
			while( b<tot && sum[b+1]<=n/2 ) b++;
			printf("%d %d %d\n",sum[1],sum[s]-sum[1],sum[b]-sum[s]);
		}
	}
	return 0;
}
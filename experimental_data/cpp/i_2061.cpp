#include<cstdio>
#include<algorithm>
#define TY ll
#define MAXN 300002
#define FOR(i,a,b) for(TY i=(a);i<=(b);i=-~i)
#define fOR(i,a,b) for(TY i=(a);i<(b);i=-~i)
#define ROF(i,a,b) for(TY i=(a);i>=(b);i=~-i)
#define rOF(i,a,b) for(TY i=(a);i>(b);i=~-i)
#define EDG(i,u) for(TY i=hed[u];i;i=nxt[i])
using namespace std;
typedef long long ll;
const TY M=998244353,B=2325,INF=1e15;
typedef unsigned long long ull;
TY _abs(TY a){return a<0?-a:a;}
TY maxn(TY a,TY b){return a>b?a:b;}
TY minn(TY a,TY b){return a<b?a:b;}
inline void updmx(TY &x,TY y){if(x<y)x=y;}
inline void updmn(TY &x,TY y){if(x>y)x=y;}
inline void add(TY &x,TY y){if((x+=y)>=M)x-=M;}
TY gcd(TY a,TY b){return b?gcd(b,a%b):a;}
TY qp(TY a,TY b){TY ans=1;do{if(1&b)ans=ans*a%M;a=a*a%M;}while(b>>=1);return ans;}
char getc(){char ch=getchar();while(ch==' '||ch=='\n'||ch=='\r')ch=getchar();return ch;}
TY qr(){
	char ch=getchar();TY s=0,x=1;
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')x=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';return x*s;
}void qw(TY a){if(a>9)qw(a/10);putchar(a%10+'0');}
void qw(TY a,char ch){
	if(a<0){a=-a;putchar('-');}
	if(a>9)qw(a/10);putchar(a%10+'0');if(ch)putchar(ch);
}TY T=qr(),n,R,a[MAXN],dp[MAXN],nw[MAXN],ct,vl,ar[MAXN],l,r;
void findans(TY l,TY r,TY p,TY q){
	TY mid=l+r>>1,ps;
	FOR(i,p,q){
		if(i>mid)break;
		if(nw[mid]>dp[i]+ar[mid-i])
			{nw[mid]=dp[i]+ar[mid-i];ps=i;}
	}if(l<mid)findans(l,mid-1,p,ps);
	if(r>mid)findans(mid+1,r,ps,q);
}int main(){
	while(T--){
		n=qr();FOR(i,1,n){a[i]=qr();dp[i]=INF;}
		for(TY x=1;x<=n;x+=B){
			l=maxn(0,x-B>>1);r=minn(x-1,x+B-1>>1);
			R=minn(n,x+B-1);ct=vl=0;
			FOR(i,x,R)if(a[i]!=-1)ar[++ct]=a[i];else ++vl;
			FOR(i,ar[0]=0,n)nw[i]=INF;sort(ar+1,ar+ct+1);
			FOR(i,2,ct)ar[i]+=ar[i-1];FOR(i,ct+1,n)ar[i]=INF;
			findans(0,l+ct-1,0,l-1);
			ROF(i,ct,0)ar[i+vl]=ar[i];fOR(i,0,vl)ar[i]=0;
			findans(r+1,R,r+1,R);
			FOR(i,l,r)ar[i]=dp[i];
			FOR(i,x,R){
				ar[++r]=INF;
				if(a[i]==-1)rOF(j,r,i>>1)ar[j]=ar[j-1];
				else rOF(j,r,l)updmn(ar[j],ar[j-1]+a[i]);
			}FOR(i,0,n)dp[i]=nw[i];
			FOR(i,l,r)updmn(dp[i],ar[i]);
		}FOR(i,0,n)qw(dp[i],' ');putchar('\n');
	}return 0;
}
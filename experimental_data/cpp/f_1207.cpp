// SeptEtavioxy
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
#define re register
#define ll long long
#define il inline
#define rep(i,s,t) for(re int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(re int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define pt(ch) putchar(ch)
#define pti(x) printf("%d",x)
#define ptll(x) printf("%I64d",x)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
// c_ints
il int ci(){
	re char ch;int f=1;
	while(!isdigit(ch=getchar()))f= ch=='-'?-1:1 ;
	re int x= ch^'0';
	while(isdigit(ch=getchar()))x=(x*10)+(ch^'0');
	return f*x;
}
il char cc(){
	re char ch;
	while(!isgraph(ch=getchar()));
	return ch;
}
enum{N=500024,SQR=310};
int n,block;
int pool[SQR+1][SQR+1];
int a[N];
int main(){
	n= 500000;
	block= sqrt(n)+1;
	int q= ci();
	while( q-- ){
		if( cc()=='2' ){
			ll ans= 0;
			int x= ci(), y= ci();
			if( x<=SQR ){
				ans= pool[x][y];
			}
			else{
				for(re int f=y;f<=n;f+=x) ans+= a[f];
			}
			ptll(ans),pt('\n');
		}
		else{
			int x= ci(), y= ci();
			rep(i,1,SQR){
				pool[i][x%i] += y;
			}
			a[x]+= y;
		}
	}
	return 0;
}
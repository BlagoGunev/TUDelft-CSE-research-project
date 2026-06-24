#include<cstdio>
#define rint register int
#define ll long long
using namespace std;
const int mx=100005;
int t,n,id;
ll a,b,mt;
ll at[mx],bt[mx];
bool flag;
inline int read()
{
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	return x;
}
int main()
{
	t=read();
	for(rint op=1;op<=t;++op){
		a=read();b=read();n=read();mt=0;flag=true;
		for(rint i=1;i<=n;++i){
			at[i]=read();
			if(at[i]>mt){
				mt=at[i];id=i;
			}
		} 
		for(rint i=1;i<=n;++i) bt[i]=read();
		for(rint i=1;i<=n;++i){
			mt=bt[i]/a;
			if(a*mt<bt[i]) ++mt;
			b-=mt*at[i];
			if(b+at[id]<=0){
				flag=false;break;
			}
		}
		if(flag){
			b+=at[id];
			if(b>0) printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}
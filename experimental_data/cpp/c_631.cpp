#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<queue>
#include<stack>
#include<functional>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define inf 1000000007

long long read(){
	   char c;
	   long long x=0,f=1;
	   c=getchar();
	   while ( c <  '0' || c > '9' ) { if ( c == '-') f=-1; c=getchar(); }
	   while ( c >= '0' && c <= '9' ) {  x=x*10+c-'0'; c=getchar(); }
	   return x*f;
}
int a[200007];
bool row[5007],col[5007];
int t[200007],ans[200007],r[200007],b[200007],suf[200007];
int main(){
	int n,m,k;
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) t[i]=read(),r[i]=read();
	for(int i=m;i>=1;i--) if (r[i]>r[suf[i+1]]) suf[i]=i; else suf[i]=suf[i+1];
	int head=1,last=r[suf[1]],now=suf[1];
	for(int i=1;i<=r[suf[1]];i++) b[i]=a[i];
	sort(b+1,b+last+1);
	for(int i=last+1;i<=n;i++) ans[i]=a[i];
	int top=last+1;
	while(head<=last){
		int cnt,v=suf[now+1];
		if (t[now]==1) {
			cnt=r[now]-r[v];
			while(cnt>0){
				cnt--;
				ans[--top]=b[last];
				last--;
			}
		}
		else {
			cnt=r[now]-r[v];
			while(cnt>0){
				cnt--;
				ans[--top]=b[head];
				head++;
			}
		}
		now=v;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
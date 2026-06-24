#include<bits/stdc++.h>
	#define rep(i,a,b)	for(int i=a;i<=b;i++)
	#define rev(i,a,b)	for(int i=a;i>=b;i--)
	#define reg(i,g,u)	for(int i=h[u];i;i=g[i].nxt)
	#define LL long long
	#define INF (2147483647)
	#define sqr(x)  ((x)*(x))
	#define mod (1000000007)
	using namespace std;
	inline void read(int &data){
	    data=0; 
		int w=1; char ch=0;
	    while (ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	    if (ch=='-') w=-1,ch=getchar();
	    while  (ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
	    data=data*w;
	}
	inline void read(LL &data){
	    data=0;
		int w=1; char ch=0;
	    while (ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	    if (ch=='-') w=-1,ch=getchar();
	    while  (ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
	    data=data*w;
	}
	inline void write(int x){
	    if(x<0) putchar('-'),x=-x;
	    if(x>9) write(x/10);
	    putchar(x%10+'0');
	} 
	inline void write(LL x){
	    if(x<0) putchar('-'),x=-x;
	    if(x>9) write(x/10);
	    putchar(x%10+'0');
	}
	int n;int a[200005];
	int main(){
		read(n);
		int ans=0;
		for(int i=2;i<=n;i+=2)	a[++ans]=i;
		for(int i=1;i<=n;i+=2)	a[++ans]=i;
		for(int i=2;i<=n;i+=2)	a[++ans]=i;
		write(ans),puts("");
		rep(i,1,ans)	write(a[i]),putchar(' ');
	}
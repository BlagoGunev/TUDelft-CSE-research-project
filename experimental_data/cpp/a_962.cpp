#include<cstdio>
#define maxn 200005
using namespace std;
int n,sum,a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	sum=(sum+1)>>1;
	int t=0;
	for (int i=1;i<=n;i++){
		t+=a[i];
		if (t>=sum){printf("%d\n",i);return 0;}
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Rep(i,a,b) for (int i=b;i>=a;i--)
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){ if (ch=='-') f=-1;ch=getchar(); }
	while (ch>='0'&&ch<='9'){ x=x*10+ch-'0';ch=getchar(); }
	return x*f;
}
int main(){
//	freopen("D.in","r",stdin);
	
	printf("YES\n");
	int n=read();
	For(i,1,n){
		int x1=read(),y1=read();
		x1=abs(x1),y1=abs(y1);
		if (x1%2==0&&y1%2==0) printf("1\n");
		if (x1%2==0&&y1%2==1) printf("2\n");
		if (x1%2==1&&y1%2==0) printf("3\n");
		if (x1%2==1&&y1%2==1) printf("4\n");
		x1=read(),y1=read();
	}
	
}
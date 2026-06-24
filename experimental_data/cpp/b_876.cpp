#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define d1(i,x) for(int i=x;i;--i)
#define f0(i,x) for(int i=0;i<=x;++i)
#define f1(i,x) for(int i=1;i<=x;++i)
#define f2(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=100005;
int n,k,m,a[N],b[N];
int main(){
	n=read();k=read();m=read();
	f1(i,n){
		a[i]=read();
		++b[a[i]%m];
	}
	int mx=0;
	f1(i,m-1)if(b[i]>b[mx])mx=i;
	if(b[mx]<k)puts("No");
	else{
		puts("Yes");
		int num=0;
		for(int i=1;i<=n&&num<k;++i)if(a[i]%m==mx){
			printf("%d ",a[i]);
			++num;
		}
	}
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=0; char c=getchar();
	while(c<'0'||c>'9') f|=c=='-',c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return f?-x:x;
} 
const int maxn=3e5+10;
int n,a[maxn];
int check(int i){
	if(i==1||i==n) return 0;
	if(a[i]>a[i-1]&&a[i]>a[i+1]||a[i]<a[i-1]&&a[i]<a[i+1]) return 1;
	return 0;
}
int main(){
	int t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int sum=0;
		for(int i=2;i<n;i++) if(check(i)) sum++;
		int _max=0;
		for(int i=2;i<n;i++){
			int x=check(i-1)+check(i+1)+check(i),y;
			int d=a[i];
			a[i]=a[i-1];
			y=check(i-1)+check(i+1)+check(i);
			_max=max(_max,x-y);
			a[i]=a[i+1];
			y=check(i-1)+check(i+1)+check(i);
			_max=max(_max,x-y);
			a[i]=d;
		}
		printf("%d\n",sum-_max);
	}
	return 0;
}
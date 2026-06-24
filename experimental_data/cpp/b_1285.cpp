#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define M 1000005
#define INF 1000000000000000000ll
using namespace std;
int t,n,a[M];
int read(){
	char c=getchar();int ans=0;bool flag=1;
	while (c<'0'||c>'9') flag&=(c!='-'),c=getchar();
	while (c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	return flag?ans:~ans+1;
}
int main(){
	t=read();
	while (t--){
		n=read();long long sum=0,ans=-INF,total=0;
		for (register int i=1;i<=n;i++) a[i]=read();
		for (register int i=1;i<n;i++) ans=max(ans,sum=max(sum,0ll)+a[i]),total+=a[i];sum=0;
		for (register int i=2;i<=n;i++) ans=max(ans,sum=max(sum,0ll)+a[i]);total+=a[n];
		printf("%s\n",total>ans?"YES":"NO");
	}
	return 0;
}
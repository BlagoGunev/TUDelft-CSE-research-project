#include<bits/stdc++.h>
#define N 500010
#define P 13331
#define double long double
#define int long long
#define mod 1000000007
using namespace std;
inline int read()
{
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void write(int x)
{
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
typedef pair<int,int> pb;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}
int qpow(int a,int b)
{
	int ret=1;a%=mod;
	for(int i=b;i>0;i>>=1){
		if(i&1) ret*=a,ret%=mod;
		a*=a,a%=mod;
	}
	return ret;
}
int qp(int a,int b)
{
	int ret=1;
	for(int i=b;i>0;i>>=1){
		if(i&1) ret*=a;
		a*=a;
	}
	return ret;
}
int lowbit(int x)
{
	return x&(-x);
}
int T,n;int a[N];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();a[n+1]=1e18;int ans=0;
		for(int i=n;i>=1;i--){
			if(a[i]>a[i+1]){
				int num=ceil(1.0*a[i]/a[i+1]);
				ans+=num-1;a[i]=a[i]/num;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
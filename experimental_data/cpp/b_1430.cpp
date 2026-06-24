#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ch() getchar()
#define pc(x) putchar(x)
template<typename T>inline void read(T&x){
	int f;char c;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c<='9'&&c>='0';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>inline void write(T x){
	static char q[64];int cnt=0;
	if(!x)pc('0');if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
const int maxn=200005;
int a[maxn];
int main(){
	int T;read(T);
	while(T--){
		int n,k;read(n),read(k);
		for(int i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1);
		if(k==0)write(a[n]-a[1]),pc('\n');
		else{
			long long ans=a[n];int no=n-1;
			while(k--&&no){
				ans+=a[no];--no;
			}
			write(ans),pc('\n');
		}
	}
	return 0;
}
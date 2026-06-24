#include<cstdio>
#include<cctype>
#include<cstring>

#define maxn 202202

inline int read(){
	int r=0,f=0;
	char c;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?-r:r;
}

inline long long max(long long a,long long b){
	return a>b?a:b;
}

int n,a[maxn],s[maxn];

long long ans;

inline void work(){
	ans=0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i+=2)ans+=a[i];
	long long Max=0;
	for(int opt=0;opt<2;opt++){
		for(int i=1;i<=(n-opt)/2;i++)
			s[i]=a[(i<<1)]-a[(i<<1)+(opt?1:-1)];
		long long sum=0;
		for(int i=1;i<=(n-opt)/2;i++){
			sum+=s[i];
			if(sum<0)sum=0;
			Max=max(Max,sum);
		}
	}
	ans+=Max;
	printf("%lld\n",ans);
}

int main(){
	int t=read();
	while(t--)work();
	return 0;
}
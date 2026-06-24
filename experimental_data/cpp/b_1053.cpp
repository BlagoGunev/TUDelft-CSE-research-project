#include<bits/stdc++.h>
#define max(a,b) (((a)>(b))?a:b)
#define min(a,b) (((a)<(b))?a:b)
using namespace std;
template<typename T>void read(T &x){
	x=0;int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	x*=f;
}
long long ans;
int a[300010],n;
int main(){
	read(n);
	for(int i=1;i<=n;++i){
		long long x;
		read(x);
		while(x){ 
			if(x&1) ++a[i];
			x>>=1;
		}
	}
	int ji=0,ou=0;
	for(int i=1;i<=n;++i){
		if(a[i]&1) ans+=ji,swap(ji,ou),++ji;
			else ans+=ou,++ou;
	}
	for(int i=1;i<=n;++i){
		for(int l=i,ls=0;l>=1&&ls<a[i];--l,ls+=a[l])
			for(int r=i,s=ls;r<=n&&s<a[i];++r,s+=a[r]) 
				if((!((s+a[i])&1))&&l!=r) --ans;
	}
	cout<<ans<<endl;
	return 0;
}
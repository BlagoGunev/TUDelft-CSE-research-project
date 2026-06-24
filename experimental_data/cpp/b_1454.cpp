#include<bits/stdc++.h>
using namespace std;
namespace IO{
	#define iL (1<<20)
	char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL;
	#define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
	template<class T>inline void read(T &x){
		register char c;register bool f;
		for(f=false,c=gc();!isdigit(c);f|=c=='-',c=gc());
		for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());
		if(f)x=~x+1;
		return ;
	}
	char Out[iL],*iter=Out;
	#define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
	template<class T>inline void write(register T x){
		register T c[35],l;
		if(x<0)*iter++='-',x=~x+1;
		for(l=0;!l || x;c[l]=x%10,++l,x/=10);
		for(;l;--l,*iter++=c[l]+'0');
		flush();
		return ;
	}
	template<class T>inline void write(register T x,register char LC){
		write(x),putchar(LC);
		return ;
	}
}
using namespace IO;
int T,n,a[200005],ton[200005];
int main(){
	read(T);
	while(T--){
		read(n);
		int minn=INT_MAX,ans=0;
		for(register int i=1;i<=n;++i){
			read(a[i]);
		}
		for(register int i=1;i<=n;++i){
			ton[i]=0;
		}
		for(register int i=1;i<=n;++i){
			++ton[a[i]];
		}
		for(register int i=1;i<=n;++i){
			if(!(ton[a[i]]^1)){
				if(a[i]<minn){
					minn=a[i],ans=i;
				}
			}
		}
		if(!ans){
			puts("-1");
		}
		else{
			write(ans,'\n');
		}
	}
	return 0;
}
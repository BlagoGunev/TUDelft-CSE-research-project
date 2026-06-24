#include<bits/stdc++.h>
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=2e5+5;
int a[N],c[N];
inline int  read(){//inline read()
	int f=1,res=0;
	char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();//res+=res*10+c-'0' 
	return f*res;
}
/*int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1){
		if(b&1)res=(ll)res*a%P;
		a=(ll)a*a%P;
	}
	return res;
}*/
int main(){
	int T;
	ios::sync_with_stdio(false);cin.tie(0);
	T=read();
	while(T--){
		int n=read();
		int u=n,s=0,num=0;
		for(int i=1;i<=n;i++)c[i]=0;
	    for(int i=1;i<=n;i++){
	    	a[i]=read();
	    	c[a[i]]++;
	    	if(c[a[i]]==1)num++;
			//if(c[a[i]]>=2)u--,s++;
		}
	//	printf("%d\n",min(u,s));
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,max(min(c[i],num-1),min(c[i]-1,num)));
	printf("%d\n",ans);
	}
	return 0;
}
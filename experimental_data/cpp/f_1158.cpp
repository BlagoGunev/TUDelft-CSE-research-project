#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=3030,mod=998244353;
int n,c,a[N],mi[N],iv[N],b[N];
int f[N][N],g[N][N],s[N][N];
int ksm(int p,int k){
	int x=1;
	while(k){
		if(k&1)x=1ll*x*p%mod;
		p=1ll*p*p%mod;
		k>>=1;
	} 
	return x;
}
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod; 
}
int main(){
//	freopen("a.in","r",stdin);
	n=read(),c=read();
	if(c==1){
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			f[i][0]=1;
			for(int j=1;j<=i;j++){
				f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
			}
		}
		cout<<"0 ";
		for(int i=1;i<=n;i++){
			cout<<f[n][i]<<" ";
		}
		return 0;
	}
	mi[0]=iv[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		mi[i]=2*mi[i-1]%mod;
		iv[i]=ksm(mi[i]-1,mod-2);
	}
	if(c<=8){
		f[0][0]=1;int m=0,x=(1<<c)-1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				for(int s=0;s<x;s++){
					add(g[j][s],f[j][s]);
					add(g[j][s|(1<<(a[i]-1))],f[j][s]);
				}
			}
			for(int j=0;j<=m;j++){
				for(int s=0;s<=x;s++){
					f[j][s]=g[j][s];g[j][s]=0;
				}
			}
			for(int j=m;j>=0;j--){
				if(f[j][x]){
					m=max(m,j+1);
					add(f[j+1][0],f[j][x]);
					f[j][x]=0;
				}
			}
		}
		for(int i=0;i<=n;i++){
			int res=0;
			for(int j=0;j<x;j++){
				add(res,f[i][j]);
			}
			if(!i)add(res,mod-1);
			cout<<res<<" ";
		}
		return 0;
	}
	int ct=0,vl=1;
	for(int i=n;i;i--){
		f[i][0]=mi[n-i];
		int &x=b[a[i]];
		if(!x)ct++;
		vl=1ll*vl*iv[x]%mod;
		x++;
		vl=1ll*vl*(mi[x]-1)%mod;
		if(ct==c){
			int y=1ll*vl*iv[x]%mod*mi[x-1]%mod;
			add(f[i][0],mod-y);
		}
	}
	for(int i=n;i;i--){
		memset(b,0,sizeof(b));
		int ct=1,vl=1;
		for(int j=i;j>=1;j--){
			if(a[j]==a[i])continue;
			int &x=b[a[j]];
			if(!x)ct++;
			vl=1ll*vl*iv[x]%mod;
			x++;
			vl=1ll*vl*(mi[x]-1)%mod;
			if(ct==c){
				g[i][j]=1ll*vl*iv[x]%mod*mi[x-1]%mod;
			}
		}
	}
	f[n+1][0]=1;
	for(int i=n+1;i;i--){
		for(int j=0;j<=n/c;j++){
			add(s[i][j],s[i+1][j]);
			add(s[i][j],f[i][j]);
			if(!s[i][j])continue;
			for(int k=i-1;k;k--){
				add(f[k][j+1],1ll*s[i][j]*g[i-1][k]%mod);
			}
		}
	}
	add(s[1][0],mod-1);
	for(int i=0;i<=n;i++){
		cout<<s[1][i]<<" ";
	}
	return 0;
}
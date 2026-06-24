#include<cstdio>
#define For(i,A,B) for(i=A;i<=(B);++i)
int f[250050];
int main(){
	int n,mod,i,ans=0;
	scanf("%d%d",&n,&mod);
	f[0]=f[1]=1;
	For(i,2,n)f[i]=1ll*f[i-1]*i%mod;
	For(i,1,n)ans=(ans+1ll*(n-i+1)*(n-i+1)%mod*f[i]%mod*f[n-i])%mod;
	printf("%d",ans);
	return 0;
}
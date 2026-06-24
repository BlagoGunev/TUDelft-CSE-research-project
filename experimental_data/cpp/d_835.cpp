#include<cstdio>
#include<cstring>
const int N=5010;
int f[N][N]; bool b[N][N];
char s[N]; int ans[N];
int main(){
	scanf("%s",s+1); int n=strlen(s+1);
	for(int i=1;i<=n;++i) f[i][i]=1,b[i][i]=b[i][i-1]=1;;
	for(int i=n;i>=1;--i)
		for(int j=i+1;j<=n;++j)
			if(s[i]==s[j]&&b[i+1][j-1]){
				b[i][j]=1;
				int len=(j-i+1)/2;
				f[i][j]=f[i][i+len-1]+1;
			}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j) if(b[i][j]) ++ans[f[i][j]];
	for(int i=n;i>=1;--i) ans[i]+=ans[i+1];
	for(int i=1;i<=n;++i) printf("%d ",ans[i]); return 0;
}
//skl
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2005;
int n,m,top;
int dp[N][N];
char ch[N][N],ans[N+N];
bool vis[N][N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
    n=read(),m=read();
	for(int i=0;i<n;i++)
		scanf("%s",ch[i]);
	if(m>=2*n-1){
	    for(int i=1;i<=2*n-1;i++)
	        putchar('a');
	       puts("");
	       return 0;
	}
	dp[0][0]=(ch[0][0]!='a');
	for(int i=1;i<n;i++)
		dp[0][i]=dp[0][i-1]+(ch[0][i]!='a');
	for(int i=1;i<n;i++)
		dp[i][0]=dp[i-1][0]+(ch[i][0]!='a');
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			dp[i][j]=min(dp[i][j-1],dp[i-1][j])+(ch[i][j]!='a');
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dp[i][j]<=m)
				ch[i][j]='a';
	for(int i=0;i<2*n-1;i++){
		char mn='z';
		for(int x=max(0,i-n+1);x<n && x<i+1;x++){
			int y=i-x;
			if((x==0 && y==0) || (x>0 && vis[x-1][y]) || (y>0 && vis[x][y-1]))
			    mn=min(mn,ch[x][y]);
		}
		for(int x=max(0,i-n+1);x<n && x<i+1;x++){
			int y=i-x;
			if(ch[x][y]!=mn)continue;
			if((x==0 && y==0) || (x>0 && vis[x-1][y]) || (y>0 && vis[x][y-1]))
			    vis[x][y]=1;
		}
		ans[++top]=mn;
	}
	for(int i=1;i<=2*n-1;i++)
	    putchar(ans[i]);
	puts("");
	return 0;
}
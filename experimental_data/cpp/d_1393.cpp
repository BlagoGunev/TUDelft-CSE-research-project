#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int n,m;
lol f[2005][2005];
char s[2005][2005];
int main(){
	scanf("%d%d",&n,&m);
	lol ans=0;
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=1;
			int x1=i-1,y1=j-1,x2=i-1,y2=j+1;
			if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&x2>=1&&x2<=n&&y2>=1&&y2<=m&&s[i][j]==s[x1][y1]&&s[i][j]==s[x2][y2]&&s[i][j]==s[i-1][j]){
				int k=min(f[x1][y1],f[x2][y2]);
				int x3=i-(2*k-1),x4=i-(2*k);
				if(x3>=1&&x4>=1&&s[x3][j]==s[i][j]&&s[x4][j]==s[i][j])
					f[i][j]=k+1;
				else{
					f[i][j]=k;
				}
			}
			ans+=f[i][j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
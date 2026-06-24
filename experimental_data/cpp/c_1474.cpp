#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2005
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int read01(){
	char c=getchar();
	while(c!='0'&&c!='1')c=getchar();
	return c-'0';
}
int T,n,a[N],ans1[N],ans2[N],vis[1000005];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n*2;i++)
			a[i]=read();
		sort(a+1,a+n*2+1);
		bool flag=0;
		int ans=0;
		for(int i=1;i<n*2;i++){
			for(int j=1;j<=n*2;j++)
				vis[a[j]]=0;
			for(int j=1;j<=n*2;j++)
				vis[a[j]]++;
			ans1[1]=a[i],ans2[1]=a[n*2];
			vis[a[i]]--,vis[a[n*2]]--;
			int cnt=1,now=a[n*2];
			bool fl=0;
			for(int j=n*2-1;j>0;j--){
				if(!vis[a[j]])continue;
				vis[a[j]]--;
				if(vis[now-a[j]])vis[now-a[j]]--,ans1[++cnt]=a[j],ans2[cnt]=now-a[j],now=a[j];
				else{
					fl=1;
					break;
				}
			}
			if(!fl&&cnt==n){
				ans=a[i]+a[n*2];
				flag=1;
				break;
			}
		}
		if(!flag)puts("NO");
		else{
			puts("YES");
			printf("%lld\n",ans);
			for(int i=1;i<=n;i++)
				printf("%lld %lld\n",ans1[i],ans2[i]);
		}
		for(int i=1;i<=n*2;i++)
			vis[a[i]]=0;
	}
	return 0;
}
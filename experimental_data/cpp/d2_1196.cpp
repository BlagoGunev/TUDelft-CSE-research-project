#include<bits/stdc++.h>

using namespace std;
inline int read() {
	int res=0,fh=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')fh=-1,ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return fh*res;
}
const int maxn=200010;
char str[3]= {'R','G','B'};
char s[maxn];
int sum[maxn];int n,k;
inline int solve() {
	int res=n;
	for(int i=1; i<=n; i++) {
		sum[i]+=sum[i-1];
		if(i>=k) res=min(res,sum[i]-sum[i-k]);
	}
	return res;
}
inline int Min(int a,int b){
	return a<b?a:b;
}
int main() {
	int T=read();
	while(T--) {
		n=read(),k=read();
		scanf("%s",s+1);
		int cur=0,ans=k;
		for(int i=1; i<=n; i++,cur=(cur+1)%3)
			if(str[cur]!=s[i]) sum[i]=1;
			else sum[i]=0;
		ans=Min(ans,solve());
		cur=1;
		for(int i=1; i<=n; i++,cur=(cur+1)%3)
			if(str[cur]!=s[i]) sum[i]=1;
			else sum[i]=0;
		ans=Min(ans,solve());
		cur=2;
		for(int i=1; i<=n; i++,cur=(cur+1)%3)
			if(str[cur]!=s[i]) sum[i]=1;
			else sum[i]=0;
		ans=Min(ans,solve());
		printf("%d\n",ans);
	}
	return 0;
}
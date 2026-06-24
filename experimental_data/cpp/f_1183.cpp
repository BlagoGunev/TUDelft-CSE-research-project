#include<bits/stdc++.h>
using namespace std;
int q,n,m,a[200005],b[200005],c[200005];
inline int read()
{
	int x=0; char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
void solve()
{
	int ans=a[n];
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>0;j--){
			if(a[i]%a[j]!=0){
				b[i]=j; break;
			}
		}
		ans=max(ans,a[i]+a[b[i]]);
	}
//	for(int i=1;i<=n;i++) cout<<b[i]<<' '; cout<<endl;
	for(int i=n;i>=3;i--){
		int x=a[i],y=a[b[i]],z=x+y;
//		if(x+y+a[b[b[i]]]<=ans) break;
//		cout<<x<<' '<<y<<endl;
		for(int j=b[b[i]];j>0;j=b[j]){
			if(a[j]+z<=ans) break;
			if(x%a[j]!=0&&y%a[j]!=0){
				ans=max(ans,a[j]+z);
				break;
			}
		}
	}
	printf("%d\n",ans);
}
void pre()
{
	for(int i=1;i<=m;i++){
		if(c[i]!=c[i-1]) a[++n]=c[i];
	}
}
int main()
{
	q=read();
	while(q--){
		m=read(); n=0;
		for(int i=1;i<=m;i++) c[i]=read(),b[i]=0;
		a[m+1]=b[m+1]=c[m+1]=0; a[0]=b[0]=c[0]=0;
		sort(c+1,c+m+1);
		pre();
		solve();
	}
}
#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
#define ll long long
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,cnt,Min[N],Max[N],tot,p;
ll ans;
int main(){
	n=read();
	inc(i,1,n){
		int l=read();
		int minn=1e9,maxx=0;
		bool pd=0;
		inc(j,1,l){
			int x=read();
			if(x>minn) pd=1;
			minn=min(x,minn);
			maxx=max(x,maxx);
		}
		if(pd) cnt++;
		else Min[++tot]=minn,Max[tot]=maxx;
	}
	ans+=2LL*n*cnt-(1LL*cnt*cnt);
	sort(Min+1,Min+1+tot),sort(Max+1,Max+1+tot);
	int p=0;
	inc(i,1,tot){
		while(Min[p+1]<Max[i]&&p<tot) p++; 
		ans+=p;
	}
	printf("%lld",ans);
}
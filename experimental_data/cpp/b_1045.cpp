#include<bits/stdc++.h>
#define R int
#define ll long long 
#define N 200001
#define bas 257
using namespace std;
int n,m,tot,w[N],G[N],sum[N];
int Q[N],H[N],cha[N],f[N],g[N];
int fin[N],len;
int gi(){
    R x=0,k=1;char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')k=-1,c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return x*k;
}
int main(){
	n=gi(),m=gi(),sum[0]=1;
	for(R i=1;i<=n;++i)w[i]=gi(),sum[i]=sum[i-1]*bas;
	sort(w+1,w+n+1);
	for(R i=1;i<n;++i)cha[i]=w[i+1]-w[i],Q[i]=Q[i-1]*bas+cha[i];
	for(R i=n-1;i>=1;--i)H[i]=H[i+1]*bas+cha[i];
	f[1]=f[2]=g[n]=g[n-1]=1;
	for(R i=2;i<n;++i){
		R mid=(i>>1);
		if(Q[mid]==H[i-mid+1]-H[i+1]*sum[mid]){
			f[i+1]=1;
		}
		if(H[n-1-mid+1]==Q[n-1-i+mid]-Q[n-1-i]*sum[mid])g[n-i]=1;
	}
	for(R i=1;i<=n;++i)
		if(f[i]&&g[i+1]){
			R le=w[1]+w[i],ri=(w[i+1]+w[n])%m;
			if(le==ri)fin[++len]=le;
		}
	if(f[n])fin[++len]=(w[1]+w[n])%m;
	printf("%d\n",len),sort(fin+1,fin+len+1);
	for(R i=1;i<=len;++i)printf("%d ",fin[i]);
    return 0;
}
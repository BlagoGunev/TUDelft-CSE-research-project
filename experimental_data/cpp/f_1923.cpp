// LUOGU_RID: 157403928
#include<bits/stdc++.h>
using namespace std;
const int N=500005,p=1000000007;
int n,k,ans,a[N],sa[N];
char s[N],t[2][N],_s[N];
namespace SA{
void suffix_sort(char*s){
	static int rk[N],bu[N],id[N],p;
	memset(rk,0,sizeof rk),memset(bu,0,sizeof bu);
	memset(sa,0,sizeof sa),memset(id,0,sizeof id),p=0;
	for(int i=1;i<=n;++i) ++s[i];
	for(int i=1;i<=n;++i) ++bu[s[i]];
	for(int i=1;i<=2;++i) bu[i]+=bu[i-1];
	for(int i=n;i;--i) sa[bu[s[i]]--]=i;
	for(int i=1;i<=n;++i) rk[sa[i]]=s[sa[i]]==s[sa[i-1]]?p:++p;
	for(int i=1;i<n&&p<n;i<<=1){
		memset(bu+1,0,p<<2);
		for(int j=n-i+1;j<=n;++j) id[j-n+i]=j;
		for(int j=1,k=i;j<=n;++j) if(sa[j]>i) id[++k]=sa[j]-i;
		for(int j=1;j<=n;++j) ++bu[rk[j]];
		for(int j=2;j<=p;++j) bu[j]+=bu[j-1];
		for(int j=n;j;--j) sa[bu[rk[id[j]]]--]=id[j],id[j]=rk[j];
		p=0;
		for(int j=1;j<=n;++j) rk[sa[j]]=id[sa[j]]==id[sa[j-1]]&&id[sa[j]+i]==id[sa[j-1]+i]?p:++p;
	}
}
}
void chk0(){
	memcpy(t[0],s,sizeof s);
	int r=n,l=1,c=k;
	while(c--){
		while(r&&t[0][r]) --r;
		while(l<=n&&!t[0][l]) ++l;
		if(l>=r) break;
		swap(t[0][l],t[0][r]);
	}
}
bool chk(int len,int c){
	if(len<a[n]) return 0;
	for(int i=1;i+len-1<=n;++i)
		if(a[n]-(a[i+len-1]-a[i-1])<=c)
			return 1;
	return 0;
}
void chk1(){
	int l=1,r=n,mid;
	while(l<r) chk(mid=(l+r)/2,k-1)?r=mid:l=mid+1;
	for(int _=1,x;_<=n;++_){
		x=n-sa[_]+1-l+1;
		if(x<1) continue;
		if(a[n]-(a[x+l-1]-a[x-1])<=k-1){
			for(int i=0,cnt=a[n]-(a[x+l-1]-a[x-1]);i<l;++i)
				if(!(t[1][n-i]=s[x+i])&&cnt)
					--cnt,t[1][n-i]=1;
			break;
		}
	}
}
bool cmp(char*s,char*t){
	for(int i=1;i<=n;++i)
		if(s[i]!=t[i])
			return s[i]>t[i];
	return 0;
}
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;++i) s[i]-='0',a[i]=a[i-1]+s[i];
	memcpy(_s,s,sizeof s);
	SA::suffix_sort(_s),chk0();
	memcpy(_s,s,sizeof s);
	reverse(_s+1,_s+n+1);
	SA::suffix_sort(_s),chk1();
	if(cmp(s,t[0])) swap(s,t[0]);
	if(cmp(s,t[1])) swap(s,t[1]);
	for(int i=n,z=1;i;--i,z=z*2%p) if(s[i]) ans=(ans+z)%p;
	return printf("%d",ans),0;
}